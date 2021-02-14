//
// Created by Tuan Perera on 17.01.21.
//

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>
# include <iostream>
# include "traits.h"
# include "random_access_iterator.hpp"

namespace ft {
	template < class T, class Allocator = std::allocator<T> >
	class vector {
	private:
		T 			*_array;
		size_t		_size;
		size_t		_capacity;
		Allocator 	_alloca;

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

	public:
		explicit vector (const allocator_type& alloc = allocator_type()) {
			this->_array = NULL;
			this->_size = 0;
			this->_capacity = 0;
			this->_alloca = alloc;
		}

		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {
			this->_capacity = 0;
			this->_alloca = alloc;
			this->reserve(n);
			while (n > 0) {
				this->push_back(val);
				n--;
			}
		}

		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<ft::is_iterator<typename InputIterator::iterator_category>::value, T>::type* = NULL) {
			this->_capacity = 0;
			this->_array = NULL;
			this->_alloca = alloc;
			this->reserve(get_range_length(first, last));
			while (first != last) {
				this->push_back(*first);
				first++;
			}
		}

		vector (const vector& x) {
			this->_capacity = 0;
			this->_array = NULL;
			this->reserve(x._capacity);
			for (const_iterator it = x.begin(); it != x.end(); it++) {
				this->push_back(*it);
			}
		}

		~vector() {
			delete[] this->_array;
		}

		vector& operator= (const vector& x) {
			this->_capacity = x._capacity;
			this->clear();
			for (const_iterator it = x.begin(); it != x.end(); it++) {
				this->push_back(*it);
			}
			return *this;
		}

		// Iterators
		iterator begin() {
			return iterator(this->_array);
		}

		const_iterator begin() const {
			return const_iterator(this->_array);
		}

		iterator end() {
			return iterator(this->_array + this->_size);
		}

		const_iterator end() const {
			return const_iterator(this->_array + this->_size);
		}

