//
// Created by Tuan Perera on 17.01.21.
//

#ifndef RANDOM_ACCESS_ITERATOR_H
#define RANDOM_ACCESS_ITERATOR_H

namespace ft {
	template<typename T, typename R, typename P>
	class random_access_iterator {
	public:
		typedef P							pointer;
		typedef R							reference;
		typedef size_t						size_type;
		typedef random_access_iterator_tag 	iterator_category;

	private:
		pointer								array;

	public:
		// Functions
		random_access_iterator(pointer arr = NULL) : array(arr) { }
		random_access_iterator(const random_access_iterator& src) : array(src.array) {}
		~random_access_iterator() { }

		random_access_iterator& operator=(const random_access_iterator& rhs) {
			if (*this != rhs) {
				this->array = rhs.array;
			}
			return *this;
		}

		reference operator*() {
			return *this->array;
		}

		pointer operator->() {
			return &(this->array);
		}

		bool operator!=(const random_access_iterator &rhs) {
			return this->array != rhs.array;
		}

		bool operator==(const random_access_iterator &rhs) {
			return this->array == rhs.array;
		}

		random_access_iterator operator++() {
			this->array++;
			return *this;
		}

		random_access_iterator operator++(int) {
			random_access_iterator<T, R, P> out(*this);
			this->array++;
			return out;
		}

		random_access_iterator operator--() {
			this->array--;
			return *this;
		}

		random_access_iterator operator--(int) {
			random_access_iterator<T, R, P> out(*this);
			this->array--;
			return out;
		}

		random_access_iterator& operator+=(size_type n) {
			this->array += n;
			return *this;
		}

		random_access_iterator operator+(size_type n) {
			random_access_iterator<T, R, P> out(*this);
			out.array += n;
			return out;
		}

		random_access_iterator& operator-=(size_type n) {
			this->array -= n;
			return *this;
		}

		random_access_iterator operator-(size_type n) {
			random_access_iterator<T, R, P> out(*this);
			out.array -= n;
			return out;
		}

		reference operator[](size_type n) const {
			return this->array[n];
		}
	};

	template<typename T, typename R, typename P>
	class reverse_random_access_iterator {
	public:
		typedef P							pointer;
		typedef R							reference;
		typedef size_t						size_type;
		typedef random_access_iterator_tag 	iterator_category;

	private:
		pointer								array;

	public:
		// Functions
		reverse_random_access_iterator(pointer arr = NULL) : array(arr) { }
		reverse_random_access_iterator(const reverse_random_access_iterator& src) : array(src.array) {}
		~reverse_random_access_iterator() { }

		reverse_random_access_iterator& operator=(const reverse_random_access_iterator& rhs) {
			if (*this != rhs) {
				this->array = rhs.array;
			}
			return *this;
		}

		reference operator*() {
			return *this->array;
		}

		pointer operator->() {
			return &(this->array);
		}

		bool operator!=(const reverse_random_access_iterator &rhs) {
			return this->array != rhs.array;
		}

		bool operator==(const reverse_random_access_iterator &rhs) {
			return this->array == rhs.array;
		}

		reverse_random_access_iterator operator++() {
			this->array--;
			return *this;
		}

		reverse_random_access_iterator operator++(int) {
			reverse_random_access_iterator<T, R, P> out(*this);
			this->array--;
			return out;
		}

		reverse_random_access_iterator operator--() {
			this->array++;
			return *this;
		}

		reverse_random_access_iterator operator--(int) {
			reverse_random_access_iterator<T, R, P> out(*this);
			this->array++;
			return out;
		}

		reverse_random_access_iterator& operator+=(size_type n) {
			this->array -= n;
			return *this;
		}

		reverse_random_access_iterator operator+(size_type n) {
			reverse_random_access_iterator<T, R, P> out(*this);
			out.array -= n;
			return out;
		}

		reverse_random_access_iterator& operator-=(size_type n) {
			this->array += n;
			return *this;
		}

		reverse_random_access_iterator operator-(size_type n) {
			reverse_random_access_iterator<T, R, P> out(*this);
			out.array += n;
			return out;
		}

		reference operator[](size_type n) const {
			return this->array[n];
		}
	};
}

#endif //RANDOM_ACCESS_ITERATOR_H
