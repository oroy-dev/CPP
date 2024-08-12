/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 00:45:48 by olivierroy        #+#    #+#             */
/*   Updated: 2024/08/12 17:39:28 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <stdexcept>

# define GREEN 	"\033[32m"
# define RESET	"\033[0m"

class Span
{
private:

	std::vector<unsigned int>	_v;
	unsigned int				_N;

public:

	Span(unsigned int N);
	Span(Span const &src);
	Span &operator=(Span const &rhs);
	~Span();

	unsigned int	shortestSpan(void) const;
	unsigned int	longestSpan(void) const;

	void			addNumber(unsigned int number);
	void			print(void) const;

};

#endif
