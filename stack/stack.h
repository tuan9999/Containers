//
// Created by Tuan Perera on 11.02.21.
//

#ifndef CONTAINERS_STACK_H
#define CONTAINERS_STACK_H
#include "vector.hpp"

namespace ft {
	template <class T, class Container = vector<T> >
	class stack {
	public:
		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;

	private:
		container_type		contain;

	public:
		explicit stack (const container_type& ctnr = container_type()) {
			this->contain = ctnr;
		}

		bool empty() const {
			return this->contain.empty();
		}

		size_type size() const {
			return this->contain.size();
		}

		value_type& top() {
			return this->contain.back();
		}

		const value_type& top() const {
			return this->contain.front();
		}

		void push (const value_type& val) {
			this->contain.push_back(val);
		}

		void pop() {
			this->contain.erase(this->contain.end()-1);
		}

		template <class U, class Contain>
		friend bool operator== (const stack<U,Contain>& lhs, const stack<U,Contain>& rhs);

		template <class U, class Contain>
		friend bool operator< (const stack<U,Contain>& lhs, const stack<U,Contain>& rhs);
	};

	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.contain == rhs.contain);
	}

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (!(lhs == rhs));
	}

	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.contain < rhs.contain);
	}

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (!(lhs > rhs));
	}

	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (rhs < lhs);
	}

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (!(lhs < rhs));
	}

}

#endif //CONTAINERS_STACK_H
