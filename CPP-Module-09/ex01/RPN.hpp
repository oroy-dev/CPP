/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:01:25 by olivierroy        #+#    #+#             */
/*   Updated: 2024/09/10 10:50:02 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>

class RPN
{
private:

	std::stack<double>	_stack;
	double				_left;
	double				_right;

	bool				_insert(double &operand);
	void				_operate(char sign);
	void				_printStack(void);

public:

	RPN(std::string const &arg);
	RPN(RPN const &src);
	RPN &operator=(RPN const &rhs);
	~RPN();

};

#endif
