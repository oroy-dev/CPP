/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 01:01:01 by olivierroy        #+#    #+#             */
/*   Updated: 2024/08/12 17:48:42 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _N(N)
{
	std::cout << GREEN << "Span class instance created" << RESET << std::endl;
	_v.reserve(_N);
}

Span::Span(Span const &src)
{
	*this = src;
}

Span	&Span::operator=(Span const &rhs)
{
	this->_N = rhs._N;
	this->_v = rhs._v;
	return (*this);
}

Span::~Span()
{
	std::cout << GREEN << "Span class instance destroyed" << RESET << std::endl;
}

/* Member Functions */

void	Span::addNumber(unsigned int number)
{
	if (_v.size() + 1 > _N)
		throw	std::length_error("Size exceeds maximum limit");
	_v.push_back(number);
}

unsigned int	Span::shortestSpan(void) const
{
	bool			first = true;
	long			range_l = 0;
	unsigned int	range_u = 0;
	size_t			v_size = _v.size();

	for (size_t	i = 0; i < v_size; ++i)
	{
		for (size_t j = 0; j < v_size; ++j)
		{
			if (j != i)
			{
				range_l = _v.at(j) - _v.at(i);
				if (first)
				{	
					range_u = std::abs(range_l);
					first = false;
					continue ;
				}
				if ((range_l = std::abs(range_l)) < range_u)
					range_u = range_l;
			}
		}
	}
	return (range_u);
}

unsigned int	Span::longestSpan(void) const
{
	bool			first = true;
	long			range_l = 0;
	unsigned int	range_u = 0;
	size_t			v_size = _v.size();

	for (size_t	i = 0; i < v_size; ++i)
	{
		for (size_t j = 0; j < v_size; ++j)
		{
			if (j != i)
			{
				range_l = _v.at(j) - _v.at(i);
				if (first)
				{
					range_u = std::abs(range_l);
					first = false;
					continue ;
				}
				if ((range_l = std::abs(range_l)) > range_u)
					range_u = range_l;
			}
		}
	}
	return (range_u);
}

void	Span::print(void) const
{
	std::cout << "============ Span print - start ============" << std::endl;
	for (std::vector<unsigned int>::const_iterator it = _v.begin(); it != _v.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	std::cout << "============ Span print - end ============" << std::endl;
}
