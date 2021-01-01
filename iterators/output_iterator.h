//
// Created by Tuan Perera on 01.01.21.
//

#ifndef OUTPUT_ITERATOR_H
# define OUTPUT_ITERATOR_H
# include "iterator.h"

namespace ft {
	class output_iterator : public virtual iterator {
		reference operator*() const;
		iterator operator++(int); //postfix increment
	};
}

#endif //OUTPUT_ITERATOR_H
