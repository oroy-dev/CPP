/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:50:37 by oroy              #+#    #+#             */
/*   Updated: 2024/09/16 21:45:49 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static bool	parseArgs(int argc, char **argv, std::string &args, size_t &count)
{
	std::istringstream	iss;
	std::ostringstream	oss;
	long				num;

	for (int i = 1; i < argc; ++i)
	{
		iss.str (argv[i]);
		while (iss.good())
		{
			if ((iss >> num).fail() || num < 0 || num > 2147483647)
			{
				std::cerr << "Error: Please enter positive integers only" << std::endl;
				return false;
			}
			count++;
			oss << num;
			if (!iss.eof())
				oss << " ";
		}
	}
	args = oss.str();
	return true;
}

int	main(int argc, char **argv)
{
	std::string	args = "";
	size_t		count = 0;
	PmergeMe	*p;

	if (argc == 1)
	{
		std::cerr << "Error: Please provide arguments" << std::endl;
		return 1;
	}
	if (!parseArgs(argc, argv, args, count))
		return 1;
	p = new PmergeMe(args, count);
	delete p;
	return 0;
}
