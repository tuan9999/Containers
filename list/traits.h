//
// Created by Tuan Perera on 05.01.21.
//

#ifndef TRAITS_H
# define TRAITS_H

namespace ft {
	struct iterator_tag {};
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag {};
	struct bidirectional_iterator_tag {};
	struct random_access_iterator_tag {};

	template <bool, typename T = void>
	struct enable_if
	{};

	template <typename T>
	struct enable_if<true, T> {
		typedef T type;
	};

	template <bool is_iterator, typename T>
	struct iterator_result
	{
		typedef T type;
		static const bool value = is_iterator;
	};

	template <typename>
	struct iterator_check : public iterator_result<false, bool>
	{
	};

	template <>
	struct iterator_check<random_access_iterator_tag> : public iterator_result<true, random_access_iterator_tag>
	{
	};

	template <>
	struct iterator_check<bidirectional_iterator_tag> : public iterator_result<true, bidirectional_iterator_tag>
	{
	};

	template <>
	struct iterator_check<forward_iterator_tag> : public iterator_result<true, forward_iterator_tag>
	{
	};

	template <>
	struct iterator_check<input_iterator_tag> : public iterator_result<true, input_iterator_tag>
	{
	};

	template <typename T>
	struct is_iterator : public iterator_check<T>
	{
	};
}

#endif //TRAITS_H
