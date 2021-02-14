//
// Created by Tuan Perera on 28.01.21.
//

#ifndef CONTAINERS_MAP_NODE_H
#define CONTAINERS_MAP_NODE_H
#include <stddef.h>
#define RED		0
#define BLACK	1

namespace ft {
	template<typename T>
	class rb_tree_node {
	public:
		typedef rb_tree_node<T> *node_ptr;
		typedef rb_tree_node<T> self_type;
		typedef T				value_type;
		typedef T				*pointer;
		typedef T				&reference;

	public:
		rb_tree_node<T> *parent;
		rb_tree_node<T> *left;
		rb_tree_node<T> *right;
		// 1 for black, 0 for red
		int				color;
		value_type 		data;
		bool 			null_node;

	public:
		rb_tree_node(value_type v, int color = BLACK, bool n = false) :
				parent(NULL),
				left(NULL),
				right(NULL),
				color(color),
				data(v),
				null_node(n)
		{
		}

		rb_tree_node(const rb_tree_node &src) :
									parent(src.parent),
									left(src.left),
									right(src.right),
									color(src.color),
									data(src.data),
									null_node(src.null_node)
		{
		}

		~rb_tree_node() {
		}

		self_type &operator=(const self_type &rhs)
		{
			this->data = rhs.data;
			this->parent = rhs.parent;
			this->left = rhs.left;
			this->right = rhs.right;
			this->color = rhs.color;
			this->null_node = rhs.null_node;
			return (*this);
		}

		node_ptr minimum(node_ptr node) {
			while (node->left->null_node != true) {
				node = node->left;
			}
			return node;
		}

		node_ptr maximum(node_ptr node) {
			while (node->right->null_node != true) {
				node = node->right;
			}
			return node;
		}

		node_ptr inorder_pred_parent(node_ptr node) {
			while (node != this->parent->right)
				node = this->parent;
			return node->parent;
		}

		node_ptr next() {
			if (this->right->right != NULL) {
				return minimum(this->right);
			}
			else
				return this->parent;
		}

		node_ptr prev() {
			if (this->left->null_node != true)
				return maximum(this->left);
			else
				return inorder_pred_parent(this);
		}
	};
}

#endif //CONTAINERS_MAP_NODE_H
