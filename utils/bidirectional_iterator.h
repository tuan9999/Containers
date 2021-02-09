//
// Created by Tuan Perera on 28.01.21.
//

#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H
#include "traits.h"

namespace ft {
	template<typename T, typename R, typename P, typename N>
	class bidirectional_iterator {
	public:
		// Variables
		typedef T	value_type;
		typedef R	reference;
		typedef P 	pointer;
		typedef N 	node_pointer;
		typedef bidirectional_iterator_tag iterator_category;

		node_pointer pos;

	public:
		// Functions
		bidirectional_iterator(node_pointer p = 0) : pos(p) {}

		bidirectional_iterator(const bidirectional_iterator &src) : pos(src.pos) {}

		~bidirectional_iterator() {}

		bidirectional_iterator &operator=(const bidirectional_iterator &rhs) {
			if (*this != rhs) {
				this->pos = rhs.pos;
			}
			return *this;
		}

		reference operator*() {
			return pos->data;
		}

		pointer operator->() {
			return &(pos->data);
		}

		bool operator!=(const bidirectional_iterator &rhs) {
			return this->pos != rhs.pos;
		}

		bidirectional_iterator operator++() {
			pos = pos->next();
			return *this;
		}

		bidirectional_iterator operator++(int) {
			bidirectional_iterator<T, R, P, N> out(*this);
			pos = pos->next();
			return out;
		}

		bidirectional_iterator operator--() {
			pos = pos->prev();
			return *this;
		}

		bidirectional_iterator operator--(int) {
			bidirectional_iterator<T, R, P, N> out(*this);
			pos = pos->prev();
			return out;
		}
	};

	template<typename T, typename R, typename P, typename N>
	class reverse_bidirectional_iterator {
	public:
		// Variables
		typedef T	value_type;
		typedef R	reference;
		typedef P 	pointer;
		typedef N 	node_pointer;
		typedef bidirectional_iterator_tag iterator_category;

		node_pointer pos;

	public:
		// Functions
		reverse_bidirectional_iterator() : pos(NULL) {}

		reverse_bidirectional_iterator(node_pointer p = 0) : pos(p) {}

		reverse_bidirectional_iterator(const reverse_bidirectional_iterator &src) : pos(src.pos) {}

		~reverse_bidirectional_iterator() {}

		reverse_bidirectional_iterator &operator=(const reverse_bidirectional_iterator &rhs) {
			if (this != rhs) {
				this->pos = rhs.pos;
			}
		}

		reference operator*() {
			return pos->data;
		}

		pointer operator->() {
			return &(pos->data);
		}

		bool operator!=(const reverse_bidirectional_iterator &rhs) {
			return this->pos != rhs.pos;
		}

		reverse_bidirectional_iterator operator++() {
			pos = pos->prev();
			return *this;
		}

		reverse_bidirectional_iterator operator++(int) {
			reverse_bidirectional_iterator<T, R, P, N> out(*this);
			pos = pos->prev();
			return *this;
		}

		reverse_bidirectional_iterator operator--() {
			pos = pos->next();
			return *this;
		}

		reverse_bidirectional_iterator operator--(int) {
			reverse_bidirectional_iterator<T, R, P, N> out(*this);
			pos = pos->next();
			return *this;
		}
	};
}

#endif //BIDIRECTIONAL_ITERATOR_H
