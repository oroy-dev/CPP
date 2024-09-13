/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:50:37 by oroy              #+#    #+#             */
/*   Updated: 2024/09/13 14:31:47 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <iostream>
# include <sstream>
# include <stdexcept>
# include <utility>
# include <vector>

class PmergeMe
{
private:

	std::vector<int>					S;
	std::vector<int>					_pend;
	std::vector<std::pair<int, int> >	_pairs;
	std::vector<int>					_jacob;

	bool								_isOdd;
	int									_odd;

	int		_jacobsthal(int idx);

	void	_createS(void);
	void	_fillJacobsthalArray(void);
	void	_groupIntoPairs(int argc, char **argv);
	void	_insertionSort(void);
	void	_printPairs(void) const;
	void	_printS(void) const;
	void	_recurse(std::pair<int, int> p, ssize_t n);
	void	_sortEachPair(void);

public:

	PmergeMe(int argc, char **argv);
	PmergeMe(PmergeMe const &src);
	PmergeMe &operator=(PmergeMe const &rhs);
	~PmergeMe();

};

#endif
