//
// Created by Tuan Perera on 01.01.21.
//

#ifndef BIDIRECTIONAL_ITERATOR_H
# define BIDIRECTIONAL_ITERATOR_H
# include "forward_iterator.h"

namespace ft {
	class bidirectional_iterator : forward_iterator {
		iterator& operator--(); //prefix decrement
		iterator operator--(int); //postfix decrement
	};
}

#endif //BIDIRECTIONAL_ITERATOR_H
