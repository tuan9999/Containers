/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/17 16:48:28 by tuperera      #+#    #+#                 */
/*   Updated: 2020/12/17 17:25:25 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# include <memory>
# include <iostream>
# include "list_element.h"
# include "list_iterator.h"
# include "reverse_list_iterator.h"
# include "traits.h"

namespace ft {
	template<class T, class Allocator = std::allocator<T> >
	class list {
		private:
			list_element<T>							*_head;
			list_element<T>							*_tail;
			size_t 									_size;

		public:
			typedef T								value_type;
			typedef Allocator						allocator_type;
			typedef std::size_t						size_type;
			typedef std::ptrdiff_t					difference_type;
			typedef T								&reference;
            typedef const T							&const_reference;
            typedef T								*pointer;
            typedef const T							*const_pointer;
			typedef list_iterator<T>				iterator;
			typedef list_iterator<const T>			const_iterator;
			typedef reverse_list_iterator<T>		reverse_iterator;
			typedef reverse_list_iterator<const T>	const_reverse_iterator;

		public:
			explicit list (const allocator_type& alloc = allocator_type()) {
				this->_head = new list_element<T>();
				this->_tail = new list_element<T>();
				this->_head->next = this->_tail;
				this->_head->prev = NULL;
				this->_tail->prev = this->_head;
				this->_tail->next = NULL;
				this->_size = 0;
			}

			explicit list (size_t n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {
				this->_head = new list_element<T>();
				this->_tail = new list_element<T>();
				this->_head->next = this->_tail;
				this->_head->prev = NULL;
				this->_tail->prev = this->_head;
				this->_tail->next = NULL;
				this->_size = 0;
				this->insert(this->end(), n, val);
			}

			template <class InputIterator>
  			list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
				  typename ft::enable_if<ft::is_iterator<typename InputIterator::iterator_category>::value, T>::type* = NULL) {
				this->_head = new list_element<T>();
				this->_tail = new list_element<T>();
				this->_head->next = this->_tail;
				this->_head->prev = NULL;
				this->_tail->prev = this->_head;
				this->_tail->next = NULL;
				this->_size = 0;
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

			list (const list& src) {
				this->_head = src._head;
				this->_tail = src._tail;
				this->_size = src._size;
			}

            ~list() {
				this->clear();
				delete this->_head;
				delete this->_tail;
            }

			list&		operator=(const list& rhs) {
				if (*this != rhs) {
					this->_head = rhs._head;
					this->_tail = rhs._tail;
					this->_size = rhs._size;
				}
			}

			// Iterators
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
				return (reverse_iterator(this->_tail->prev));
			}

			const_reverse_iterator rbegin() const {
				return (const_reverse_iterator(this->_tail->prev));
			}

			reverse_iterator rend() {
				return (reverse_iterator(this->_head));
			}

			const_reverse_iterator rend() const {
				return (const_reverse_iterator(this->_head));
			}

			// Capacity
			bool		empty() const {
				return (this->_size == 0);
			}

			size_type	size() const {
				return (this->_size);
			}

			size_type	max_size() const {
				return (size_type(-1) / sizeof(list_element<T>));
			}

			// Element access
			reference front() {
				return (this->_head->next->data);
			}

			const_reference front() const {
				return (this->_head->next->data);
			}

			reference back() {
				return (this->_tail->prev->data);
			}

			const_reference back() const {
				return (this->_tail->prev->data);
			}

			// Modifiers
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last,
				typename ft::enable_if<ft::is_iterator<typename InputIterator::iterator_category>::value, T>::type* = NULL) {
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

			void assign (size_type n, const value_type& val) {
				this->clear();
				this->insert(this->end(), n, val);
			}

			void push_front (const value_type& val) {
				list_element<T> *new_elem = new list_element<T>(val);
				new_elem->prev = this->_head;
				new_elem->next = this->_head->next;
				this->_head->next->prev = new_elem;
				this->_head->next = new_elem;
				this->_size++;
			}

			void pop_front() {
				if (this->_size) {
					list_element<T> *tmp = this->_head->next->next;
					delete this->_head->next;
					this->_head->next = tmp;
					tmp->prev = this->_head;
					this->_size--;
				}
			}

			void push_back (const value_type& val) {
				list_element<T> *new_elem = new list_element<T>(val);
				new_elem->next = this->_tail;
				new_elem->prev = this->_tail->prev;
				this->_tail->prev->next = new_elem;
				this->_tail->prev = new_elem;
				this->_size++;
			}

			void pop_back() {
				if (this->_size) {
					list_element<T> *tmp = this->_tail->prev->prev;
					delete this->_tail->prev;
					this->_tail->prev = tmp;
					tmp->next = this->_tail;
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
				int i = 1;
				while(first != last) {
					first = erase(first);
				}
				if (last.pos == this->_tail)
					return (iterator(this->_tail));
				else
					return (erase(first));
			}

			void swap (list& x) {
				list<T> *tmp = new list<T>;
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

			void resize (size_type n, value_type val = value_type()) {
				if (n < this->_size) {
					while (this->size > n)
						pop_back();
				}
				else if (n > this->_size) {
					insert(this->end(), (n - this->_size), val);
				}
			}

			void clear() {
				this->erase(this->begin(), this->end());
			}

			// Operations
	};
};

#endif