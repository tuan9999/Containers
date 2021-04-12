//
// Created by Tuan Perera on 18.02.21.
//

#ifndef CONTAINERS_MULTIMAP_TREE_H
#define CONTAINERS_MULTIMAP_TREE_H
#include "multimap_node.h"

namespace ft {
	template<typename Key, typename Mapped, typename T>
	class multimap_tree {
	public:
		typedef multimap_tree_node<Key, Mapped, T> 	*node_ptr;
		typedef multimap_tree<Key, Mapped, T>		self_type;
		typedef T									value_type;
		typedef T									*pointer;
		typedef T									&reference;
		typedef Key									key_type;
		typedef Mapped								mapped_type;

	private:
		node_ptr root;

	public:
		multimap_tree() : root(NULL) {}

		multimap_tree(const multimap_tree &src) : root(src.root) {}

		~multimap_tree() {
			delete_tree(this->root);
		}

		void delete_tree(node_ptr node) {
			if (node->right!=NULL)
				delete_tree(node->right);
			if (node->left!=NULL)
				delete_tree(node->left);
			delete node;
		}

		self_type &operator=(const self_type &rhs) {
			this->root = rhs.root;
			return *this;
		}

		node_ptr& get_root() {
			return this->root;
		}

		node_ptr min_val() {
			node_ptr node = this->root;
			if (node && node->null_node != true && node->left && node->left->null_node != true) {
				while (node->left && node->left->null_node != true)
					node = node->left;
			}
			return node;
		}

		node_ptr max_val() {
			node_ptr node = this->root;
			if (node) {
				while (node->right->null_node != true)
					node = node->right;
			}
			return node;
		}

		node_ptr find(key_type k) {
			node_ptr n = this->root;
			if (n == NULL)
				return NULL;
			else if (k == n->data.first)
				return n;
			else {
				while (n) {
					if (n->null_node == true)
						return NULL;
					else if (k > n->data.first)
						n = n->right;
					else if (k < n->data.first)
						n = n->left;
					else
						return n;
				}
			}
			return n;
		}

		node_ptr find_key_after(key_type k) {
			node_ptr n = this->root;
			node_ptr prev = NULL;
			if (n == NULL)
				return NULL;
			else if (k == n->data.first)
				return n;
			else {
				while (n) {
					prev = n;
					n = n->next();
					if (k > prev->data.first && k < n->data.first)
						return n;
				}
			}
			return NULL;
		}

		void print(node_ptr p,int start)
		{
			start++;
			if (p->right != NULL)
			{
				print(p->right , start);
			}
			for (int i = 0; i <= start; i++)
			{
				std::cout<<"    ";
			}
			std::cout << ((p->null_node == false) ? p->data.first : 0) << " " <<  ((p->null_node == false) ? p->data.second : "(null)") << std::endl;
			if (p->left != NULL)
			{
				print(p->left, start);
			}
		}

		node_ptr insert_data(value_type data) {
			node_ptr node = new multimap_tree_node<Key, Mapped, T>(data);
			if (this->root == NULL) {
				this->root = node;
			}
			else {
				node_ptr x = this->root;
				node_ptr y = NULL;
				while (x && x->null_node != true) {
					y = x;
					if (x->data.first == node->data.first) {
						if (x->right->null_node != true)
							node = minimum(x->right);
						break ;
					}
					if (x->data.first > node->data.first) {
						x = x->left;
					}
					else {
						x = x->right;
					}
				}
				x = node;
				node->parent = y;
				if (y->data.first > node->data.first) {
					if (y->left)
						delete y->left;
					y->left = node;
				}
				else {
					if (y->right)
						delete y->right;
					y->right = node;
				}
			}

			node->right = new multimap_tree_node<Key, Mapped, T>(data, true);
			node->left = new multimap_tree_node<Key, Mapped, T>(data, true);
			node->right->parent = node;
			node->left->parent = node;
			return (node);
		}

		node_ptr minimum(node_ptr x) {
			while (x->left->null_node != true) {
				x = x->left;
			}
			return x;
		}

		void delete_node(value_type data) {
			node_ptr z = NULL;
			node_ptr y, node = this->root;

			while (node != NULL){
				if (node->data.first == data.first) {
					z = node;
					break;
				}

				if (node->data.first <= data.first) {
					node = node->right;
				} else {
					node = node->left;
				}
			}

			if (z == NULL) {
				std::cout << "Couldn't find key in the tree" << std::endl;
				return;
			}
			if (z == this->root) {
				y = minimum(z->right);
				delete y->left;
				y->left = z->left;
				this->root = y;
			}
			else if (z->left->null_node == false or z->right->null_node == false) {
				if (z->left->null_node == false && z->right->null_node == false) {
					y = minimum(z->right);
					y = y->parent;
					y->parent = z->parent;
					y->right = z->right;
					y->left = z->left;
					if (z->right)
						z->right->parent = y;
					if (z->left)
						z->left->parent = y;
					if (z->parent->right == z)
						z->parent->right = y;
					else
						z->parent->left = y;
				}
				else if (z->left->null_node == false) {
					y = z->left;
					y->parent = z->parent;
					if (z == z->parent->right)
						z->parent->right = y;
					else
						z->parent->left = y;
				}
				else if (z->right->null_node == false) {
					y = z->right;
					y->parent = z->parent;
					if (z == z->parent->right)
						z->parent->right = y;
					else
						z->parent->left = y;
				}
			}
			else {
				if (z == z->parent->right)
					z->parent->right = NULL;
				else
					z->parent->left = NULL;
			}
			delete z;
		}

	};
}

#endif //CONTAINERS_MULTIMAP_TREE_H
