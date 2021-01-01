//
// Created by Tuan Perera on 01.01.21.
//

#ifndef FORWARD_ITERATOR_H
# define FORWARD_ITERATOR_H
# include "input_iterator.h"
# include "output_iterator.h"

namespace ft {
	class forward_iterator : input_iterator, output_iterator {
		forward_iterator();
	};
}

#endif //FORWARD_ITERATOR_H
