//
// Created by Tuan Perera on 01.01.21.
//

#ifndef LIST_ELEMENT_H
# define LIST_ELEMENT_H

namespace ft {
    template<typename T>
    class element {
        public:
    		// Variables
            T				data;
            element<T>		*next;
            element<T>		*prev;

            // Functions
            explicit element(const T &init_data) : data(init_data), next(NULL), prev(NULL) { }
            element(const element &src) : data(src.data), next(src.next), prev(src.prev) { }
            ~element() { }

            element&    operator=(const element &rhs) {
                if (this != rhs) {
                    this->data = rhs.data;
                    this->next = rhs.next;
                    this->prev = rhs.prev;
                }
                return *this;
            }

            bool        operator==(const element &rhs) {
                return (this->data == rhs.data && this->next == rhs.next && this->prev == rhs.prev);
            }

            bool        operator!=(const element &rhs) {
                return (this->data != rhs.data || this->next != rhs.next || this->prev != rhs.prev);
            }
    };
};

#endif //LIST_ELEMENT_H
