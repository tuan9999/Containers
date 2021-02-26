//
// Created by Tuan Perera on 28.01.21.
//

#ifndef MAP_H
#define MAP_H
#include "rb_tree.h"
#include "../utils/bidirectional_iterator.h"
#include "pair.h"

namespace ft {
	template < class Key,                                   				// map::key_type
			class T,                                       					// map::mapped_type
			class Compare = std::less<Key>,                     			// map::key_compare
			class Allocator = std::allocator<ft::pair<const Key,T> >    	// map::allocator_type
	>
	class map {
	public:
		typedef Key 									key_type;
		typedef T 										mapped_type;
		typedef ft::pair<const key_type,mapped_type> 	value_type;
		typedef	Compare 								key_compare;
		typedef Allocator								allocator_type;
		typedef std::size_t								size_type;
		typedef std::ptrdiff_t							difference_type;
		typedef value_type								&reference;
		typedef const value_type						&const_reference;
		typedef value_type								*pointer;
		typedef const value_type						*const_pointer;
		class value_compare : std::binary_function<value_type, value_type,bool>
		{
			friend class map;
		protected:
			Compare comp;
			value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;
			bool operator() (const value_type& x, const value_type& y) const
			{
				return comp(x.first, y.first);
			}
		};

		typedef ft::rb_tree<Key, T, value_type> 	bst;
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

	public:
		explicit map (const key_compare& comp = key_compare(),
					  const allocator_type& alloc = allocator_type()) {
			key_cmp = comp;
			allocator = alloc;
			this->tree = new bst();
			this->t_size = 0;
		}

		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			 const key_compare& comp = key_compare(),
			 const allocator_type& alloc = allocator_type(),
			 typename ft::enable_if<ft::is_iterator<typename InputIterator::iterator_category>::value, T>::type* = NULL) {
			key_cmp = comp;
			allocator = alloc;
			this->tree = new bst();
			this->t_size = 0;
			this->insert(first, last);
		}

		map (const map& x) {
			this->tree = x.tree;
			this->allocator = x.allocator;
			this->key_cmp = x.key_cmp;
			this->t_size = x.t_size;
		}

		~map() {
			delete this->tree;
		}

		map& operator= (const map& x) {
			if (*this != x) {
				this->tree = x.tree;
				this->allocator = x.allocator;
				this->key_cmp = x.key_cmp;
				this->t_size = x.t_size;
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
			return (this->t_size);
		}

		size_type max_size() const {
			return (size_type(-1) / sizeof(ft::rb_tree_node<value_type>));
		}

		mapped_type& operator[] (const key_type& k) {
			if (this->tree->find(k) == NULL) {
				this->tree->insert_data(ft::pair<key_type, mapped_type>(k, 0));
				this->t_size++;
			}
			return this->tree->find(k)->data.second;
		}

		void insert (const value_type& val) {
			node_pointer n = this->tree->find(val.first);
			if (n) {
				return ;
			}
			else {
				n = this->tree->insert_data(val);
				this->t_size++;
				return ;
			}
		}

		iterator insert (iterator position, const value_type& val) {
			(void)position;
			node_pointer n = this->tree->find(val.first);
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
				n = this->tree->find(first->first);
				if (n) {
					continue ;
				}
				else {
					n = this->tree->insert_data(*first);
					this->t_size++;
				}
				first++;
			}
		}

		void erase (iterator position) {
			node_pointer n = this->tree->find(position->first);
			if (!n) {
				return ;
			}
			else {
				this->tree->delete_node(*position);
				this->t_size--;
				return ;
			}
		}

		size_type erase (const key_type& k) {
			node_pointer n = this->tree->find(k);
			if (!n) {
				return 0;
			}
			else {
				this->tree->delete_node(n->data);
				this->t_size--;
				return 1;
			}
		}

		void erase (iterator first, iterator last) {
			node_pointer n;
			while (first != last) {
				n = this->tree->find(first->first);
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

		void swap (map& x) {
			if (*this != x) {
				map tmp = x;
				x = *this;
				*this = tmp;
			}
		}

		void clear() {
			this->tree->delete_tree(this->tree->get_root());
			this->t_size = 0;
		}

		key_compare key_comp() const {
			return (key_cmp);
		}

		value_compare value_comp() const {
			return (value_compare(key_cmp));
		}

		iterator find (const key_type& k) {
			return iterator(this->tree->find(k));
		}

		const_iterator find (const key_type& k) const {
			return const_iterator(this->tree->find(k));
		}

		size_type count (const key_type& k) const {
			return (this->tree->find(k) ? 1 : 0);
		}

		iterator lower_bound (const key_type& k) {
			node_pointer n = this->tree->find(k);
			if (n->prev()) {
				return (iterator(n->prev()));
			}
			else
				return this->end();
		}

		const_iterator lower_bound (const key_type& k) const {
			node_pointer n = this->tree->find(k);
			if (n->prev()) {
				return (const_iterator(n->prev()));
			}
			else
				return this->end();
		}

		iterator upper_bound (const key_type& k) {
			node_pointer n = this->tree->find(k);
			if (n->next()) {
				return (iterator(n->next()));
			}
			else
				return this->end();
		}

		const_iterator upper_bound (const key_type& k) const {
			node_pointer n = this->tree->find(k);
			if (n->next()) {
				return (const_iterator(n->next()));
			}
			else
				return this->end();
		}

		ft::pair<const_iterator,const_iterator>	equal_range (const key_type& k) const {
			const_iterator it1;
			const_iterator it2;
			node_pointer n = this->tree.find(k);
			if (n) {
				it1 = iterator(n);
				it2 = it1++;
			}
			else {
				it1 = iterator(this->tree->find_key_after(k));
				it2 = it1;
			}
			return ft::pair<const_iterator,const_iterator>(it1, it2);
		}

		ft::pair<iterator,iterator>             equal_range (const key_type& k) {
			iterator it1;
			iterator it2;
			node_pointer n = this->tree->find(k);
			if (n) {
				it2 = iterator(n);
				it1 = it2++;
			}
			else {
				it1 = iterator(this->tree->find_key_after(k));
				it2 = it1;
			}
			return ft::pair<iterator, iterator>(it1, it2);
		}

		allocator_type get_allocator() const {
			return (this->allocator);
		}

		void print() {
			if (this->tree->get_root() != NULL)
				this->tree->print(this->tree->get_root(), 1);
		}

	};
}

#endif //MAP_H
