//
// Created by Tuan Perera on 28.01.21.
//

#ifndef MAP_H
#define MAP_H
#include "map_node.h"

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

	};
}

#endif //MAP_H
