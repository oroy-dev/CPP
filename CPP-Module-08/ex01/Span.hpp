/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 00:45:48 by olivierroy        #+#    #+#             */
/*   Updated: 2024/08/13 00:16:29 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <stdexcept>
# include <vector>

# define GREEN 		"\033[32m"
# define RESET		"\033[0m"

# define SHORTEST	0
# define LONGEST	1

class Span
{
private:

	std::vector<unsigned int>	_v;
	unsigned int				_N;

	unsigned int				_range(unsigned int num1, unsigned int num2) const;
	unsigned int				_span(bool length) const;


public:

	Span(unsigned int N);
	Span(Span const &src);
	Span &operator=(Span const &rhs);
	~Span();

	unsigned int	shortestSpan(void) const;
	unsigned int	longestSpan(void) const;

	void			addNumber(unsigned int number);
	void			addNumberRange(std::vector<unsigned int>::const_iterator position, std::vector<unsigned int>::const_iterator first, std::vector<unsigned int>::const_iterator last) const;
	void			print(void) const;

};

#endif
