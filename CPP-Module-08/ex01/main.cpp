/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 01:01:01 by olivierroy        #+#    #+#             */
/*   Updated: 2024/08/13 13:46:45 by olivierroy       ###   ########.fr       */
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
// 	std::cout << span.longestSpan() << std::endl;

// 	span.print();

// 	return (0);
// }

// int main()
// {
// 	Span sp = Span(5);

// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);

// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;

// 	return 0;
// }

// int	main(void)
// {
// 	Span	sp(20000);

// 	for (size_t i = 0; i < 20000; ++i)
// 	{
// 		sp.addNumber(i);
// 	}
	
// 	std::cout << "Shortest span = " << sp.shortestSpan() << std::endl;
// 	std::cout << "Longest span = " << sp.longestSpan() << std::endl;

// 	return (0);
// }

int	main(void)
{
	Span	sp(10000);
	Span	sp2(5000);

	for (size_t i = 0; i < 10000; ++i)
	{
		sp.addNumber(i * i);
	}

	std::cout << "Shortest span = " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span = " << sp.longestSpan() << std::endl;

	sp2.addNumberRange(sp2);

}
