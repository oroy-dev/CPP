/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 22:27:21 by olivierroy        #+#    #+#             */
/*   Updated: 2024/08/14 14:33:06 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(void) {}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(MutantStack<T, Container> const &src)
{
	*this = src;
}

template <typename T, typename Container>
MutantStack<T, Container>	&MutantStack<T, Container>::operator=(MutantStack<T, Container> const &rhs)
{
	if (this != &rhs)
	{
		this->_container = rhs._container;
	}
	return (*this);
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack(void) {}

/* Member functions */

template <typename T, typename Container>
bool	MutantStack<T, Container>::empty(void) const
{
	return (_container.empty());
}

template <typename T, typename Container>
size_t	MutantStack<T, Container>::size(void) const
{
	return (_container.size());	
}

template <typename T, typename Container>
T const &	MutantStack<T, Container>::top(void) const
{
	return (_container.back());
}

template <typename T, typename Container>
void	MutantStack<T, Container>::pop(void)
{
	_container.pop_back();
}

template <typename T, typename Container>
void	MutantStack<T, Container>::push(T const &number)
{
	_container.push_back(number);
}
