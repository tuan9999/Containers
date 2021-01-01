//
// Created by Tuan Perera on 01.01.21.
//

#ifndef RANDOM_ACCESS_ITERATOR_H
# define RANDOM_ACCESS_ITERATOR_H
# include "bidirectional_iterator.h"

namespace ft {
	class random_access_iterator : bidirectional_iterator {
		friend bool operator<(const iterator&, const iterator&);
		friend bool operator>(const iterator&, const iterator&);
		friend bool operator<=(const iterator&, const iterator&);
		friend bool operator>=(const iterator&, const iterator&);

		iterator& operator+=(size_type);
		friend iterator operator+(const iterator&, size_type);
		friend iterator operator+(size_type, const iterator&);
		iterator& operator-=(size_type);
		friend iterator operator-(const iterator&, size_type);
		friend difference_type operator-(iterator, iterator);

		reference operator[](size_type) const;
	};
}

#endif //RANDOM_ACCESS_ITERATOR_H
