/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 00:45:48 by olivierroy        #+#    #+#             */
/*   Updated: 2024/08/15 15:49:35 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main(void)
{
	std::cout << "---------- pdf test ----------" << std::endl;
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
		// std::cout << *ite << std::endl;

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << std::endl;
	
	std::cout << "---------- Assignment test ----------" << std::endl;
	{
		MutantStack<std::string> mstack1;
		MutantStack<std::string> mstack2;

		mstack1.push("Hello");
		mstack1.push("how");
		mstack1.push("are");
		mstack1.push("you?");

		mstack2 = mstack1;

		mstack1.pop();
		mstack1.pop();
		mstack1.pop();
		mstack1.push("World");
		
		MutantStack<std::string>::iterator it2 = mstack2.begin();

		while (it2 != mstack2.end())
		{
			std::cout << *it2 << std::endl;
			++it2;
		}
		std::cout << std::endl;

		MutantStack<std::string>::iterator it1 = mstack1.begin();
		while (it1 != mstack1.end())
		{
			std::cout << *it1 << std::endl;
			++it1;
		}
	}
	std::cout << std::endl;

	std::cout << "---------- Set container test ----------" << std::endl;
	{
		MutantStack<int, std::vector<int> >	mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();
		mstack.pop();

		std::cout << mstack.size() << std::endl;

		if (mstack.empty())
		{
			mstack.push(-1);
			mstack.push(2147483647);
		}

		MutantStack<int, std::vector<int> >::iterator it = mstack.begin();
		MutantStack<int, std::vector<int> >::iterator ite = mstack.end();

		std::cout << *it << std::endl;

		it = it + 1;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int, std::vector<int> > s(mstack);
	}
	std::cout << std::endl;
}
