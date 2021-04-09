//
// Created by Tuan Perera on 18.02.21.
//

#ifndef CONTAINERS_MULTIMAP_NODE_H
#define CONTAINERS_MULTIMAP_NODE_H
#include "vector.hpp"
#include <stddef.h>

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

		value_type	data;

	public:
		multimap_tree_node(value_type v) :
				parent(NULL),
				left(NULL),
				right(NULL),
				data(v) {
		}

		multimap_tree_node(const multimap_tree_node &src) :
				parent(src.parent),
				left(src.left),
				right(src.right),
				data(src.data) {
		}

		~multimap_tree_node() {
		}

		self_type &operator=(const self_type &rhs) {
			this->data = rhs.data;
			this->parent = rhs.parent;
			this->left = rhs.left;
			this->right = rhs.right;
			return (*this);
		}

		node_ptr minimum(node_ptr node) {
			while (node->left) {
				node = node->left;
			}
			return node;
		}

		node_ptr maximum(node_ptr node) {
			while (node->right) {
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
			if (this->right) {
				return minimum(this->right);
			} else
				return this->parent;
		}

		node_ptr prev() {
			if (this->left)
				return maximum(this->left);
			else
				return inorder_pred_parent(this);
		}
	};
}

#endif //CONTAINERS_MULTIMAP_NODE_H
