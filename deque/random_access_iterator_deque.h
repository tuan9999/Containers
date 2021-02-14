//
// Created by Tuan Perera on 12.02.21.
//

#ifndef CONTAINERS_RANDOM_ACCESS_ITERATOR_DEQUE_H
#define CONTAINERS_RANDOM_ACCESS_ITERATOR_DEQUE_H
#include "list_element.h"

namespace ft {
	template<typename T, typename R, typename P>
	class random_access_iterator_deque {
	public:
		typedef P							pointer;
		typedef R							reference;
		typedef size_t						size_type;
		typedef list_element<T>				*list_pointer;
		typedef random_access_iterator_tag 	iterator_category;

	private:
		list_pointer 						pos;
		list_pointer			 			head;
		list_pointer		 				tail;

	public:
		// Functions
		random_access_iterator_deque(list_pointer position = NULL) : pos(position) {
			list_pointer tmp = pos;
			while (tmp->prev != NULL)
				tmp = tmp->prev;
			head = tmp;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tail = tmp;
		}

		random_access_iterator_deque(const random_access_iterator_deque& src) : pos(src.pos), head(src.head), tail(src.tail) {}

		~random_access_iterator_deque() { }

		random_access_iterator_deque& operator=(const random_access_iterator_deque& rhs) {
			if (*this != rhs) {
				this->pos = rhs.pos;
				this->head = rhs.head;
				this->tail = rhs.tail;
			}
			return *this;
		}

		reference operator*() {
			return pos->data;
		}

		pointer operator->() {
			return &(pos->data);
		}

		bool operator!=(const random_access_iterator_deque &rhs) {
			return this->pos != rhs.pos;
		}

		bool operator==(const random_access_iterator_deque &rhs) {
			return this->pos == rhs.pos;
		}

		random_access_iterator_deque operator++() {
			pos = pos->next;
			return *this;
		}

		random_access_iterator_deque operator++(int) {
			random_access_iterator_deque<T, R, P> out(*this);
			pos = pos->next;
			return out;
		}

		random_access_iterator_deque operator--() {
			pos = pos->prev;
			return *this;
		}

		random_access_iterator_deque operator--(int) {
			random_access_iterator_deque<T, R, P> out(*this);
			pos = pos->prev;
			return out;
		}

		random_access_iterator_deque& operator+=(size_type n) {
			while (n) {
				pos = pos->next;
				n--;
			}
			return *this;
		}

		random_access_iterator_deque operator+(size_type n) {
			random_access_iterator_deque<T, R, P> out(*this);
			while (n) {
				pos = pos->next;
				n--;
			}
			return out;
		}

		random_access_iterator_deque& operator-=(size_type n) {
			while (n) {
				pos = pos->prev;
				n--;
			}
			return *this;
		}

		random_access_iterator_deque operator-(size_type n) {
			random_access_iterator_deque<T, R, P> out(*this);
			while (n) {
				pos = pos->prev;
				n--;
			}
			return out;
		}

		reference operator[](size_type n) const {
			list_pointer tmp = head;
			while (n) {
				tmp = tmp->next;
				n--;
			}
			return tmp->data;
		}
	};

	template<typename T, typename R, typename P>
	class reverse_random_access_iterator_deque {
	public:
		typedef P							pointer;
		typedef R							reference;
		typedef size_t						size_type;
		typedef list_element<T>				*list_pointer;
		typedef random_access_iterator_tag 	iterator_category;

	private:
		list_pointer 						pos;
		list_pointer			 			head;
		list_pointer		 				tail;

	public:
		// Functions
		reverse_random_access_iterator_deque(list_pointer position = NULL) : pos(position) {
			list_pointer tmp = pos;
			while (tmp->prev != NULL)
				tmp = tmp->prev;
			head = tmp;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tail = tmp;
		}

		reverse_random_access_iterator_deque(const reverse_random_access_iterator_deque& src) : pos(src.pos), head(src.head), tail(src.tail) {}

		~reverse_random_access_iterator_deque() { }

		reverse_random_access_iterator_deque& operator=(const reverse_random_access_iterator_deque& rhs) {
			if (*this != rhs) {
				this->pos = rhs.pos;
				this->head = rhs.head;
				this->tail = rhs.tail;
			}
			return *this;
		}

		reference operator*() {
			return pos->data;
		}

		pointer operator->() {
			return &(pos->data);
		}

		bool operator!=(const reverse_random_access_iterator_deque &rhs) {
			return this->pos != rhs.pos;
		}

		bool operator==(const reverse_random_access_iterator_deque &rhs) {
			return this->pos == rhs.pos;
		}

		reverse_random_access_iterator_deque operator++() {
			pos = pos->prev;
			return *this;
		}

		reverse_random_access_iterator_deque operator++(int) {
			reverse_random_access_iterator_deque<T, R, P> out(*this);
			pos = pos->prev;
			return out;
		}

		reverse_random_access_iterator_deque operator--() {
			pos = pos->next;
			return *this;
		}

		reverse_random_access_iterator_deque operator--(int) {
			reverse_random_access_iterator_deque<T, R, P> out(*this);
			pos = pos->next;
			return out;
		}

		reverse_random_access_iterator_deque& operator+=(size_type n) {
			while (n) {
				pos = pos->prev;
				n--;
			}
			return *this;
		}

		reverse_random_access_iterator_deque operator+(size_type n) {
			reverse_random_access_iterator_deque<T, R, P> out(*this);
			while (n) {
				pos = pos->prev;
				n--;
			}
			return out;
		}

		reverse_random_access_iterator_deque& operator-=(size_type n) {
			while (n) {
				pos = pos->next;
				n--;
			}
			return *this;
		}

		reverse_random_access_iterator_deque operator-(size_type n) {
			reverse_random_access_iterator_deque<T, R, P> out(*this);
			while (n) {
				pos = pos->next;
				n--;
			}
			return out;
		}

		reference operator[](size_type n) const {
			list_pointer tmp = head;
			while (n) {
				tmp = tmp->next;
				n--;
			}
			return tmp->data;
		}
	};
}

#endif //CONTAINERS_RANDOM_ACCESS_ITERATOR_DEQUE_H
