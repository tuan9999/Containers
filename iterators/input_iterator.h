//
// Created by Tuan Perera on 01.01.21.
//

#ifndef INPUT_ITERATOR_H
# define INPUT_ITERATOR_H
# include "iterator.h"

namespace ft {
	class input_iterator : public virtual iterator {
		iterator operator++(int); //postfix increment
		value_type operator*() const;
		pointer operator->() const;
		friend bool operator==(const iterator&, const iterator&);
		friend bool operator!=(const iterator&, const iterator&);
	};
}

#endif //INPUT_ITERATOR_H
