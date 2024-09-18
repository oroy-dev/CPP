/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:50:37 by oroy              #+#    #+#             */
/*   Updated: 2024/09/17 22:23:59 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename Container, typename ContainerPair>
PmergeMe<Container, ContainerPair>::PmergeMe(std::string const &type) : _type(type),
_initialNumbers(""), _sortedNumbers(""), _timeDifference(0.0) {}

template <typename Container, typename ContainerPair>
PmergeMe<Container, ContainerPair>::PmergeMe(PmergeMe const &src)
{
	*this = src;
}

template <typename Container, typename ContainerPair>
PmergeMe<Container, ContainerPair>	&PmergeMe<Container, ContainerPair>::operator=(PmergeMe const &rhs)
{
	if (this != &rhs)
	{
		_initialNumbers = rhs._initialNumbers;
		_sortedNumbers = rhs._sortedNumbers;
		_timeDifference = rhs._timeDifference;
	}
	return *this;
}

template <typename Container, typename ContainerPair>
PmergeMe<Container, ContainerPair>::~PmergeMe() {}

/*	Private ====================================== */

template <typename Container, typename ContainerPair>
size_t	PmergeMe<Container, ContainerPair>::_jacobsthal(unsigned int n) const
{
	if (n == 0 || n == 1)
		return n;
	return _jacobsthal(n - 1) + (_jacobsthal(n - 2) * 2);
}

template <typename Container, typename ContainerPair>
Container	PmergeMe<Container, ContainerPair>::_createJacobSequence(Container const &pend) const
{
	Container	jacobSequence;
	int			jacobIndex = 3;
	size_t		len = pend.size();

	while (_jacobsthal(jacobIndex) < len - 1)
	{
		jacobSequence.push_back(_jacobsthal(jacobIndex));
		jacobIndex++;
	}
	return jacobSequence;
}

template <typename Container, typename ContainerPair>
void	PmergeMe<Container, ContainerPair>::_sortMainSequence(Container &main, Container const &pend)
{
	bool		useJacob = true;
	Container	indexSequence;
	Container	jacobSequence;
	int			num = 0;
	int			it = 1;
	size_t		len = pend.size();

	indexSequence.push_back(1);
	jacobSequence = _createJacobSequence(pend);
	for (size_t i = 1; i < len; ++i)
	{
		if (jacobSequence.size() && useJacob)
		{
			indexSequence.push_back(jacobSequence[0]);
			num = pend[jacobSequence[0] - 1];
			jacobSequence.erase(jacobSequence.begin());
			useJacob = false;
		}
		else
		{
			if (std::find(indexSequence.begin(), indexSequence.end(), it) != indexSequence.end())
				++it;
			indexSequence.push_back(it);
			num = pend[it - 1];
			if (++it == indexSequence.back())
				useJacob = true;
		}
		main.insert(std::lower_bound(main.begin(), main.end(), num), num);
	}
}

template <typename Container, typename ContainerPair>
void	PmergeMe<Container, ContainerPair>::_initSequences(Container &main, Container &pend, ContainerPair const &pairs) const
{
	for (iteratorConstPair it = pairs.begin(); it != pairs.end(); ++it)
	{
		main.push_back(it->second);
		pend.push_back(it->first);
	}
}

template <typename Container, typename ContainerPair>
ContainerPair	PmergeMe<Container, ContainerPair>::_merge(ContainerPair const &left, ContainerPair const &right) const
{
	ContainerPair	sortedList;
	size_t			l = 0;
	size_t			r = 0;

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

template <typename Container, typename ContainerPair>
ContainerPair	PmergeMe<Container, ContainerPair>::_mergeSort(size_t lowIndex, size_t highIndex, ContainerPair const &pairs)
{
	ContainerPair	left;
	ContainerPair	right;
	size_t			middle;
	
	if (lowIndex == highIndex)
	{
		ContainerPair remaining;
		remaining.push_back(pairs[lowIndex]);
		return remaining;
	}
	middle = (lowIndex + highIndex) / 2;
	left = _mergeSort(lowIndex, middle, pairs);
	right = _mergeSort(middle + 1, highIndex, pairs);
	return _merge(left, right);
}

template <typename Container, typename ContainerPair>
void	PmergeMe<Container, ContainerPair>::_swapNumbers(ContainerPair &pairs)
{
	int	tmp = 0;

	for (iteratorPair it = pairs.begin(); it != pairs.end(); ++it)
	{
		if (it->first > it->second)
		{
			tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
	}
}

template <typename Container, typename ContainerPair>
void	PmergeMe<Container, ContainerPair>::_makePairs(ContainerPair &pairs, bool &isOdd, int &straggler)
{
	std::istringstream	iss(_initialNumbers);
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

template <typename Container, typename ContainerPair>
Container	PmergeMe<Container, ContainerPair>::_sortNumbers(void)
{
	ContainerPair	pairs;
	Container		main;
	Container		pend;
	int				straggler = 0;
	bool			isOdd = false;

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
	if (pend.size() > 1)
		_sortMainSequence(main, pend);
	if (isOdd)
		main.insert(std::lower_bound(main.begin(), main.end(), straggler), straggler);
	return main;
}

/*	Setters ====================================== */

template <typename Container, typename ContainerPair>
void	PmergeMe<Container, ContainerPair>::_setInitialNumbers(std::string const &args)
{
	_initialNumbers = args;
}

template <typename Container, typename ContainerPair>
void	PmergeMe<Container, ContainerPair>::_setSortedNumbers(Container sequence)
{
	std::ostringstream	oss;

	for (iteratorConst it = sequence.begin(); it != sequence.end(); ++it)
	{
		oss << *it;
		if ((it + 1) != sequence.end())
			oss << " ";
	}
	_sortedNumbers = oss.str();
}

template <typename Container, typename ContainerPair>
void	PmergeMe<Container, ContainerPair>::_setTimeDifference(struct timeval start, struct timeval end)
{
	_timeDifference = end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec) / static_cast<double>(1000000);
}

/*	Getters ====================================== */

template <typename Container, typename ContainerPair>
std::string	const	&PmergeMe<Container, ContainerPair>::getInitialNumbers(void) const
{
	return _initialNumbers;
}

template <typename Container, typename ContainerPair>
std::string	const	&PmergeMe<Container, ContainerPair>::getSortedNumbers(void) const
{
	return _sortedNumbers;
}

template <typename Container, typename ContainerPair>
double	PmergeMe<Container, ContainerPair>::getTimeDifference(void) const
{
	return _timeDifference;
}

/*	Utils ====================================== */

template <typename Container, typename ContainerPair>
void	PmergeMe<Container, ContainerPair>::checkIfSorted(void) const
{
	for (std::string::const_iterator it = _sortedNumbers.begin(); it != _sortedNumbers.end(); ++it)
	{
		if ((it + 1) != _sortedNumbers.end() && it > (it + 1))
		{
			std::cout << _type << ": " << RED << "Not Sorted" << RESET << std::endl;
			return ;
		}
	}
	std::cout << _type << ": " << GREEN << "Sorted" << RESET << std::endl;
}

/*	Start ====================================== */

template <typename Container, typename ContainerPair>
void	PmergeMe<Container, ContainerPair>::sort(std::string const &args)
{
	struct timeval 	start;
	struct timeval 	end;

	_setInitialNumbers(args);
	gettimeofday(&start, NULL);
	_setSortedNumbers(_sortNumbers());
	gettimeofday(&end, NULL);
	_setTimeDifference(start, end);
}
