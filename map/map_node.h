//
// Created by Tuan Perera on 28.01.21.
//

#ifndef CONTAINERS_MAP_NODE_H
#define CONTAINERS_MAP_NODE_H
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

	public:
		rb_tree_node(const T v, int color = BLACK) :
				parent(NULL),
				left(NULL),
				right(NULL),
				color(color),
				data(v) {}
		rb_tree_node(const rb_tree_node &src) :
									parent(src.parent),
									left(src.left),
									right(src.right),
									color(src.color),
									data(src.data) {}

		~rb_tree_node() {}

		self_type &operator=(const self_type &rhs)
		{
			this->data = rhs.data;
			this->parent = rhs.parent;
			this->left = rhs.left;
			this->right = rhs.right;
			this->color = rhs.color;
			return (*this);
		}
	};
}

#endif //CONTAINERS_MAP_NODE_H