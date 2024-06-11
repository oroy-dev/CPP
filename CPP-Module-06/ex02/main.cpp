/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:02:49 by oroy              #+#    #+#             */
/*   Updated: 2024/06/10 16:47:48 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

static Base	*generate(void)
{
	Base	*inst;

	switch (std::rand() % 3)
	{
		case 0: inst = new A(); break;
		case 1: inst = new B(); break;
		case 2: inst = new C(); break;
	}
	return (inst);
}

static void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

static void	identify(Base &p)
{
	A	a;
	B	b;
	C	c;

	for (int i = 0; i < 3; i++)
	{
		try
		{
			switch (i)
			{
				case 0: a = dynamic_cast<A &>(p); std::cout << "A"; break;
				case 1: b = dynamic_cast<B &>(p); std::cout << "B"; break;
				case 2: c = dynamic_cast<C &>(p); std::cout << "C"; break;
			}
			std::cout << std::endl;
			return ;
		}
		catch (std::bad_cast &bc)
		{
			continue ;
		}
	}
}

int	main(void)
{
	Base	*p;

	std::srand(std::time(0));
	p = generate();

	std::cout << std::endl;

	std::cout << "-- Dynamic casting with pointers --" << std::endl;
	identify(p);

	std::cout << std::endl;

	std::cout << "-- Dynamic casting with references --" << std::endl;
	identify(*p);

	std::cout << std::endl;

	delete	p;

	return (0);
}
