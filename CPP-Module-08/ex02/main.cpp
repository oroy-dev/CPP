/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 00:45:48 by olivierroy        #+#    #+#             */
/*   Updated: 2024/08/14 21:42:12 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <stack>

int	main(void)
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << *it << std::endl;
	std::cout << *ite << std::endl;

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	// std::stack<int> s(mstack);
	return 0;
}

// #include <iostream>
// #include <vector>

// int	main(void)
// {
// 	std::vector<int>			vect;
// 	std::vector<int>::iterator	it;
// 	std::vector<int>::iterator	ite;

// 	vect.push_back(0);
// 	vect.push_back(1);
// 	vect.push_back(2);
// 	vect.push_back(3);
// 	vect.push_back(4);

// 	it = vect.begin();
// 	ite = vect.end();

// 	std::cout << std::boolalpha << (it > ite) << std::endl;
	
// 	return (0);	
// }
