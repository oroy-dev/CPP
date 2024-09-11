/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:50:37 by oroy              #+#    #+#             */
/*   Updated: 2024/09/11 17:36:24 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <stdexcept>
# include <utility>
# include <vector>

class PmergeMe
{
private:

	std::vector<std::pair<int, int> >	_pairs;
	int									_odd;

	void	_groupIntoPairs(int argc, char **argv);
	void	_printPairs(void) const;
	void	_recursiveSort(size_t numbersToCompare);
	void	_sortEachPair(void);
	void	_sortPairs(size_t i);

public:

	PmergeMe(int argc, char **argv);
	PmergeMe(PmergeMe const &src);
	PmergeMe &operator=(PmergeMe const &rhs);
	~PmergeMe();

};

#endif
