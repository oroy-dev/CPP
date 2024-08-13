/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 00:45:48 by olivierroy        #+#    #+#             */
/*   Updated: 2024/08/13 19:43:19 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <deque>
# include <list>
# include <vector>

template <typename T>
class MutantStack
{
private:

	std::deque<T>	_d;

public:

	MutantStack(void);
	MutantStack(MutantStack const &src);
	MutantStack &operator=(MutantStack const &rhs);
	~MutantStack();

	bool		empty(void) const;
	size_t		size(void) const;
	T const &	top(void) const;

	void		pop();
	void		push(T const &);

};

#endif
