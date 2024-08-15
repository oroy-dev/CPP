/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 01:01:01 by olivierroy        #+#    #+#             */
/*   Updated: 2024/08/15 16:45:13 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	std::cout << "---------- pdf test ----------" << std::endl;
	try
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << "---------- 10000 test ----------" << std::endl;
	try
	{
		Span sp(10000);

		for (size_t i = 0; i < sp.vectorCapacity(); ++i)
		{
			sp.addNumber(i);
		}

		std::cout << "Shortest span = " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span = " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << "---------- Range fill test ----------" << std::endl;
	try
	{
		Span	sp1(9);
		Span	sp2(UINT_MAX + 10);

		for (size_t i = 0; i < sp1.vectorCapacity(); ++i)
		{
			sp1.addNumber(i * i);
		}

		std::cout << "sp1 - Shortest span = " << sp1.shortestSpan() << std::endl;
		std::cout << "sp1 - Longest span = " << sp1.longestSpan() << std::endl;

		sp2.addNumberRange(sp1);
		sp2.print();

		std::cout << "sp2 - Shortest span = " << sp2.shortestSpan() << std::endl;
		std::cout << "sp2 - Longest span = " << sp2.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << "---------- Big values test ----------" << std::endl;
	try
	{
		Span	sp(-1);

		for (size_t i = 0; i < 20000; ++i)
		{
			sp.addNumber(i * i);
		}

		std::cout << "Shortest span = " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span = " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << "---------- Size Exceeded test ----------" << std::endl;
	try
	{
		Span	sp(100);

		for (size_t i = 0; i < 10000; ++i)
		{
			sp.addNumber(i * i);
		}

		std::cout << "Shortest span = " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span = " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << "---------- Assignment test ----------" << std::endl;
	try
	{
		Span	sp1(100);
		Span	sp2(100);

		for (size_t i = 0; i < sp1.vectorCapacity(); ++i)
		{
			sp1.addNumber(i);
		}

		sp2 = sp1;

		std::cout << "sp1 - Shortest span = " << sp1.shortestSpan() << std::endl;
		std::cout << "sp1 - Longest span = " << sp1.longestSpan() << std::endl;
		std::cout << "sp2 - Shortest span = " << sp2.shortestSpan() << std::endl;
		std::cout << "sp2 - Longest span = " << sp2.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << "---------- Whatever test ----------" << std::endl;
	try
	{
		Span	sp1(100);
		Span	sp2(1000);

		for (size_t i = 0; i < sp1.vectorCapacity(); ++i)
		{
			sp1.addNumber(i * i);
		}
		for (size_t i = 0; i < 11; ++i)
		{
			sp2.addNumberRange(sp1);
			std::cout << "Range added" << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << "---------- Only one number ----------" << std::endl;
	try
	{
		Span	sp(1);

		for (size_t i = 0; i < sp.vectorCapacity(); ++i)
		{
			sp.addNumber(i);
		}

		std::cout << "Shortest span = " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span = " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << "---------- Generate random numbers ----------" << std::endl;
	try
	{
		Span	sp(42);

		sp.fillWithRandomNumbers();

		std::cout << "Shortest span = " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span = " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	return (0);
}
