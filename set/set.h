//
// Created by Tuan Perera on 15.02.21.
//

#ifndef CONTAINERS_SET_H
#define CONTAINERS_SET_H
#include "set_tree.h"

namespace ft {
	template < class T,                        // set::key_type/value_type
			class Compare = std::less<T>,        // set::key_compare/value_compare
			class Alloc = std::allocator<T>      // set::allocator_type
	>
	class set {
		typedef T									 	key_type;
		typedef T									 	value_type;
		typedef	Compare 								key_compare;
		typedef Alloc									allocator_type;
		typedef std::size_t								size_type;
		typedef std::ptrdiff_t							difference_type;
		typedef value_type								&reference;
		typedef const value_type						&const_reference;
		typedef value_type								*pointer;
		typedef const value_type						*const_pointer;
		class value_compare : std::binary_function<value_type, value_type,bool>
		{
			friend class set;
		protected:
			Compare comp;
			value_compare (Compare c) : comp(c) {}
		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;
			bool operator() (const value_type& x, const value_type& y) const
			{
				return comp(x.first, y.first);
			}
		};

		typedef ft::set_tree<T> 					bst;
		typedef ft::rb_tree_node<value_type> 		*node_pointer;
		typedef const ft::rb_tree_node<value_type> 	*const_node_pointer;

	private:
		bst				*tree;
		size_type		t_size;
		allocator_type 	allocator;
		key_compare 	key_cmp;

	public:
		typedef bidirectional_iterator<T, reference, pointer, node_pointer>								iterator;
		typedef bidirectional_iterator<T, const_reference, const_pointer, const_node_pointer>			const_iterator;
		typedef reverse_bidirectional_iterator<T, reference, pointer, node_pointer>						reverse_iterator;
		typedef reverse_bidirectional_iterator<T, const_reference, const_pointer, const_node_pointer>	const_reverse_iterator;

		explicit set (const key_compare& comp = key_compare(),
					  const allocator_type& alloc = allocator_type()) {
			this->tree = new bst;
			this->t_size = 0;
			this->allocator = alloc;
			this->key_cmp = comp;
		}

		template <class InputIterator>
		set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(),
			 typename ft::enable_if<ft::is_iterator<typename InputIterator::iterator_category>::value, T>::type* = NULL) {
			this->tree = new bst;
			this->t_size = 0;
			this->allocator = alloc;
			this->key_cmp = comp;
			this->insert(first, last);
		}

		set (const set& x) {
			this->tree = x.tree;
			this->t_size = x.t_size;
			this->allocator = x.allocator;
			this->key_cmp = x.key_cmp;
		}

		~set() {
			delete this->tree;
		}

		set& operator= (const set& x) {
			if (*this != x) {
				this->tree = x.tree;
				this->t_size = x.t_size;
				this->allocator = x.allocator;
				this->key_cmp = x.key_cmp;
			}
			return *this;
		}

		iterator begin() {
			return (iterator(this->tree->min_val()));
		}

		const_iterator begin() const {
			return (const_iterator(this->tree->min_val()));
		}

		iterator end() {
			node_pointer n = this->tree->max_val()->right;
			n->end_node = true;
			return (iterator(n));
		}

		const_iterator end() const {
			node_pointer n = this->tree->max_val()->right;
			n->end_node = true;
			return (const_iterator(n));
		}

		reverse_iterator rbegin() {
			return (reverse_iterator(this->tree->max_val()));
		}

		const_reverse_iterator rbegin() const {
			return (const_reverse_iterator(this->tree->max_val()));
		}

		reverse_iterator rend() {
			node_pointer n = this->tree->min_val()->left;
			n->end_node = true;
			return (reverse_iterator(n));
		}

		const_reverse_iterator rend() const {
			node_pointer n = this->tree->min_val()->left;
			n->end_node = true;
			return (const_reverse_iterator(n));
		}

		bool empty() const {
			return (this->t_size == 0);
		}

		size_type size() const {
			return this->t_size;
		}

		size_type max_size() const {
			return (size_type(-1) / sizeof(ft::rb_tree_node<value_type>));
		}

		ft::pair<iterator,bool> insert (const value_type& val) {
			node_pointer n = this->tree->find(val);
			if (n) {
				return ft::pair<iterator, bool>(iterator(n), false);
			}
			else {
				n = this->tree->insert_data(val);
				this->t_size++;
				return ft::pair<iterator, bool>(iterator(n), true);
			}
		}

		iterator insert (iterator position, const value_type& val) {
			(void)position;
			node_pointer n = this->tree->find(val);
			if (n) {
				return iterator(n);
			}
			else {
				n = this->tree->insert_data(val);
				this->t_size++;
				return iterator(n);
			}
		}

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last,
					 typename ft::enable_if<ft::is_iterator<typename InputIterator::iterator_category>::value, T>::type* = NULL) {
			node_pointer n;
			while (first != last) {
				n = this->tree->find(*first);
				if(!n) {
					n = this->tree->insert_data(*first);
					this->t_size++;
				}
				first++;
			}
		}

		void erase (iterator position) {
			node_pointer n = this->tree->find(*position);
			if (!n) {
				return ;
			}
			else {
				this->tree->delete_node(*position);
				this->t_size--;
				return ;
			}
		}

		size_type erase (const value_type& val) {
			node_pointer n = this->tree->find(val);
			if (!n) {
				return 0;
			}
			else {
				this->tree->delete_node(val);
				this->t_size--;
				return 1;
			}
		}

		void erase (iterator first, iterator last) {
			node_pointer n;
			while (first != last) {
				n = this->tree->find(*first);
				if (!n) {
					continue ;
				}
				else {
					this->tree->delete_node(*first);
					this->t_size--;
				}
				first++;
			}
		}

		void swap (set& x) {
			if (*this != x) {
				set tmp = x;
				x = *this;
				*this = tmp;
			}
		}

		void clear() {
			this->tree->delete_tree(this->tree->get_root());
			this->t_size = 0;
		}

		key_compare key_comp() const {
			return this->key_cmp;
		}

		value_compare value_comp() const {
			return value_comp(key_cmp);
		}

		iterator find (const value_type& val) const {
			return iterator(this->tree->find(val));
		}

		size_type count (const value_type& val) const {
			node_pointer n = this->tree->find(val);
			return n ? 1 : 0;
		}

		iterator lower_bound (const value_type& val) const {
			node_pointer n = this->tree->find(val);
			if (!n) {
				n = this->tree->find_key_after(val);
			}
			return iterator(n);
		}

		iterator upper_bound (const value_type& val) const {
			return iterator(this->tree->find_key_after(val));
		}

		ft::pair<iterator,iterator> equal_range (const value_type& val) const {
			iterator it1;
			iterator it2;
			node_pointer n = this->tree->find(val);
			if (n) {
				it2 = iterator(n);
				it1 = it2++;
			}
			else {
				it1 = iterator(this->tree->find_key_after(val));
				it2 = it1;
			}
			return ft::pair<iterator, iterator>(it1, it2);
		}

		allocator_type get_allocator() const {
			return this->allocator;
		}

		void print() {
			if (this->tree->get_root() != NULL)
				this->tree->print(this->tree->get_root(), 1);
		}
	};
}

#endif //CONTAINERS_SET_H
