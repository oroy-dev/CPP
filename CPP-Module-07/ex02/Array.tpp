/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:45:31 by oroy              #+#    #+#             */
/*   Updated: 2024/08/05 21:08:28 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

/*	Canonical Form Requirements --------------------------------------------- */

template <typename T>
Array<T>::Array(void) : _a(NULL), _n(0)
{
	return ;
}

template <typename T>
Array<T>::Array(unsigned int n) : _a(new T[n]), _n(n)
{
	for (unsigned i = 0; i < _n; ++i)
	{
		_a[i] = '\0';
	}
	return ;
}

template <typename T>
Array<T>::Array(Array<T> const &src) : _a(NULL), _n(0)
{
	*this = src;
	return ;
}

template <typename T>
Array<T>	&Array<T>::operator=(Array<T> const &rhs)
{
	if (_n)
		delete [] _a;
	_n = rhs._n;
	_a = new T[_n];
	for (unsigned int i = 0; i < _n; ++i)
	{
		_a[i] = rhs._a[i];
	}
	return (*this);
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
	if (i >= _n)
		throw	InvalidIndex();
	return (_a[i]);
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (_n);
}
