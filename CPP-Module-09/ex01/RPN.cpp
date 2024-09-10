/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:01:25 by olivierroy        #+#    #+#             */
/*   Updated: 2024/09/10 10:47:47 by oroy             ###   ########.fr       */
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
				return ;
			_operate(*it);
		}
		else
		{
			std::cerr << "Error: only digits and operators accepted (0123456789+-*/)" << std::endl;
			return ;
		}
	}
	_printStack();
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

bool	RPN::_insert(double &operand)
{
	if (_stack.empty())
	{
		std::cerr << "Error: not enough numbers in stack to operate" << std::endl;
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

void	RPN::_printStack(void)
{
	while (!_stack.empty())
	{
		std::cout << _stack.top() << " ";
		_stack.pop();
	}
	std::cout << std::endl;
}
