/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:50:37 by oroy              #+#    #+#             */
/*   Updated: 2024/09/13 16:39:37 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://github.com/decidedlyso/merge-insertion-sort?tab=readme-ov-file
// https://en.wikipedia.org/wiki/Merge-insertion_sort
// https://www.reddit.com/r/algorithms/comments/1bajgye/merge_insertion_ford_johnson/
// https://iq.opengenus.org/merge-insertion-sort/#google_vignette
// https://github.com/PunkChameleon/ford-johnson-merge-insertion-sort

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv) : _isOdd(false)
{
	_groupIntoPairs(argc, argv);
	_sortEachPair();
	_insertionSort();
	_printPairs();
	_createS();
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
	bool								isJacob = false;
	std::vector<int>					idx;
	int									item;
	std::vector<int>::const_iterator	insertionPoint;

	idx.push_back(1);
	for (std::vector<std::pair<int, int> >::const_iterator it = _pairs.begin(); it != _pairs.end(); ++it)
	{
		S.push_back(it->second);
		_pend.push_back(it->first);
	}
	S.insert(S.begin(), _pend[0]);
	_fillJacobsthalArray();
	for (size_t i = 1; i <= _pend.size(); i++)
	{
		if (_jacob.size() && !isJacob)
		{
			idx.push_back(_jacob[0]);
			item = _pend[_jacob[0] - 1];
			_jacob.erase(_jacob.begin());
			isJacob = true;
		}
		else
		{
			if (std::find(idx.begin(), idx.end(), i) != idx.end())
				++i;
			item = _pend[i - 1];
			idx.push_back(i);
			isJacob = false;
		}
		insertionPoint = std::lower_bound (S.begin(), S.end(), item);
		S.insert(insertionPoint, item);
	}
	if (_isOdd)
	{
		insertionPoint = std::lower_bound (S.begin(), S.end(), _odd);
		S.insert(insertionPoint, _odd);
	}
}

void	PmergeMe::_fillJacobsthalArray(void)
{
	int	len = _pend.size();
	int	jacobIndex = 3;

	while (_jacobsthal(jacobIndex) < len - 1)
	{
		_jacob.push_back(_jacobsthal(jacobIndex));
		jacobIndex++;
	}
	for (std::vector<int>::const_iterator it = _jacob.begin(); it != _jacob.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
}

int	PmergeMe::_jacobsthal(int idx)
{
	if (idx == 0 || idx == 1)
		return idx;
	return _jacobsthal(idx - 1) + (_jacobsthal(idx - 2) * 2);
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
				_isOdd = true;
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
