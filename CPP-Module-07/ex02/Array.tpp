/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:45:31 by oroy              #+#    #+#             */
/*   Updated: 2024/06/10 21:21:20 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

/*	Canonical Form Requirements --------------------------------------------- */

template <typename T>
Array<T>::Array(void) : _a(new T[0]), _n(0)
{
	return ;
}

template <typename T>
Array<T>::Array(unsigned int n) : _a(new T[n]), _n(n)
{
	for (unsigned int i = 0; i < _n; ++i)
		_a[i] = 0;
	return ;
}

template <typename T>
Array<T>::Array(Array<T> const &src) : _n(src._n)
{
	*this = src;
	return ;
}

template <typename T>
Array<T>	&Array<T>::operator=(Array<T> const &rhs)
{
	delete [] _a;
	_a = new T[_n];
	for (unsigned int i = 0; i < _n; ++i)
	{
		_a[i] = rhs._a[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	delete [] _a;
	return ;
}

/*	Others ------------------------------------------------------------------ */

template <typename T>
T const	&Array<T>::operator[](unsigned int i) const
{
	try
	{
		if (!_a[i])
			throw	InvalidIndex();
	}
	catch (const InvalidIndex& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (_a[i]);
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (_n);
}
