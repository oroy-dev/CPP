/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:50:37 by oroy              #+#    #+#             */
/*   Updated: 2024/09/17 19:28:19 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <deque>
# include <iomanip>
# include <iostream>
# include <sstream>
# include <utility>	//std::pair
# include <vector>
# include <string>
# include <sys/time.h>

# define GREEN 		"\033[32m"
# define RED 		"\033[31m"
# define RESET		"\033[0m"

template <typename Container, typename ContainerPair>
class PmergeMe
{
private:

	std::string	const	_type;

	std::string			_initialNumbers;
	std::string 		_sortedNumbers;
	double				_timeDifference;

	Container			_createJacobSequence(Container const &pend) const;
	Container			_sortNumbers(void);
	ContainerPair		_merge(ContainerPair const &left, ContainerPair const &right) const;
	ContainerPair		_mergeSort(size_t lowIndex, size_t highIndex, ContainerPair const &pairs);
	size_t				_jacobsthal(unsigned int n) const;
	void				_initSequences(Container &main, Container &pend, ContainerPair const &pairs) const;
	void				_makePairs(ContainerPair &pairs, bool &isOdd, int &straggler);
	void				_setInitialNumbers(std::string const &args);
	void				_setSortedNumbers(Container sequence);
	void				_setTimeDifference(struct timeval start, struct timeval end);
	void				_sortMainSequence(Container &main, Container const &pend);
	void				_swapNumbers(ContainerPair &pairs);

	typedef	typename Container::const_iterator		iteratorConst;
	typedef	typename ContainerPair::const_iterator	iteratorConstPair;
	typedef	typename ContainerPair::iterator		iteratorPair;

public:

	PmergeMe(std::string const &type);
	PmergeMe(PmergeMe const &src);
	PmergeMe &operator=(PmergeMe const &rhs);
	~PmergeMe();

	std::string const	&getInitialNumbers(void) const;
	std::string const	&getSortedNumbers(void) const;
	double				getTimeDifference(void) const;

	void				checkIfSorted(void) const;
	void				sort(std::string const &args);

};

# include "PmergeMe.tpp" 

#endif
