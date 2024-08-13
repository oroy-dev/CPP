/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 00:45:48 by olivierroy        #+#    #+#             */
/*   Updated: 2024/08/13 18:36:57 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <climits>
# include <iostream>
# include <stdexcept>
# include <vector>

# define GREEN 		"\033[32m"
# define RED 		"\033[31m"
# define RESET		"\033[0m"

# define SHORTEST	0
# define LONGEST	1

class Span
{
private:

	std::vector<unsigned int>	_v;

	unsigned int				_range(unsigned int num1, unsigned int num2) const;
	unsigned int				_span(bool length) const;

public:

	Span(unsigned int N);
	Span(Span const &src);
	Span &operator=(Span const &rhs);
	~Span();

	unsigned int				shortestSpan(void) const;
	unsigned int				longestSpan(void) const;
	unsigned int				vectorCapacity(void) const;

	void						addNumber(unsigned int number);
	void						addNumberRange(Span const &sp);
	void						print(void) const;

};

#endif
