/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:45:31 by oroy              #+#    #+#             */
/*   Updated: 2024/06/11 17:34:36 by oroy             ###   ########.fr       */
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
		_a[i] = 5;
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
T	&Array<T>::operator[](unsigned int i) const
{
	try
	{
		if (i >= _n)
			throw	InvalidIndex();
		return (_a[i]);
	}
	catch (const InvalidIndex& e)
	{
		std::cout << e.what() << std::endl;
		return (0);
	}
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (_n);
}
