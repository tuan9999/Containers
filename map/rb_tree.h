//
// Created by Tuan Perera on 29.01.21.
//

#ifndef CONTAINERS_RB_TREE_H
#define CONTAINERS_RB_TREE_H
#include "map_node.h"

namespace ft {
	template<typename T>
	class rb_tree {
	public:
		typedef rb_tree_node<T> *node_ptr;
		typedef rb_tree<T>		self_type;
		typedef T				value_type;
		typedef T				*pointer;
		typedef T				&reference;

	private:
		node_ptr root;

	public:
		rb_tree() : root(NULL) {}

		rb_tree(const rb_tree &src) : root(src.root) {}

		self_type &operator=(const self_type &rhs) {
			this->root = rhs.root;
		}

		node_ptr get_root() {
			return this->root;
		}

		node_ptr min_val() {
			node_ptr node = this->root;
			if (node) {
				while (node->left)
					node = node->left;
			}
			return node;
		}

		node_ptr max_val() {
			node_ptr node = this->root;
			if (node) {
				while (node->right)
					node = node->right;
			}
			return node;
		}

		void left_rotate(node_ptr x) {
			node_ptr y = x->right;
			x->right = y->left;
			if (y->left != NULL)
				y->left->parent = x;
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
			std::cout << p->data.first << " " << ((p->color == 1) ? "B" : "R") << std::endl;
			if (p->left != NULL)
			{
				print(p->left, start);
			}
		}

		void check_rb_violation(node_ptr node) {
			if (node->parent->color == BLACK)
				return ;
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

		void insert_data(value_type data) {
			node_ptr node = new rb_tree_node<T>(data, 0);
			if (this->root == NULL) {
				this->root = node;
				node->color = 1;
				return ;
			}
			else {
				node_ptr x = this->root;
				node_ptr y = NULL;
				while (x) {
					y = x;
					if (x->data.first == node->data.first) {
						std::cout << "Cannot add duplicate key" << std::endl;
						return ;
					}
					if (x->data.first > node->data.first)
						x = x->left;
					else
						x = x->right;
				}
				x = node;
				node->parent = y;
				if (y->data.first > node->data.first)
					y->left = node;
				else
					y->right = node;
			}
			check_rb_violation(node);
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
							if (s->left)
								s->left->color = BLACK;
							s->color = RED; //case 3.3
							right_rotate(s);
							s = x->parent->right;
						}
						s->color = x->parent->right->color;
						x->parent->color = BLACK;
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
						s->left->color = BLACK;
						right_rotate(x->parent);
						x = this->root;
					}
				}
			}
			x->color = BLACK;
		}

		node_ptr minimum(node_ptr x) {
			while (x->left != NULL) {
				x = x->left;
			}
			return x;
		}

		void rb_transplant(node_ptr u, node_ptr v){
			value_type tmp = u->data;
			u->data = v->data;
			v->data = tmp;
		}

		void delete_node(value_type data) {
			node_ptr z = NULL;
			node_ptr x, y, node = this->root;
			while (node != NULL){
				if (node->data.first == data.first) {
					z = node;
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

			y = z;
			int y_original_color = y->color;
			std::cout << y->data.first << " " << y_original_color << std::endl;
			if (z->left == NULL && z->right == NULL) {
				x = z->parent;
				if (x->left == z) {
					x->left = NULL;
				}
				else {
					x->right = NULL;
				}
			} else if (z->right == NULL && z->left) {
				x = z->left;
				if (z->parent->right == z) {
					z->parent->right = z->left;
				}
				else {
					z->parent->left = z->left;
				}
				z->left->parent = z->parent;
			} else if (z->right && z->left == NULL) {
				x = z->right;
				if (z->parent->right == z) {
					z->parent->right = z->right;
				}
				else {
					z->parent->left = z->right;
				}
				z->right->parent = z->parent;
			} else {
				y = minimum(z->right);
				if (z == this->root)
					x = z;
				else
					x = z->parent;
				rb_transplant(z, y);
				z = y;
				if (y == y->parent->right) {
					y->parent->right = NULL;
				}
				else {
					y->parent->left = NULL;
				}
			}
			delete z;
			std::cout << "Hello " << std::endl;
			if (y_original_color == BLACK){
				fix_rb_delete_violation(x);
			}
		}

	};
}

#endif //CONTAINERS_RB_TREE_H
