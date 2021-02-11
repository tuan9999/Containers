//
// Created by Tuan Perera on 11.02.21.
//

#ifndef CONTAINERS_QUEUE_H
#define CONTAINERS_QUEUE_H
#include "vector.hpp"

namespace ft {

	template <class T, class Container = ft::vector<T> >
	class queue {
	public:
		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;

	private:
		container_type		contain;

	public:
		explicit queue (const container_type& ctnr = container_type()) {
			this->contain = ctnr;
		}

		bool empty() const {
			return this->contain.empty();
		}

		size_type size() const {
			return this->contain.size();
		}

		value_type& front() {
			return this->contain.front();
		}

		const value_type& front() const {
			return this->contain.front();
		}

		value_type& back() {
			return this->contain.back();
		}

		const value_type& back() const {
			return this->contain.back();
		}

		void push (const value_type& val) {
			this->contain.push_back(val);
		}

		void pop() {
			this->contain.erase(this->contain.begin());
		}

		template <class U, class Contain>
		friend bool operator== (const queue<U,Contain>& lhs, const queue<U,Contain>& rhs);

		template <class U, class Contain>
		friend bool operator<  (const queue<U,Contain>& lhs, const queue<U,Contain>& rhs);
	};
}

template <class T, class Container>
bool operator== (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs) {
	return (lhs.container == rhs.container);
}

template <class T, class Container>
bool operator!= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs) {
	return (!(lhs == rhs));
}

template <class T, class Container>
bool operator<  (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs) {
	return (lhs.container < rhs.container);
}

template <class T, class Container>
bool operator<= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs) {
	return (!(lhs > rhs));
}

template <class T, class Container>
bool operator>  (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs) {
	return (rhs < lhs);
}

template <class T, class Container>
bool operator>= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs) {
	return (!(lhs < rhs));
}

#endif //CONTAINERS_QUEUE_H
