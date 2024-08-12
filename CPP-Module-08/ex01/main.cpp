/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 01:01:01 by olivierroy        #+#    #+#             */
/*   Updated: 2024/08/12 17:40:42 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// int	main(void)
// {
// 	Span	span(3);

// 	span.addNumber(8);
// 	span.addNumber(-1);
// 	span.addNumber(24);

// 	std::cout << span.shortestSpan() << std::endl;
// 	std::cout << span.shortestSpan() << std::endl;

// 	span.print();

// 	return (0);
// }

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return 0;
}
