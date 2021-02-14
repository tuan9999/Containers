//
// Created by Tuan Perera on 29.01.21.
//

#ifndef CONTAINERS_RB_TREE_H
#define CONTAINERS_RB_TREE_H
#include <iostream>
#include "map_node.h"

namespace ft {
	template<typename Key, typename Mapped, typename T>
	class rb_tree {
	public:
		typedef rb_tree_node<T> 			*node_ptr;
		typedef rb_tree<Key, Mapped, T>		self_type;
		typedef T							value_type;
		typedef T							*pointer;
		typedef T							&reference;
		typedef Key							key_type;
		typedef Mapped						mapped_type;

	private:
		node_ptr root;

	public:
		rb_tree() : root(NULL) {}

		rb_tree(const rb_tree &src) : root(src.root) {}

		~rb_tree() {
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
			if (node) {
				while (node->left->null_node != true)
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

		node_ptr end() {
			node_ptr node = this->root;
			if (node) {
				while (node->right->null_node != true)
					node = node->right;
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

		void left_rotate(node_ptr x) {
			node_ptr y = x->right;
			x->right = y->left;
			if (y->left != NULL) {
				y->left->parent = x;
			}
			y->parent = x->parent;
			if (x->parent == NULL) {
				this->root = y;
			}
			else if (x == x->parent->left) {
				x->parent->left = y;
			}
			else {
				x->parent->right = y;
			}
			y->left = x;
			x->parent = y;
		}

		void right_rotate(node_ptr x) {
			node_ptr y = x->left;
			x->left = y->right;
			if (y->right != NULL) {
				y->right->parent = x;
			}
			y->parent = x->parent;
			if (x->parent == NULL) {
				y = this->root;
			}
			else if (x == x->parent->right) {
				x->parent->right = y;
			}
			else {
				x->parent->left = y;
			}
			y->right = x;
			x->parent = y;
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
			std::cout << ((p->null_node == false) ? p->data.first : 0)  << " " << ((p->color == 1) ? "B" : "R") << std::endl;
			if (p->left != NULL)
			{
				print(p->left, start);
			}
		}

		void check_rb_violation(node_ptr node) {
			if (node == this->root || node->parent->color == BLACK) {
				return ;
			}
			else {
				while (node->parent && node->parent->color == RED) {
					if (node->parent == node->parent->parent->right) {
						node_ptr u = node->parent->parent->left;
						if (u->color == RED) {
							u->color = BLACK;
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							node = node->parent->parent;
						}
						else if (node == node->parent->left) {
							node = node->parent;
							left_rotate(node);
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							right_rotate(node);
						}
					}
					else if (node->parent == node->parent->parent->left) {
						node_ptr u = node->parent->parent->right;
						if (u->color == RED) {
							u->color = BLACK;
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							node = node->parent->parent;
						}
						else if (node == node->parent->right) {
							node = node->parent;
							right_rotate(node);
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							left_rotate(node);
						}
					}
				}
				this->root->color = BLACK;
			}
		}

		node_ptr insert_data(value_type data) {
			node_ptr node = new rb_tree_node<T>(data, RED);
			if (this->root == NULL) {
				this->root = node;
				node->color = BLACK;
			}
			else {
				node_ptr x = this->root;
				node_ptr y = NULL;
				while (x && x->null_node != true) {
					y = x;
					if (x->data.first == node->data.first) {
						std::cout << "Cannot add duplicate key" << std::endl;
						delete node;
						return x;
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
			node->right = new rb_tree_node<T>(data, BLACK, true);
			node->left = new rb_tree_node<T>(data, BLACK, true);
			node->right->parent = node;
			node->left->parent = node;
			check_rb_violation(node);
			return (node);
		}

		void fix_rb_delete_violation(node_ptr x) {
			while (x != this->root && x->color == BLACK) {
				if (x == x->parent->left) {
					node_ptr s = x->parent->right;
					if (s->color == RED) {
						s->color = BLACK;
						x->parent->color = RED;
						left_rotate(x->parent);
						s = x->parent->right;
					}
					if ((s->left && s->left->color == BLACK) && (s->right && s->right->color == BLACK)) {
						s->color = RED;
						x = x->parent;
					}
					else {
						if (s->right && s->right->color == BLACK) {
							if (s->left) {
								s->left->color = BLACK;
							}
							s->color = RED; //case 3.3
							right_rotate(s);
							s = x->parent->right;
						}
						s->color = x->parent->right->color;
						x->parent->color = BLACK;
						if (s->right)
							s->right->color = BLACK;
						left_rotate(x->parent);
						x = this->root;
					}
				}
				else {
					node_ptr s = x->parent->left;
					if (s->color == RED) {
						s->color = BLACK;
						x->parent->color = RED;
						right_rotate(x->parent);
						s = x->parent->left;
					}
					if ((s->right && s->right->color == BLACK) && (s->left && s->left->color == BLACK)) {
						s->color = RED;
						x = x->parent;
					}
					else {
						if (s->left && s->left->color == BLACK) {
							if (s->right)
								s->right->color = BLACK;
							s->color = RED;
							left_rotate(s);
							s = x->parent->left;
						}
						s->color = x->parent->left->color;
						x->parent->color = BLACK;
						if (s->left)
							s->left->color = BLACK;
						right_rotate(x->parent);
						x = this->root;
					}
				}
			}
			x->color = BLACK;
		}

		node_ptr minimum(node_ptr x) {
			while (x->left->null_node != true) {
				x = x->left;
			}
			return x;
		}

		void rb_transplant(node_ptr u, node_ptr v){
			if (u->parent == NULL) {
				this->root = v;
			} else if (u == u->parent->left){
				u->parent->left = v;
			} else {
				u->parent->right = v;
			}
			v->parent = u->parent;
		}

		void delete_node(value_type data) {
			node_ptr z = NULL;
			node_ptr x, y, node = this->root, r_tmp = NULL, l_tmp = NULL;

			while (node != NULL){
				if (node->null_node == false && node->data.first == data.first) {
					z = node;
				}

				if (node->null_node == false && node->data.first <= data.first) {
					node = node->right;
				} else {
					node = node->left;
				}
			}

			if (z == NULL) {
				std::cout << "Couldn't find key in the tree" << std::endl;
				return;
			}
			if (z->right->right == NULL)
				r_tmp = z->right;
			if (z->left->left == NULL)
				l_tmp = z->left;

			y = z;
			int y_original_color = y->color;
			if (z->left->null_node == true) {
				x = z->right;
				delete z->left;
				rb_transplant(z, z->right);
			} else if (z->right->null_node == true) {
				x = z->left;
				delete z->right;
				rb_transplant(z, z->left);
			} else {
				y = minimum(z->right);
				y_original_color = y->color;
				x = y->right;
				if (y->parent == z) {
					x->parent = y;
				} else {
					rb_transplant(y, y->right);
					y->right = z->right;
					y->right->parent = y;
				}

				rb_transplant(z, y);
				delete y->left;
				y->left = z->left;
				y->left->parent = y;
				y->color = z->color;
			}
			delete z;
			if (y_original_color == BLACK){
				fix_rb_delete_violation(x);
			}
		}

	};
}

#endif //CONTAINERS_RB_TREE_H
