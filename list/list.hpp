/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/17 16:48:28 by tuperera      #+#    #+#                 */
/*   Updated: 2020/12/17 17:25:25 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <memory>

namespace ft {
	template<class T, class Allocator = std::allocator<T>>
	class list {
		private:
			T										value_type;
			Allocator								allocator_type;
			std::size_t								size_type;
			std::ptrdiff_t							difference_type
			Allocator::reference					reference
			Allocator::const_reference				const_reference;
			Allocator::pointer						pointer;
			Allocator::const_pointer				const_pointer;
			std::iterator							iterator;
			std::const_iterator						const_iterator;
			std::reverse_iterator<iterator>			reverse_iterator
			std::reverse_iterator<const_iterator>	const_reverse_iterator;

		public:
			explicit list (const allocator_type& alloc = allocator_type()) {
				
			}
			explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			
			template <class InputIterator>
  			list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
			list (const list& x);
			~list();
			list&	operatior=(const list& rhs);
			
			iterator begin();
			const_iterator begin() const;
			iterator end();
			const_iterator end() const;

	};
}