/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 00:45:48 by olivierroy        #+#    #+#             */
/*   Updated: 2024/08/11 01:18:23 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span
{
private:

	std::vector<unsigned int>	_vect;

public:

	Span(unsigned int N);
	Span(Span const &src);
	Span &operator=(Span const &rhs);
	~Span();

	void			addNumber(unsigned int number);

	unsigned int	shortestSpan(void) const;
	unsigned int	longestSpan(void) const;

};

#endif
