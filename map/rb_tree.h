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

		void recolor(node_ptr node) {
			node->color = (node->color == BLACK) ? RED : BLACK;
		}

		void check_rb_violation(node_ptr node) {
			if (node->parent->color == BLACK)
				return ;
			else {
				while (node->parent && node->parent->color == RED) {
					if (node->parent == node->parent->parent->right) {
						node_ptr u = node->parent->parent->left; //uncle
						if (u->color == RED) {// case 3.1
							u->color = BLACK;
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							node = node->parent->parent;
						}
						else if (node == node->parent->left) { // case 3.3.1 and 3.3.2
							node = node->parent;
							left_rotate(node);
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							right_rotate(node);
						}
					}
					else if (node->parent == node->parent->parent->left) {
						node_ptr u = node->parent->parent->right; //uncle
						if (u->color == RED) {// case 3.1
							u->color = BLACK;
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							node = node->parent->parent;
						}
						else if (node == node->parent->right) { // case 3.3.1 and 3.3.2
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
						s->color = BLACK; // case 3.1
						x->parent->color = RED; // case 3.1
						left_rotate(x->parent); // case 3.1
						s = x->parent->right; // case 3.1
					}
					if ((s->left && s->left->color == BLACK) && (s->right && s->right->color == BLACK)) {
						s->color = RED; // case 3.2
						x = x->parent; //case 3.2
					}
					else {
						if (s->right && s->right->color == BLACK) {
							if (s->left)
								s->left->color = BLACK; // case 3.3
							s->color = RED; //case 3.3
							right_rotate(s); // case 3.3
							s = x->parent->right; // case 3.3
						}
						s->color = x->parent->right->color; // case 3.4
						x->parent->color = BLACK; // case 3.4
						s->right->color = BLACK; // case 3.4
						left_rotate(x->parent); // case 3.4
						x = this->root;
					}
				}
				else {
					node_ptr s = x->parent->left;
					if (s->color == RED) {
						s->color = BLACK; // case 3.1
						x->parent->color = RED; // case 3.1
						right_rotate(x->parent); // case 3.1
						s = x->parent->left; // case 3.1
					}
					if ((s->right && s->right->color == BLACK) && (s->left && s->left->color == BLACK)) {
						s->color = RED; // case 3.2
						x = x->parent; //case 3.2
					}
					else {
						if (s->left && s->left->color == BLACK) {
							if (s->right)
								s->right->color = BLACK; // case 3.3
							s->color = RED; //case 3.3
							left_rotate(s); // case 3.3
							s = x->parent->left; // case 3.3
						}
						s->color = x->parent->left->color; // case 3.4
						x->parent->color = BLACK; // case 3.4
						s->left->color = BLACK; // case 3.4
						right_rotate(x->parent); // case 3.4
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
			if (u->parent == NULL) {
				root = v;
			} else if (u == u->parent->left){
				u->parent->left = v;
			} else {
				u->parent->right = v;
			}
			v->parent = u->parent;
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
			if (z->left == NULL) {
				x = z;
				rb_transplant(z->parent, z);
			} else if (z->right == NULL) {
				x = z;
				rb_transplant(z->parent, z);
			} else {
				y = minimum(z->right);
				y = y->parent;
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
