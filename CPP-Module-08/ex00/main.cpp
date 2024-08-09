/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:08:48 by oroy              #+#    #+#             */
/*   Updated: 2024/08/09 16:47:11 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "easyfind.hpp"

#include <iostream>
// #include <exception>
#include <deque>
#include <list>
#include <vector>

template <typename T>
int	easyfind(T container, int entry)
{
	typename T::iterator it = std::find(container.begin(), container.end(), entry);

	for (T::iterator it = container.begin(); it != container.end(); ++it)
	{
		if (*it == entry)
			return (*it);
	}
	throw	NoOccurenceFound();
}

int	main(void)
{
	std::cout << "---------- std::list ----------" << std::endl;
	{
		std::list<int>	lst;

		lst.push_back(1);
		lst.push_back(3);
		lst.push_back(6);
		lst.push_back(127);

		try
		{
			std::cout << easyfind(lst, 127) << std::endl;
			std::cout << easyfind(lst, 42) << std::endl;
		}
		catch(int e)
		{
			std::cerr << "No occurence of " << e << "found in the list." << std::endl;
		}
	}

	std::cout << "---------- std::vector ----------" << std::endl;
	{
		std::vector<int>	vect;

		vect.push_back(42);
		vect.push_back(-1);
		vect.push_back(2147483647);
		vect.push_back(0);

		try
		{
			std::cout << easyfind(vect, 42) << std::endl;
			std::cout << easyfind(vect, 0) << std::endl;
		}
		catch(int e)
		{
			std::cerr << "No occurence of " << e << "found in the vector." << std::endl;
		}
	}

	std::cout << "---------- std::deque ----------" << std::endl;
	{
		std::deque<int>	deq;

		deq.push_back(-1);
		deq.push_back(2147483647);
		deq.push_back(0);
		deq.push_back(888);
		deq.push_back(777);
		deq.push_back(777);

		try
		{
			std::cout << easyfind(deq, 888) << std::endl;
			std::cout << easyfind(deq, 777) << std::endl;
		}
		catch(int e)
		{
			std::cerr << "No occurence of " << e << "found in the deque." << std::endl;
		}
	}

	return (0);	
}
