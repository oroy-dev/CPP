/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:50:37 by oroy              #+#    #+#             */
/*   Updated: 2024/09/12 16:51:04 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://github.com/decidedlyso/merge-insertion-sort?tab=readme-ov-file
// https://en.wikipedia.org/wiki/Merge-insertion_sort
// https://www.reddit.com/r/algorithms/comments/1bajgye/merge_insertion_ford_johnson/
// https://iq.opengenus.org/merge-insertion-sort/#google_vignette
// https://github.com/PunkChameleon/ford-johnson-merge-insertion-sort

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
	_groupIntoPairs(argc, argv);
	_sortEachPair();
	_insertionSort();
	_createS();
	// _printPairs();
	_printS();
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

void	PmergeMe::_createS(void)
{
	for (std::vector<std::pair<int, int> >::const_iterator it = _pairs.begin(); it != _pairs.end(); ++it)
	{
		S.push_back(it->second);
		_pend.push_back(it->first);
	}
	S.insert(S.begin(), _pend[0]);
	_fillJacobsthalArray();
}

void	PmergeMe::_fillJacobsthalArray(void)
{
	size_t	len = _pend.size();
	size_t	jacobIndex = 3;

	while (_findJacobsthalNumber(jacobIndex) < len - 1)
	{
		_jacob.push_back(_findJacobsthalNumber(jacobIndex));
		jacobIndex++;
	}
}

int	PmergeMe::_findJacobsthalNumber(int idx)
{
	// if (idx == 0 || idx == 1)
	// 	return idx;
	return _jacob.at(idx - 1) + (_jacob.at(idx - 2) * 2);
}

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
				break ;
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

void	PmergeMe::_printS(void) const
{
	for (std::vector<int>::const_iterator it = S.begin(); it != S.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::_recurse(std::pair<int, int> p, ssize_t n)
{
	if (n < 0)
		_pairs[0] = p;
	else if (p.second >= _pairs.at(n).second)
		_pairs[n + 1] = p;
	else
	{
		_pairs[n + 1] = _pairs[n];
		_recurse(p, n - 1);
	}
}

void	PmergeMe::_insertionSort(void)
{
	for (size_t i = 1; i < _pairs.size(); ++i)
	{
		_recurse(_pairs.at(i), i - 1);
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
