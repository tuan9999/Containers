//
// Created by Tuan Perera on 18.02.21.
//

#ifndef CONTAINERS_MULTIMAP_NODE_H
#define CONTAINERS_MULTIMAP_NODE_H
#include "vector.hpp"
#include <stddef.h>
#define RED		0
#define BLACK	1

namespace ft {
	template<typename Key, typename Mapped, typename T>
	class multimap_tree_node {
	public:
		typedef multimap_tree_node<Key, Mapped, T>	*node_ptr;
		typedef multimap_tree_node<Key, Mapped, T>	self_type;
		typedef Key									key_type;
		typedef Mapped								mapped_type;
		typedef T 									value_type;
		typedef T 									*pointer;
		typedef T 									&reference;

	public:
		multimap_tree_node<Key, Mapped, T> *parent;
		multimap_tree_node<Key, Mapped, T> *left;
		multimap_tree_node<Key, Mapped, T> *right;
		// 1 for black, 0 for red
		int			color;
		value_type	data;
		bool		null_node;
		bool		end_node;
		size_t 		count;

	public:
		multimap_tree_node(value_type v, int color = BLACK, bool n = false, size_t count = 1) :
				parent(NULL),
				left(NULL),
				right(NULL),
				color(color),
				data(v),
				null_node(n),
				end_node(false),
				count(count) {
		}

		multimap_tree_node(const multimap_tree_node &src) :
				parent(src.parent),
				left(src.left),
				right(src.right),
				color(src.color),
				data(src.data),
				null_node(src.null_node),
				end_node(src.end_node),
				count(src.count) {
		}

		~multimap_tree_node() {
		}

		self_type &operator=(const self_type &rhs) {
			this->data = rhs.data;
			this->parent = rhs.parent;
			this->left = rhs.left;
			this->right = rhs.right;
			this->color = rhs.color;
			this->null_node = rhs.null_node;
			this->end_node = rhs.end_node;
			this->count = rhs.count;
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
			static size_t t_count = 1;
			if (t_count < this->count) {
				t_count++;
				return this;
			}
			while (t_count > 1)
				t_count--;
			if (this->right->null_node != true) {
				return minimum(this->right);
			} else if (this->right->end_node == true) {
				return this->right;
			} else
				return this->parent;
		}

		node_ptr prev() {
			static size_t t_count = 1;
			if (t_count < this->count) {
				t_count++;
				return this;
			}
			while (t_count > 1)
				t_count--;
			if (this->left->null_node != true)
				return maximum(this->left);
			else if (this->left->end_node == true)
				return this->left;
			else
				return inorder_pred_parent(this);
		}
	};
}

#endif //CONTAINERS_MULTIMAP_NODE_H
