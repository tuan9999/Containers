//
// Created by Tuan Perera on 28.01.21.
//

#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

namespace ft {
	template<typename T, typename R, typename P, typename N>
	class list_iterator {
	public:
		// Variables
		N 			pos;

		typedef P pointer;
		typedef R reference;
		typedef bidirectional_iterator_tag iterator_category;

	public:
		// Functions
		list_iterator(list_element <T> *p = 0) : pos(p) {}

		list_iterator(const list_iterator &src) : pos(src.pos) {}

		~list_iterator() {}

		list_iterator &operator=(const list_iterator &rhs) {
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

		bool operator!=(const list_iterator &rhs) {
			return this->pos != rhs.pos;
		}

		list_iterator operator++() {
			pos = pos->get_next();
			return *this;
		}

		list_iterator operator++(int) {
			list_iterator<T, R, P, N> out(*this);
			pos = pos->get_next();
			return out;
		}

		list_iterator operator--() {
			pos = pos->get_prev();
			return *this;
		}

		list_iterator operator--(int) {
			list_iterator<T, R, P, N> out(*this);
			pos = pos->get_prev();
			return out;
		}
	}

	template<typename T, typename R, typename P, typename N>
	class reverse_list_iterator {
	public:
		// Variables
		N 			pos;

		typedef P pointer;
		typedef R reference;
		typedef bidirectional_iterator_tag iterator_category;

	public:
		// Functions
		reverse_list_iterator() : pos(NULL) {}

		reverse_list_iterator(list_element <T> *p = 0) : pos(p) {}

		reverse_list_iterator(const reverse_list_iterator &src) : pos(src.pos) {}

		~reverse_list_iterator() {}

		reverse_list_iterator &operator=(const reverse_list_iterator &rhs) {
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

		bool operator!=(const reverse_list_iterator &rhs) {
			return this->pos != rhs.pos;
		}

		reverse_list_iterator operator++() {
			pos = pos->get_prev();
			return *this;
		}

		reverse_list_iterator operator++(int) {
			reverse_list_iterator<T, R, P, N> out(*this);
			pos = pos->get_prev();
			return *this;
		}

		reverse_list_iterator operator--() {
			pos = pos->get_next();
			return *this;
		}

		reverse_list_iterator operator--(int) {
			reverse_list_iterator<T, R, P, N> out(*this);
			pos = pos->get_next();
			return *this;
		}
	}
}

#endif //BIDIRECTIONAL_ITERATOR_H
