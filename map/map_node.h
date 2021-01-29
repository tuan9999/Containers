//
// Created by Tuan Perera on 28.01.21.
//

#ifndef CONTAINERS_MAP_NODE_H
#define CONTAINERS_MAP_NODE_H

namespace ft {
	template<typename T>
	class rb_tree_node {
	private:
		typedef rb_tree_node<T> self_type;
		typedef T				value_type;
		typedef T				*pointer;
		typedef T				&reference;

		rb_tree_node<T> *parent;
		rb_tree_node<T> *left;
		rb_tree_node<T> *right;
		int				color;
		value_type 		data;

	public:
		rb_tree_node(const T v) {
			this->value_type = v;
			this->parent = NULL;
			this->left = NULL;
			this->right = NULL;
			this->color = 1;
		}
		rb_tree_node(const rb_tree_node &src) :
									parent(src.parent),
									left(src.left),
									right(src.right),
									color(src.color),
									key_type(src.key_type),
									mapped_type(src.mapped_type) {}

		~rb_tree_node() {}

		self_type &operator=(const self_type &other)
		{
			this->data = other.data;
			this->parent = other.parent;
			this->left = other.left;
			this->right = other.right;
			return (*this);
		}
	};
}

#endif //CONTAINERS_MAP_NODE_H
