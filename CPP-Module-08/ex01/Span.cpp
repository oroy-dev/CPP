/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 01:01:01 by olivierroy        #+#    #+#             */
/*   Updated: 2024/08/11 01:19:37 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) 
{
	
}

Span::Span(Span const &src)
{
	*this = src;
}

Span	&Span::operator=(Span const &rhs)
{
	this->_N = rhs._N;
	return (*this);
}

Span::~Span() {}

/* Member Functions */

void	Span::addNumber(unsigned int number)
{
	
}

unsigned int	Span::shortestSpan(void) const
{
	
}

unsigned int	Span::longestSpan(void) const
{
	
}
