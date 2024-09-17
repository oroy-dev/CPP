/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:50:37 by oroy              #+#    #+#             */
/*   Updated: 2024/09/17 19:24:57 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static void	runProgram(std::string const &args, size_t count)
{
	PmergeMe<std::vector<int>, std::vector<std::pair<int, int> > >	p1("Vector");
	PmergeMe<std::deque<int>, std::deque<std::pair<int, int> > >	p2("Deque");

	p1.sort(args);
	p2.sort(args);

	std::cout << "Before: " << args << std::endl;
	std::cout << "After: " << p2.getSortedNumbers() << std::endl;
	std::cout << "Time to process a range of " << count << " elements with std::vector : ";
	std::cout << std::fixed << std::setprecision(5) << p1.getTimeDifference() << " us" << std::endl;
	std::cout << "Time to process a range of " << count << " elements with std::deque : ";
	std::cout << std::fixed << std::setprecision(5) << p2.getTimeDifference() << " us" << std::endl;

	p1.checkIfSorted();
	p2.checkIfSorted();

	std::cout << std::endl;
}

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
				return false;
			count++;
			oss << num;
			if (!iss.eof() || (i + 1) != argc)
				oss << " ";
		}
		iss.clear();
	}
	args = oss.str();
	return true;
}

int	main(int argc, char **argv)
{
	std::string	args = "";
	size_t		count = 0;

	if (argc == 1)
	{
		std::cerr << "Error: Please provide arguments" << std::endl;
		return 0;
	}
	if (!parseArgs(argc, argv, args, count))
	{
		std::cerr << "Error: Please enter positive integers only" << std::endl;
		return 0;
	}
	if (count < 2)
	{
		std::cerr << "Error: Please enter at least 2 numbers" << std::endl;
		return 0;
	}
	runProgram(args, count);
	return 0;
}
