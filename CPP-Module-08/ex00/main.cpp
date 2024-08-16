/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:08:48 by oroy              #+#    #+#             */
/*   Updated: 2024/08/16 13:58:04 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	std::cout << "---------- std::list ----------" << std::endl;
	{
		std::list<int>	cont;

		cont.push_back(-1);
		cont.push_back(0);
		cont.push_back(1);
		cont.push_back(-1);
		cont.push_back(2);
		cont.push_back(42);
		cont.push_back(127);
		cont.push_back(255);
		cont.push_back(2147483647);
		cont.push_back(-2147483648);

		try
		{
			easyfind(cont, 0);
			easyfind(cont, 2);
			easyfind(cont, -1);
			easyfind(cont, -1);
			easyfind(cont, 0);
			easyfind(cont, -1);
			easyfind(cont, 42);
			easyfind(cont, 2147483646);
			easyfind(cont, 2147483647);
		}
		catch(int e)
		{
			std::cerr << "No occurence found: " << e << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "---------- std::vector ----------" << std::endl;
	{
		std::vector<int>	cont;

		cont.push_back(-1);
		cont.push_back(0);
		cont.push_back(1);
		cont.push_back(-1);
		cont.push_back(2);
		cont.push_back(42);
		cont.push_back(127);
		cont.push_back(255);
		cont.push_back(2147483647);
		cont.push_back(-2147483648);

		try
		{
			easyfind(cont, 0);
			easyfind(cont, 2);
			easyfind(cont, -1);
			easyfind(cont, -1);
			easyfind(cont, 0);
			easyfind(cont, -1);
			easyfind(cont, 42);
			easyfind(cont, 2147483646);
			easyfind(cont, 2147483647);
		}
		catch(int e)
		{
			std::cerr << "No occurence found: " << e << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "---------- std::deque ----------" << std::endl;
	{
		std::deque<int>	cont;

		cont.push_back(-1);
		cont.push_back(0);
		cont.push_back(1);
		cont.push_back(-1);
		cont.push_back(2);
		cont.push_back(42);
		cont.push_back(127);
		cont.push_back(255);
		cont.push_back(2147483647);
		cont.push_back(-2147483648);

		try
		{
			easyfind(cont, 0);
			easyfind(cont, 2);
			easyfind(cont, -1);
			easyfind(cont, -1);
			easyfind(cont, 0);
			easyfind(cont, -1);
			easyfind(cont, 42);
			easyfind(cont, 2147483646);
			easyfind(cont, 2147483647);
		}
		catch(int e)
		{
			std::cerr << "No occurence found: " << e << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "---------- std::list - EMPTY ----------" << std::endl;
	{
		std::list<int>	cont;

		try
		{
			easyfind(cont, 2147483647);
		}
		catch(int e)
		{
			std::cerr << "No occurence found: " << e << std::endl;
		}
	}
	std::cout << std::endl;

	return (0);	
}
