/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 01:01:01 by olivierroy        #+#    #+#             */
/*   Updated: 2024/08/14 14:32:36 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N)
{
	_v.reserve(N);
}

Span::Span(Span const &src)
{
	*this = src;
}

Span	&Span::operator=(Span const &rhs)
{
	if (this != &rhs)
		this->_v = rhs._v;
	return (*this);
}

Span::~Span() {}

/* Private Functions */

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

/* Public Functions */

unsigned int	Span::shortestSpan(void) const
{
	return (_span(SHORTEST));
}

unsigned int	Span::longestSpan(void) const
{
	return (_span(LONGEST));
}

unsigned int	Span::vectorCapacity(void) const
{
	return (_v.capacity());
}

void	Span::addNumber(unsigned int number)
{
	if (_v.size() + 1 > _v.capacity())
		throw	std::length_error("addNumber error: Size exceeds maximum limit");
	_v.push_back(number);
}

void	Span::addNumberRange(Span const &sp)
{
	if (_v.capacity() - _v.size() < sp._v.size())
		throw	std::length_error("addNumberRange error: Size exceeds maximum limit");
	_v.insert(_v.begin() + _v.size(), sp._v.begin(), sp._v.end());
}

void	Span::print(void) const
{
	std::cout << std::endl;
	std::cout << "============ Span print - start ============" << std::endl;
	for (std::vector<unsigned int>::const_iterator it = _v.begin(); it != _v.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	std::cout << "============ Span print - end ============" << std::endl;
	std::cout << std::endl;
}
