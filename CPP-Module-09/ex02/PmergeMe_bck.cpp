/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:50:37 by oroy              #+#    #+#             */
/*   Updated: 2024/09/16 20:46:23 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	*this = src;
}

PmergeMe	&PmergeMe::operator=(PmergeMe const &rhs)
{
	(void) rhs;
	return *this;
}

PmergeMe::~PmergeMe() {}

/*	Private ====================================== */

void	PmergeMe::_initSequences(std::vector<int> &main, std::vector<int> &pend, std::vector<std::pair<int, int > > const &pairs) const
{
	for (std::vector<std::pair<int, int > >::const_iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		main.push_back(it->second);
		pend.push_back(it->first);
	}
}

std::vector<std::pair<int, int > >	PmergeMe::_merge(std::vector<std::pair<int, int > > const &left, std::vector<std::pair<int, int > > const &right)
{
	std::vector<std::pair<int, int> >	sortedList;
	size_t								l = 0;
	size_t								r = 0;

	while (l != left.size() || r != right.size())
	{
		if (l == left.size())
			sortedList.push_back(right[r++]);
		else if (r == right.size())
			sortedList.push_back(left[l++]);
		else if (left[l].second < right[r].second)
			sortedList.push_back(left[l++]);
		else
			sortedList.push_back(right[r++]);
	}
	return sortedList;
}

std::vector<std::pair<int, int > >	PmergeMe::_mergeSort(size_t lowIndex, size_t highIndex, std::vector<std::pair<int, int> > const &pairs)
{
	std::vector<std::pair<int, int > >	left;
	std::vector<std::pair<int, int > >	right;
	size_t								middle;
	
	if (lowIndex == highIndex)
	{
		std::vector<std::pair<int, int> > remaining;
		remaining.push_back(pairs[lowIndex]);
		return remaining;
	}
	middle = (lowIndex + highIndex) / 2;
	left = _mergeSort(lowIndex, middle, pairs);
	right = _mergeSort(middle + 1, highIndex, pairs);
	return _merge(left, right);
}

void	PmergeMe::_swapNumbers(std::vector<std::pair<int, int> > &pairs)
{
	int	tmp = 0;

	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		if (it->first > it->second)
		{
			tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
	}
}

void	PmergeMe::_makePairs(std::vector<std::pair<int, int> > &pairs, bool &isOdd, int &straggler)
{
	std::istringstream	iss(_unsortedNumbers);
	std::pair<int, int>	pair;

	while (iss.good())
	{
		iss >> pair.first;
		if (iss.eof())
		{
			isOdd = true;
			straggler = pair.first;
			return ;
		}
		iss >> pair.second;
		pairs.push_back(pair);
	}
}

size_t	PmergeMe::_jacobsthal(unsigned int n) const
{
	if (n == 0 || n == 1)
		return n;
	return _jacobsthal(n - 1) + (_jacobsthal(n - 2) * 2);
}

std::vector<int>	PmergeMe::_createJacobSequence(std::vector<int> const &pend) const
{
	std::vector<int>	jacobSequence;
	int					jacobIndex = 3;
	size_t				len = pend.size();

	while (_jacobsthal(jacobIndex) < len - 1)
	{
		jacobSequence.push_back(_jacobsthal(jacobIndex));
		jacobIndex++;
	}
	return jacobSequence;
}

void	PmergeMe::_sortMainSequence(std::vector<int> &main, std::vector<int> const &pend)
{
	bool				useJacobIndex = true;
	int					num = 0;
	size_t				len = pend.size();
	std::vector<int>	indexSequence;
	std::vector<int>	jacobSequence;

	indexSequence.push_back(1);
	jacobSequence = _createJacobSequence(pend);
	for (size_t i = 0; i < len; ++i)
	{
		if (jacobSequence.size() && useJacobIndex)
		{
			indexSequence.push_back(jacobSequence[0]);
			num = pend[jacobSequence[0] - 1];
			jacobSequence.erase(jacobSequence.begin());
			useJacobIndex = false;
		}
		else
		{
			if (std::find(indexSequence.begin(), indexSequence.end(), i) != indexSequence.end())
				i++;
			num = pend[i - 1];
			indexSequence.push_back(i);
			useJacobIndex = true;
		}
		main.insert(std::lower_bound(main.begin(), main.end(), num), num);
	}
}

void	PmergeMe::_sortNumbers(void)
{
	std::vector<std::pair<int, int> >	pairs;
	std::vector<int>					main;
	std::vector<int>					pend;
	int									straggler = 0;
	bool								isOdd = false;
	struct timeval 						start;
	struct timeval 						end;

	gettimeofday(&start, NULL);
	// Step 1
	_makePairs(pairs, isOdd, straggler);
	// Step 2
	_swapNumbers(pairs);
	// Step 3
	pairs = _mergeSort(0, pairs.size() - 1, pairs);
	// Step 4
	_initSequences(main, pend, pairs);
	main.insert(main.begin(), pend[0]);
	// Step 5
	_sortMainSequence(main, pend);
	if (isOdd)
		main.insert(std::lower_bound(main.begin(), main.end(), straggler), straggler);
	gettimeofday(&end, NULL);
	_printResult(main, end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec) / static_cast<double>(1000000));
}

void	PmergeMe::_printResult(std::vector<int> const &main, double time) const
{
	std::cout << "Before: " << _unsortedNumbers << std::endl;
	std::cout << "After:";
	for (std::vector<int>::const_iterator it = main.begin(); it != main.end(); ++it)
	{
		std::cout << " " << *it;
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << main.size() << " elements with std::vector : ";
	std::cout << std::fixed << std::setprecision(5) << time << " us" << std::endl;
	// std::cout << "Time to process a range of " << main.size() << " elements with std::deque : ";
	// std::cout << "0.00014 us" << std::endl;
}

/*	Public 	====================================== */

bool	PmergeMe::parseArgs(int argc, char **argv)
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
			oss << num;
			if (!iss.eof())
				oss << " ";
		}
	}
	_unsortedNumbers = oss.str();
	return true;
}

void	PmergeMe::start(void)
{
	_sortNumbers();
}
