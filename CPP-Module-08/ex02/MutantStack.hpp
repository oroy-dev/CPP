/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 00:45:48 by olivierroy        #+#    #+#             */
/*   Updated: 2024/08/15 15:50:20 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <deque>
# include <list>
# include <stack>
# include <string>
# include <vector>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:

	MutantStack(void);
	MutantStack(MutantStack const &src);
	MutantStack &operator=(MutantStack const &rhs);
	~MutantStack();

	typedef	typename Container::iterator	iterator;

	iterator	begin() { return this->c.begin(); }
	iterator	end() { return this->c.end(); }

};

#include "MutantStack.tpp"

#endif
