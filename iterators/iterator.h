//
// Created by Tuan Perera on 01.01.21.
//

#ifndef ITERATOR_H
# define ITERATOR_H

namespace ft {
	class iterator {
		public:
			iterator(const iterator&) { }
			~iterator() { }
			iterator& operator=(const iterator&);
			iterator& operator++(); //prefix increment
			reference operator*() const;
	};
}

#endif //ITERATOR_H
