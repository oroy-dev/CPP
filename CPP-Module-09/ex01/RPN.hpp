/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:01:25 by olivierroy        #+#    #+#             */
/*   Updated: 2024/08/22 17:03:45 by oroy             ###   ########.fr       */
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

	std::stack<int>	_stack;
	int				_left;
	int				_right;

	bool			_insert(int &operand);
	void			_operate(char sign);

public:

	RPN(std::string const &arg);
	RPN(RPN const &src);
	RPN &operator=(RPN const &rhs);
	~RPN();

	void			printResult(void) const;

};

#endif
