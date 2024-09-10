/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:50:37 by oroy              #+#    #+#             */
/*   Updated: 2024/09/10 16:53:36 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	PmergeMe	p(argc, argv);

	// if (argc == 1)
	// {
	// 	std::cerr << "Error: Please provide arguments" << std::endl;
	// 	return 1; 
	// }
	
	return 0;
}

// int	main(void)
// {
// 	std::string const	arg = "5 2 3 1 4 7 6";
// 	std::vector<std::pair<int, int> >	chain;
// 	std::pair<int, int>	p;
// 	size_t				i = 0;
// 	bool				firstFilled = false;
// 	bool				secondFilled = false;

// 	for (; i < arg.size(); ++i)
// 	{
// 		if (arg[i] == ' ' || arg[i] == '\t')
// 			continue ;
// 		if (!firstFilled)
// 		{
// 			p.first = arg[i] - '0';
// 			firstFilled = true;
// 			continue ;
// 		}
// 		if (!secondFilled)
// 		{
// 			p.second = arg[i] - '0';
// 			secondFilled = true;
// 		}
// 		chain.push_back(p);
// 		firstFilled = false;
// 		secondFilled = false;
// 	}
// 	if (!secondFilled)
// 	{
// 		chain.push_back(p);
// 	}

// 	std::cout << "Main Chain: ";
// 	for (std::vector<int>::const_iterator it = mainChain.begin(); it != mainChain.end(); ++it)
// 	{
// 		std::cout << *it << " ";
// 	}
// 	std::cout << std::endl;

// 	std::cout << "Pend Chain: ";
// 	for (std::vector<int>::const_iterator it = pendChain.begin(); it != pendChain.end(); ++it)
// 	{
// 		std::cout << *it << " ";
// 	}
// 	std::cout << std::endl;

// 	return 0;
// }

// int	main(void)
// {
// 	std::string const	arg = "5 2 3 1 4 7 6";
// 	std::vector<std::pair<int, int> >	chain;
// 	std::vector<int>	mainChain;
// 	std::vector<int>	pendChain;
// 	int					first;
// 	int					second;
// 	bool				firstFilled = false;
// 	bool				secondFilled = false;
// 	size_t				i = 0;

// 	for (; i < arg.size(); ++i)
// 	{
// 		if (arg[i] == ' ' || arg[i] == '\t')
// 			continue ;
// 		if (!firstFilled)
// 		{
// 			first = arg[i] - '0';
// 			firstFilled = true;
// 			continue ;
// 		}
// 		if (!secondFilled)
// 		{
// 			second = arg[i] - '0';
// 			secondFilled = true;
// 		}
// 		if (first < second)
// 		{
// 			mainChain.push_back(first);
// 			pendChain.push_back(second);
// 		}
// 		else
// 		{
// 			mainChain.push_back(second);
// 			pendChain.push_back(first);
// 		}
// 		firstFilled = false;
// 		secondFilled = false;
// 	}
// 	if (!secondFilled)
// 	{
// 		pendChain.push_back(first);
// 	}

// 	std::cout << "Main Chain: ";
// 	for (std::vector<int>::const_iterator it = mainChain.begin(); it != mainChain.end(); ++it)
// 	{
// 		std::cout << *it << " ";
// 	}
// 	std::cout << std::endl;

// 	std::cout << "Pend Chain: ";
// 	for (std::vector<int>::const_iterator it = pendChain.begin(); it != pendChain.end(); ++it)
// 	{
// 		std::cout << *it << " ";
// 	}
// 	std::cout << std::endl;

// 	return 0;
// }