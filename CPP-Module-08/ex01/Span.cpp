/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 01:01:01 by olivierroy        #+#    #+#             */
/*   Updated: 2024/08/13 14:08:34 by olivierroy       ###   ########.fr       */
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

unsigned int	Span::_range(unsigned int num1, unsigned int num2) const
{
	if (num1 > num2)
		return (num1 - num2);
	else
		return (num2 - num1);
}

unsigned int	Span::_span(bool length) const
{
	bool			first = true;
	unsigned int	range_tmp = 0;
	unsigned int	range_rtn = 0;
	size_t			v_size = _v.size();

	if (v_size <= 1)
		throw	std::logic_error("No distance can be found with one number or less");
	for (size_t	i = 0; i < v_size; ++i)
	{
		for (size_t j = i + 1; j < v_size; ++j)
		{
			range_tmp = _range(_v.at(i), _v.at(j));
			if (first)
			{
				range_rtn = range_tmp;
				first = false;
				continue ;
			}
			if ((range_tmp < range_rtn && length == SHORTEST) \
			||	(range_tmp > range_rtn && length == LONGEST))
				range_rtn = range_tmp;
		}
	}
	return (range_rtn);
}

unsigned int	Span::shortestSpan(void) const
{
	return (_span(SHORTEST));
}

unsigned int	Span::longestSpan(void) const
{
	return (_span(LONGEST));
}

void	Span::addNumber(unsigned int number)
{
	if (_v.size() + 1 > _N)
		throw	std::length_error("Size exceeds maximum limit");
	_v.push_back(number);
}

void	Span::addNumberRange(Span const &sp, unsigned int count) const
{
	std::vector<unsigned int>::const_iterator	position = _v.begin() + _v.size();
	std::vector<unsigned int>::const_iterator	sp_begin = _v.begin();
	std::vector<unsigned int>::const_iterator	sp_end = _v.begin();

	if (_v.capacity() - _v.size() < count)
		throw	std::length_error("Size exceeds maximum limit");
	_v.insert(position, )
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
