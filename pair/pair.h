//
// Created by Tuan Perera on 13.02.21.
//

#ifndef CONTAINERS_PAIR_H
#define CONTAINERS_PAIR_H

namespace ft {
	template<class T1, class T2>
	struct pair {
	public:
		typedef	T1 first_type;
		typedef	T2 second_type;

	public:
		first_type	first;
		second_type	second;

	public:

		template<class U, class V>
		pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {}

		template<class U, class V>
		pair (pair<U,V>& pr) : first(pr.first), second(pr.second) {}

		pair (const first_type& a, const second_type& b) : first(a), second(b) {}

		~pair() {}
	};

	template <class T1, class T2>
	bool operator== (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class T1, class T2>
	bool operator!= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {
		return (lhs.first != rhs.first && lhs.second != rhs.second);
	}

	template <class T1, class T2>
	bool operator<  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {
		return (lhs.first < rhs.first && lhs.second < rhs.second);
	}

	template <class T1, class T2>
	bool operator<= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {
		return (!(rhs < lhs));
	}

	template <class T1, class T2>
	bool operator>  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {
		return (rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {
		return (!(lhs < rhs));
	}
}

#endif //CONTAINERS_PAIR_H
