//
// Created by Tuan Perera on 28.01.21.
//

#ifndef MAP_H
#define MAP_H
#include "rb_tree.h"
#include "../utils/bidirectional_iterator.h"

namespace ft {
	template < class Key,                                   				// map::key_type
			class T,                                       					// map::mapped_type
			class Compare = std::less<Key>,                     			// map::key_compare
			class Allocator = std::allocator<std::pair<const Key,T> >    	// map::allocator_type
	>
	class map {
	public:
		typedef Key 									key_type;
		typedef T 										mapped_type;
		typedef std::pair<const key_type,mapped_type> 	value_type;
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

		typedef ft::rb_tree<value_type> bst;
		typedef ft::rb_tree_node<value_type> *node_pointer;
		typedef const ft::rb_tree_node<value_type> *const_node_pointer;

	private:
		bst			tree;
		size_type	t_size;

	public:
		typedef bidirectional_iterator<T, reference, pointer, node_pointer>								iterator;
		typedef bidirectional_iterator<T, const_reference, const_pointer, const_node_pointer>			const_iterator;
		typedef reverse_bidirectional_iterator<T, reference, pointer, node_pointer>						reverse_iterator;
		typedef reverse_bidirectional_iterator<T, const_reference, const_pointer, const_node_pointer>	const_reverse_iterator;

	public:
		explicit map (const key_compare& comp = key_compare(),
					  const allocator_type& alloc = allocator_type()) {
			this->tree = bst();
			this->size = 0;
		}

		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			 const key_compare& comp = key_compare(),
			 const allocator_type& alloc = allocator_type()) {

		}

		map (const map& x) {

		}

		~map() {

		}

		map& operator= (const map& x) {
			if (*this != x) {
				this->tree = x.tree;
				this->t_size = x.t_size;
			}
		}

		iterator begin() {
			return (iterator(this->tree.min_val()));
		}

		const_iterator begin() const {
			return (const_iterator(this->tree.min_val()));
		}

		iterator end() {
			return (iterator(this->tree.max_val()));
		}

		const_iterator end() const {
			return (const_iterator(this->tree.max_val()));
		}

		reverse_iterator rbegin() {
			return (reverse_iterator(this->tree.max_val()));
		}

		const_reverse_iterator rbegin() const {
			return (const_reverse_iterator(this->tree.max_val()));
		}

		reverse_iterator rend() {
			return (reverse_iterator(this->tree.min_val()));
		}

		const_reverse_iterator rend() const {
			return (const_reverse_iterator(this->tree.min_val()));
		}

		bool empty() const {
			return (this->t_size == 0);
		}

		size_type size() const {
			return (this->t_size);
		}

		size_type max_size() const {
			return (size_type(-1) / sizeof(node_pointer));
		}

		std::pair<iterator,bool> insert (const value_type& val) {

		}

		iterator insert (iterator position, const value_type& val) {

		}

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last) {

		}

		void erase (iterator position) {

		}

		size_type erase (const key_type& k) {

		}

		void erase (iterator first, iterator last) {

		}

		void swap (map& x) {

		}

		void clear() { // this probs doesnt work
			node_pointer node = this->tree.min_val();
			node_pointer tmp = NULL;
			while (node->next()) {
				tmp = node;
				node = node->next();
				delete tmp;
			}
			if (node)
				delete node;
		}

		key_compare key_comp() const {

		}

		value_compare value_comp() const {

		}

		iterator find (const key_type& k) {

		}

		const_iterator find (const key_type& k) const {

		}

		size_type count (const key_type& k) const {

		}

		iterator lower_bound (const key_type& k) {

		}

		const_iterator lower_bound (const key_type& k) const {

		}

		iterator upper_bound (const key_type& k) {

		}

		const_iterator upper_bound (const key_type& k) const {

		}

		std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const {

		}

		std::pair<iterator,iterator>             equal_range (const key_type& k) {

		}

		allocator_type get_allocator() const {

		}


	};
}

#endif //MAP_H
