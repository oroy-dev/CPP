/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 22:27:21 by olivierroy        #+#    #+#             */
/*   Updated: 2024/08/15 00:28:18 by olivierroy       ###   ########.fr       */
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
		this->c = rhs.c;
	}
	return (*this);
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack(void) {}