		reverse_iterator rbegin() {
			return reverse_iterator(this->_array + this->_size - 1);
		}

		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(this->_array + this->_size - 1);
		}

		reverse_iterator rend() {
			return reverse_iterator(this->_array - 1);
		}

		const_reverse_iterator rend() const {
			return const_reverse_iterator(this->_array - 1);
		}

		// Capacity
		size_type size() const {
			return this->_size;
		}

		size_type max_size() const {
			return (size_type(-1) / sizeof(T));
		}

		void resize (size_type n, value_type val = value_type()) {
			if (n <= this->_size)
				this->_size = n;
			else {
				n -= this->_size;
				while (n > 0) {
					this->push_back(val);
					n--;
				}
			}
		}

		size_type capacity() const {
			return this->_capacity;
		}

		bool empty() const {
			return (this->_size == 0);
		}

		void reserve (size_type n) {
			if (n > this->_capacity) {
				pointer tmp = new value_type[n];

				this->_capacity = n;
				for (size_t i = 0; i < this->_size; i++) {
					tmp[i] = this->_array[i];
				}

				if (this->_array)
					delete[] this->_array;
				this->_array = tmp;
			}
		}

		// Element Access
		reference operator[] (size_type n) {
			return this->_array[n];
		}

		const_reference operator[] (size_type n) const {
			return this->_array[n];
		}

		reference at(size_type n) {
			if (n >= this->_size)
				throw std::out_of_range("vector: access out of bounds.");
			else
				return this->_array[n];
		}

		const_reference at(size_type n) const {
			if (n >= this->_size)
				throw std::out_of_range("vector: access out of bounds.");
			else
				return this->_array[n];
		}

		reference front() {
			return this->_array[0];
		}

		const_reference front() const {
			return this->_array[0];
		}

		reference back() {
			return this->_array[this->_size - 1];
		}

		const_reference back() const {
			return this->_array[this->_size - 1];
		}

		// Modifiers
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last,
					typename ft::enable_if<ft::is_iterator<typename InputIterator::iterator_category>::value, T>::type* = NULL) {
			this->clear();
			while (first != last) {
				push_back(*first);
				first++;
			}
		}

		void assign(size_type n, const value_type& val) {
			if (n > this->_capacity)
				reserve(n * 2);
			this->_size = n;
			for (int i = 0; i < n; i++) {
				this->_array[i] = val;
			}
		}

		void push_back(const value_type& val) {
			if (this->_size + 1 > this->_capacity) {
				reserve((this->_size + 1) * 2);
			}
			this->_size++;
			this->_array[this->_size - 1] = val;
		}

		void pop_back() {
			this->_size--;
		}

		iterator insert(iterator position, const value_type& val) {
			if (this->_size + 1 > this->_capacity) {
				reserve((this->_size + 1) * 2);
			}
			pointer sub_array = get_sub_array(position);
			this->push_back(val);
			*position = val;
			iterator it = position + 1;
			int i = 0;
			while (it != this->end()) {
				*it = sub_array[i];
				it++;
				i++;
			}
			delete[] sub_array;
			this->pop_back();
			this->_size++;
			return position;
		}

		void insert (iterator position, size_type n, const value_type& val) {
			while (n != 0) {
				insert(position, val);
				n--;
			}
		}

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last,
					 typename ft::enable_if<ft::is_iterator<typename InputIterator::iterator_category>::value, T>::type* = NULL) {
			while (first != last) {
				insert(position, *first);
				position++;
				first++;
			}
		}

		iterator erase(iterator position) {
			for (iterator it = position; it != this->end() - 1; it++) {
				*it = *(it + 1);
			}
			this->_size--;
			return position;
		}

		iterator erase (iterator first, iterator last) {
			int i = 0;
			while (first != last) {
				*first = *last;
				first++;
				i++;
			}
			this->_size -= i;
			return first;
		}

		void swap (vector& x) {
			vector tmp;

			tmp._array = x._array;
			x._array = this->_array;
			this->_array = tmp._array;
		}

		void clear() {
			delete[] this->_array;
			this->_array = new value_type[this->_capacity];
			this->_size = 0;
		}

		// Allocator
		allocator_type get_allocator() const {
			return this->_alloca;
		}

	private:
		pointer get_sub_array(iterator position) {
			int i = 0;
			pointer ret = new value_type[get_sub_array_length(position)];
			while (position != this->end()) {
				ret[i] = *position;
				position++;
				i++;
			}
			return ret;
		}

		size_t get_sub_array_length(iterator position) {
			size_t i = 0;
			while (position != this->end()) {
				i++;
				position++;
			}
			return i;
		}

		template <class InputIterator>
		size_t get_range_length(InputIterator first, InputIterator last) {
			size_t i = 0;
			while (first != last) {
				i++;
				first++;
			}
			return i;
		}
	};
}

template <class T, class Alloc>
bool operator== (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	if (lhs.size() == rhs.size()) {
		typename ft::vector<T, Alloc>::const_iterator lit;
		typename ft::vector<T, Alloc>::const_iterator rit = rhs.begin();
		for (lit = lhs.begin(); lit != lhs.end(); lit++) {
			if (*lit != *rit)
				return false;
			rit++;
		}
	}
	else
		return false;
	return true;
}

template <class T, class Alloc>
bool operator!= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	if (lhs.size() == rhs.size()) {
		typename ft::vector<T, Alloc>::const_iterator lit;
		typename ft::vector<T, Alloc>::const_iterator rit = rhs.begin();
		for (lit = lhs.begin(); lit != lhs.end(); lit++) {
			if (*lit != *rit)
				return true;
			rit++;
		}
	}
	else
		return true;
	return false;
}

template <class T, class Alloc>
bool operator<  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	typename ft::vector<T, Alloc>::const_iterator lit = lit.begin();
	typename ft::vector<T, Alloc>::const_iterator rit = rhs.begin();
	if (lhs == rhs || lhs.size() > rhs.size())
		return false;
	while (lit != lhs.end) {
		if (*lit > *rit)
			return false;
		lit++;
		rit++;
	}
	return true;
}

template <class T, class Alloc>
bool operator<= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	return (!(lhs > rhs));
}

template <class T, class Alloc>
bool operator>  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	return (rhs < lhs);
}

template <class T, class Alloc>
bool operator>= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
	return (!(lhs < rhs));
}

template <class T, class Alloc>
void swap (ft::vector<T,Alloc>& x, ft::vector<T,Alloc>& y) {
	ft::vector<T> tmp;
	tmp = y;
	y = x;
	x = tmp;
}

#endif //VECTOR_HPP
