/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:01:25 by olivierroy        #+#    #+#             */
/*   Updated: 2024/08/21 16:08:29 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string const &arg)
{
	
}

RPN::RPN(RPN const &src)
{
	*this = src;
}

RPN	&RPN::operator=(RPN const &rhs)
{
	if (this != &rhs)
	{
		
	}
	return *this;
}

RPN::~RPN() {}

/* Functions */

