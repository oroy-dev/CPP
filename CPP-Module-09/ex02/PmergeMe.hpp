/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:50:37 by oroy              #+#    #+#             */
/*   Updated: 2024/09/16 17:33:34 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
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

	std::string							_unsortedNumbers;

	std::vector<std::pair<int, int > >	_merge(std::vector<std::pair<int, int > > const &left, std::vector<std::pair<int, int > > const &right);
	std::vector<std::pair<int, int > >	_mergeSort(size_t lowIndex, size_t highIndex, std::vector<std::pair<int, int> > const &pairs);
	void								_initSequences(std::vector<int> &main, std::vector<int> &pend, std::vector<std::pair<int, int > > const &pairs) const;
	void								_makePairs(std::vector<std::pair<int, int> > &pairs, bool &isOdd, int &straggler);
	void								_sortMainSequence(std::vector<int> &main, std::vector<int> const &pend);
	void								_sortNumbers(void);
	void								_swapNumbers(std::vector<std::pair<int, int> > &pairs);

	std::vector<int>					_createJacobSequence(std::vector<int> const &pend) const;
	size_t								_jacobsthal(unsigned int n) const;

	void								_printResult(std::vector<int> const &main, double time) const;

	// std::vector<int>					S;
	// std::vector<int>					_pend;
	// std::vector<std::pair<int, int> >	_pairs;
	// std::vector<int>					_jacob;

	// bool								_isOdd;
	// int									_odd;

	// int		_jacobsthal(int idx);

	// void	_createS(void);
	// void	_fillJacobsthalArray(void);
	// void	_groupIntoPairs(int argc, char **argv);
	// void	_insertionSort(void);
	// void	_printPairs(void) const;
	// void	_printS(void) const;
	// void	_recurse(std::pair<int, int> p, ssize_t n);
	// void	_sortEachPair(void);

public:

	PmergeMe(void);
	PmergeMe(PmergeMe const &src);
	PmergeMe &operator=(PmergeMe const &rhs);
	~PmergeMe();

	bool	parseArgs(int argc, char **argv);
	void	start(void);

};

#endif
