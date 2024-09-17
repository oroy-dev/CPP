/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:50:37 by oroy              #+#    #+#             */
/*   Updated: 2024/09/16 22:28:06 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <deque>
# include <iomanip>
# include <iostream>
# include <sstream>
# include <stdexcept>
# include <utility>
# include <vector>
# include <string>
# include <sys/time.h>

class PmergeMe
{
private:

	std::string const					_initialNumbers;
	size_t const						_numberCount;

	double								_timeToSort();
	std::vector<std::pair<int, int > >	_merge(std::vector<std::pair<int, int > > const &left, std::vector<std::pair<int, int > > const &right);
	std::vector<std::pair<int, int > >	_mergeSort(size_t lowIndex, size_t highIndex, std::vector<std::pair<int, int> > const &pairs);
	void								_initSequences(std::vector<int> &main, std::vector<int> &pend, std::vector<std::pair<int, int > > const &pairs) const;
	void								_makePairs(std::vector<std::pair<int, int> > &pairs, bool &isOdd, int &straggler);
	void								_sortMainSequence(std::vector<int> &main, std::vector<int> const &pend);
	std::vector<int>					_sortNumbers(void);
	void								_swapNumbers(std::vector<std::pair<int, int> > &pairs);

	std::vector<int>					_createJacobSequence(std::vector<int> const &pend) const;
	size_t								_jacobsthal(unsigned int n) const;

	void								_printResult(std::vector<int> const &main, double time) const;

	PmergeMe(PmergeMe const &src);
	PmergeMe &operator=(PmergeMe const &rhs);

public:

	PmergeMe(std::string const &args, size_t const &count);
	~PmergeMe();

};

#endif
