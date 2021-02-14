//
// Created by Tuan Perera on 11.02.21.
//

#ifndef CONTAINERS_DEQUE_H
#define CONTAINERS_DEQUE_H
#include "random_access_iterator_deque.h"
#include "list_element.h"

namespace ft {
	template < class T, class Allocator = std::allocator<T> >
	class deque {
	public:
		typedef T								value_type;
		typedef Allocator						allocator_type;
		typedef std::size_t						size_type;
		typedef std::ptrdiff_t					difference_type;
		typedef T								&reference;
		typedef const T							&const_reference;
		typedef T								*pointer;
		typedef const T							*const_pointer;

		typedef random_access_iterator<T, reference, pointer> 						iterator;
		typedef random_access_iterator<T, const_reference, const_pointer> 			const_iterator;
		typedef reverse_random_access_iterator<T, reference, pointer> 				reverse_iterator;
		typedef reverse_random_access_iterator<T, const_reference, const_pointer> 	const_reverse_iterator;

		typedef list_element<T>	*list_pointer;

	private:
		list_pointer 	_head;
		list_pointer 	_tail;
		size_type 		_size;
		allocator_type 	_allocate;

	public:
		explicit deque (const allocator_type& alloc = allocator_type()) {
			this->_allocate = alloc;
			this->_head = new list_element<T>;
			this->_tail = new list_element<T>;
			this->_head->next = this->_tail;
			this->_tail->prev = this->_head;
		}

		explicit deque (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {
			this->_head = new list_element<T>();
			this->_tail = new list_element<T>();
			this->_head->next = this->_tail;
			this->_tail->prev = this->_head;
			this->_size = 0;
			this->insert(this->end(), n, val);
			this->allocator = alloc;
		}

		template <class InputIterator>
		deque (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			   typename ft::enable_if<ft::is_iterator<typename InputIterator::iterator_category>::value, T>::type* = NULL) {
			this->_head = new list_element<T>();
			this->_tail = new list_element<T>();
			this->_head->next = this->_tail;
			this->_tail->prev = this->_head;
			this->_size = 0;
			this->allocator = alloc;
			InputIterator tmp = first;
			while (tmp != last) {
				push_back(*tmp);
				tmp++;
			}
			if (*tmp == 0)
				push_back(*first);
			else
				push_back(*tmp);
		}

		deque (const deque& x) {
			this->_tail = x._tail;
			this->_head = x._head;
			this->_size = x._size;
			this->_allocate = x._allocate;
		}

		~deque() {

		}

		deque& operator= (const deque& x) {
			this->_tail = x._tail;
			this->_head = x._head;
			this->_size = x._size;
			this->_allocate = x._allocate;
			return *this;
		}

		iterator begin() {
			return (iterator(this->_head->next));
		}

		const_iterator begin() const {
			return (const_iterator(this->_head->next));
		}

		iterator end() {
			return (iterator(this->_tail));
		}

		const_iterator end() const {
			return (const_iterator(this->_tail));
		}

		reverse_iterator rbegin() {
			return (iterator(this->_tail->next));
		}

		const_reverse_iterator rbegin() const {
			return (const_iterator(this->_tail->next));
		}

		reverse_iterator rend()  {
			return (iterator(this->_head->prev));
		}

		const_reverse_iterator rend() const {
			return (const_iterator(this->_head->prev));
		}

		size_type size() const {
			return this->_size;
		}

		size_type max_size() const {
			return (size_type(-1) / sizeof(list_element<T>));
		}

		void resize (size_type n, value_type val = value_type()) {
			if (n < this->_size) {
				while (this->size > n)
					pop_back();
			}
			else if (n > this->_size) {
				insert(this->end(), (n - this->_size), val);
			}
		}

		bool empty() const {
			return (this->_size == 0);
		}

		reference operator[] (size_type n) {
			list_pointer tmp = this->_head;
			while (n) {
				tmp = tmp->next;
				n--;
			}
			return (tmp->data);
		}

		const_reference operator[] (size_type n) const {
			list_pointer tmp = this->_head;
			while (n) {
				tmp = tmp->next;
				n--;
			}
			return (tmp->data);
		}

		reference at (size_type n) {
			if (n <= this->_size) {
				list_pointer tmp = this->_head;
				while (n) {
					tmp = tmp->next;
					n--;
				}
				return (tmp->data);
			}
			else
				throw std::out_of_range("Index out of range.");
		}

		const_reference at (size_type n) const {
			if (n <= this->_size) {
				list_pointer tmp = this->_head;
				while (n) {
					tmp = tmp->next;
					n--;
				}
				return (tmp->data);
			}
			else
				throw std::out_of_range("Index out of range.");
		}

		reference front() {
			return this->_head->data;
		}

		const_reference front() const {
			return this->_head->data;
		}

		reference back() {
			return this->_tail->prev->data;
		}

		const_reference back() const {
			return this->_tail->prev->data;
		}

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last,
					 typename ft::enable_if<ft::is_iterator<typename InputIterator::iterator_category>::value, T>::type* = NULL) {
			InputIterator tmp = first;
			this->clear();
			while (tmp != last) {
				push_back(*tmp);
				tmp++;
			}
			if (*tmp == 0)
				push_back(*first);
			else
				push_back(*tmp);
		}

