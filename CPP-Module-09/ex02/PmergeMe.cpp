/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:50:37 by oroy              #+#    #+#             */
/*   Updated: 2024/09/11 17:49:36 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://github.com/decidedlyso/merge-insertion-sort?tab=readme-ov-file
// https://en.wikipedia.org/wiki/Merge-insertion_sort
// https://www.reddit.com/r/algorithms/comments/1bajgye/merge_insertion_ford_johnson/
// https://iq.opengenus.org/merge-insertion-sort/#google_vignette

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
	_groupIntoPairs(argc, argv);
	_sortEachPair();
	_recursiveSort(_pairs.size());
	// _sortPairs(0);
	_printPairs();
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	*this = src;
}

PmergeMe	&PmergeMe::operator=(PmergeMe const &rhs)
{
	// if (this != &rhs)
	// {

	// }
	(void) rhs;
	return *this;
}

PmergeMe::~PmergeMe() {}

/*	Private ====================================== */

void	PmergeMe::_groupIntoPairs(int argc, char **argv)
{
	std::istringstream	iss;

	for (int i = 1; i < argc; ++i)
	{
		iss.str (argv[i]);
		while (iss.good())
		{
			std::pair<int, int>	p;

			if ((iss >> p.first).fail() || (iss >> p.second).fail())
			{
				if (!iss.eof())
				{
					std::cerr << "Error: Only positive numbers accepted" << std::endl;
					return ;
				}
				_odd = p.first;
			}
			if (p.second < 0 || p.first < 0)
			{
				std::cerr << "Error: Only positive numbers accepted" << std::endl;
				return ;
			}
			_pairs.push_back(p);
		}
	}
}

void	PmergeMe::_printPairs(void) const
{
	for (std::vector<std::pair<int, int> >::const_iterator it = _pairs.begin(); it != _pairs.end(); ++it)
	{
		std::cout << "(" << it->first << "," << it->second << ") ";
	}
	std::cout << std::endl;
}

void	PmergeMe::_recursiveSort(size_t numbersToCompare)
{
	std::pair<int, int>	tempPair;
	size_t				inc = numbersToCompare / 2;

	for (size_t i = 0; i < numbersToCompare; i += inc)
	{
		if (_pairs.at(i).second > _pairs.at(i + 1).second)
		{
			tempPair = _pairs[i];
			_pairs[i] = _pairs[i + 1];
			_pairs[i + 1] = tempPair;
		}
	}
	if (numbersToCompare > 1)
	{
		_recursiveSort(numbersToCompare / 2);
	}
}

void	PmergeMe::_sortEachPair(void)
{
	int	temp = 0;

	for (std::vector<std::pair<int, int> >::iterator it = _pairs.begin(); it != _pairs.end(); ++it)
	{
		if (it->second < it->first)
		{
			temp = it->first;
			it->first = it->second;
			it->second = temp;
		}
	}
}

void	PmergeMe::_sortPairs(size_t i)
{
	try
	{
		if (_pairs.at(i + 1) < _pairs.at(i))
		{
			
		}
	}
	catch (const std::out_of_range& e)
	{
		
	}
}
