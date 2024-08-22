/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:01:25 by olivierroy        #+#    #+#             */
/*   Updated: 2024/08/22 17:03:34 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string const &arg) : _left(0), _right(0)
{
	for (std::string::const_iterator it = arg.begin(); it != arg.end(); ++it)
	{
		if (*it == ' ' || *it == '\t')
			continue ;
		else if (*it >= '0' && *it <= '9')
			_stack.push((*it - '0'));
		else if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
		{
			if (!_insert(_right) || !_insert(_left))
				break ;
			_operate(*it);
		}
		else
		{
			std::cerr << "Error: only digits and operators accepted (0123456789+-*/)" << std::endl;
			return ;
		}
	}
	printResult();
}

RPN::RPN(RPN const &src)
{
	*this = src;
}

RPN	&RPN::operator=(RPN const &rhs)
{
	if (this != &rhs)
	{
		_stack = rhs._stack;
	}
	return *this;
}

RPN::~RPN() {}

/* Private */

bool	RPN::_insert(int &operand)
{
	if (_stack.empty())
	{
		std::cerr << "Error: no numbers in stack" << std::endl;
		return false;
	}
	operand = _stack.top();
	_stack.pop();
	return true;
}

void	RPN::_operate(char sign)
{
	switch (sign)
	{
		case '+': _stack.push(_left + _right); break;
		case '-': _stack.push(_left - _right); break;
		case '*': _stack.push(_left * _right); break;
		case '/': _stack.push(_left / _right); break;
	}
}

/* Public */

void	RPN::printResult(void) const
{
	if (_stack.size() != 1)
		std::cerr << "Error: Stack size must be exactly 1 at the end" << std::endl;	
	else
		std::cout << _stack.top() << std::endl;
}
