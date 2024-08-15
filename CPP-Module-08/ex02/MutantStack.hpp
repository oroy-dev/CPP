/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 00:45:48 by olivierroy        #+#    #+#             */
/*   Updated: 2024/08/14 21:42:33 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <cstddef>
# include <iterator>
# include <iostream>
# include <deque>
# include <list>
# include <vector>

template <typename T, typename Container = std::deque<T> >
class MutantStack
{
private:

	Container	_container;

public:

	MutantStack(void);
	MutantStack(MutantStack const &src);
	MutantStack &operator=(MutantStack const &rhs);
	~MutantStack();

	bool		empty(void) const;
	size_t		size(void) const;
	T const &	top(void) const;

	void		pop(void);
	void		push(T const &);

	class iterator
	{
	private:

		T *			_ptr;

	public:

		iterator(void) : _ptr(NULL) {}
		iterator(T *ptr) : _ptr(ptr) {} 
		iterator(iterator const &src) { *this = src; }
		iterator &	operator=(iterator const &rhs) { _ptr = rhs._ptr; return *this; }
		~iterator() {}

		bool		operator==(iterator const &rhs) const { return _ptr == rhs._ptr ? true : false; }
		bool		operator!=(iterator const &rhs) const { return _ptr != rhs._ptr ? true : false; }
		bool		operator<(iterator const &rhs) const { return _ptr < rhs._ptr ? true : false; }
		bool		operator>(iterator const &rhs) const { return _ptr > rhs._ptr ? true : false; }
		bool		operator<=(iterator const &rhs) const { return _ptr <= rhs._ptr ? true : false; }
		bool		operator>=(iterator const &rhs) const { return _ptr >= rhs._ptr ? true : false; }

		T &			operator*() const { return *_ptr; }
		T *			operator->() const { return _ptr; }
		T &			operator[](std::ptrdiff_t n) const { return *(_ptr + n); }

		iterator &	operator++()
		{
			++_ptr;
			return *this;
		}
		
		iterator	operator++(int)
		{
			iterator temp = *this;
			++_ptr;
			return temp;
		}

		iterator &	operator--()
		{
			--_ptr;
			return *this;
		}
		
		iterator	operator--(int)
		{
			iterator temp = *this;
			--_ptr;
			return temp;
		}

		iterator &	operator+=(std::ptrdiff_t n)
		{
			_ptr += n;
			return *this;
		}

		iterator &	operator-=(std::ptrdiff_t n)
		{
			_ptr -= n;
			return *this;
		}

		iterator	operator+(std::ptrdiff_t n) const
		{
			iterator temp = *this;

			return temp += n;
		}

		// static iterator	operator+(std::ptrdiff_t n, iterator const &rhs) const
		// {
		// 	return n + rhs._ptr;
		// }

		iterator	operator-(std::ptrdiff_t n) const
		{
			iterator temp = *this;

			return temp -= n;
		}

		std::ptrdiff_t	operator-(iterator const &rhs) const
		{
			return _ptr - rhs._ptr;
		}
	};

	iterator	begin() { return iterator(&_container[0]); }
	iterator	end() { return iterator(&_container[_container.size()]); }

};

#include "MutantStack.tpp"

#endif