		void assign (size_type n, const value_type& val) {
			this->clear();
			this->insert(this->end(), n, val);
		}

		void push_back (const value_type& val) {
			list_pointer tmp = new list_element<T>(val);
			tmp->next = this->_tail;
			tmp->prev = this->_tail->prev;
			this->_tail->prev->next = tmp;
			this->_tail->prev = tmp;
			this->_size++;
		}

		void push_front (const value_type& val) {
			list_element<T> *new_elem = new list_element<T>(val);
			new_elem->prev = this->_head;
			new_elem->next = this->_head->next;
			this->_head->next->prev = new_elem;
			this->_head->next = new_elem;
			this->_size++;
		}

		void pop_back() {
			if (this->_size) {
				list_pointer tmp = this->_tail->prev->prev;
				delete this->_tail->prev;
				this->_tail->prev = tmp;
				tmp->next = this->_tail;
				this->_size--;
			}
		}

		void pop_front() {
			if (this->_size) {
				list_pointer tmp = this->_head->next->next;
				delete this->_head->next;
				this->_head->next = tmp;
				tmp->prev = this->_head;
				this->_size--;
			}
		}

		iterator insert(iterator position, const value_type& val) {
			list_element<T> *new_ele = new list_element<T>(val);
			new_ele->next = position.pos;
			new_ele->prev = position.pos->prev;
			position.pos->prev->next = new_ele;
			position.pos->prev = new_ele;
			this->_size++;
			return (iterator(new_ele));
		}

		void insert(iterator position, size_type n, const value_type& val) {
			while (n > 0) {
				insert(position, val);
				n--;
			}
		}

		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last,
					typename ft::enable_if<ft::is_iterator<typename InputIterator::iterator_category>::value, T>::type* = NULL) {
			while (first != last) {
				insert(position, *first);
				first++;
			}
		}

		iterator erase(iterator position) {
			if (this->_size) {
				list_element<T> *tmp = position.pos->next;
				position.pos->next->prev = position.pos->prev;
				position.pos->prev->next = position.pos->next;
				delete position.pos;
				position.pos = tmp;
				this->_size--;
			}
			return (position);
		}

		iterator erase(iterator first, iterator last) {
			while(first != last) {
				first = erase(first);
			}
			if (last.pos == this->_tail)
				return (iterator(this->_tail));
			else
				return (erase(first));
		}

		void swap (deque& x) {
			deque<T> *tmp = new deque<T>;
			tmp->_head = this->_head;
			tmp->_tail = this->_tail;
			tmp->_size = this->_size;

			this->_head = x._head;
			this->_tail = x._tail;
			this->_size = x._size;

			x._head = tmp->_head;
			x._tail = tmp->_tail;
			x._size = tmp->_size;
			delete tmp;
		}

		void clear() {
			this->erase(this->begin(), this->end());
		}

		allocator_type get_allocator() const {
			return this->_allocate;
		}
	};
}

template <class T, class Alloc>
bool operator== (const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs) {
	if (lhs.size() == rhs.size()) {
		typename ft::deque<T>::const_iterator it_lhs = lhs.begin();
		typename ft::deque<T>::const_iterator it_rhs = rhs.begin();
		while (it_lhs != lhs.end()) {
			if (*it_lhs != *it_rhs)
				return (false);
			it_lhs++;
			it_rhs++;
		}
		return (true);
	}
	return (false);
}

template <class T, class Alloc>
bool operator!= (const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs) {
	if (lhs.size() == rhs.size()) {
		typename ft::deque<T>::const_iterator it_lhs = lhs.begin();
		typename ft::deque<T>::const_iterator it_rhs = rhs.begin();
		while (it_lhs != lhs.end()) {
			if (*it_lhs != *it_rhs)
				return (true);
			it_lhs++;
			it_rhs++;
		}
		return (false);
	}
	return (true);
}

template <class T, class Alloc>
bool operator<  (const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs) {
	typename ft::deque<T>::const_iterator it_lhs = lhs.begin();
	typename ft::deque<T>::const_iterator it_rhs = rhs.begin();
	if (lhs == rhs || lhs.size() > rhs.size())
		return (false);
	if (lhs.size() == rhs.size()) {
		while (it_lhs != lhs.end()) {
			if (*it_lhs > *it_rhs)
				return (false);
			it_lhs++;
			it_rhs++;
		}
	}
	return (true);
}

template <class T, class Alloc>
bool operator<= (const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs) {
	return (!(rhs < lhs));
}

template <class T, class Alloc>
bool operator>  (const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs) {
	return (rhs < lhs);
}

template <class T, class Alloc>
bool operator>= (const ft::deque<T,Alloc>& lhs, const ft::deque<T,Alloc>& rhs) {
	return (!(lhs < rhs));
}

template <class T, class Alloc>
void swap (ft::deque<T,Alloc>& x, ft::deque<T,Alloc>& y) {
	ft::deque<T> *tmp = new ft::deque<T>;
	tmp->_head = y->_head;
	tmp->_tail = y->_tail;
	tmp->_size = y->_size;

	y->_head = x._head;
	y->_tail = x._tail;
	y->_size = x._size;

	x._head = tmp->_head;
	x._tail = tmp->_tail;
	x._size = tmp->_size;
	delete tmp;
}

#endif //CONTAINERS_DEQUE_H
