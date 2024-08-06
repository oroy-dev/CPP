/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:08:48 by oroy              #+#    #+#             */
/*   Updated: 2024/08/06 13:38:12 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "easyfind.hpp"

#include <iostream>
#include <exception>
#include <deque>
#include <list>
#include <vector>

class	NoOccurenceFound : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("No Occurence Found");
		}
};

template <typename T>
int	easyfind(T container, int entry)
{
	size_t	len = container.size();

	for (size_t i = 0; i < len; ++i)
	{
		if (*it == data)
			return (*it);
	}
	throw	NoOccurenceFound();
}

int	main(void)
{
	std::list<int>	lst;

	lst.push_back(1);
	lst.push_back(3);
	lst.push_back(6);
	lst.push_back(127);

	try
	{
		std::cout << easyfind(lst, 42) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);	
}
