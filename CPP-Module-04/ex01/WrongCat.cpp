/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:04:06 by olivierroy        #+#    #+#             */
/*   Updated: 2024/02/06 21:07:45 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/*	Canonical Form Requirements --------------------------------------------- */

WrongCat::WrongCat(void)
{
	std::cout << WCAT_PREFIX << "Default constructor called" << std::endl;
	type = "Rooster";
	return ; 
}

WrongCat::WrongCat(WrongCat const &src)
{
	std::cout << WCAT_PREFIX << "Constructor by copy called" << std::endl;
	*this = src;
	return ; 
}

WrongCat	&WrongCat::operator=(WrongCat const &rhs)
{
	std::cout << WCAT_PREFIX << "Assignment to instance called" << std::endl;
	type = rhs.type;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << WCAT_PREFIX << "Destructor called" << std::endl;
	return ; 
}

/*	Add-ons ----------------------------------------------------------------- */

void	WrongCat::makeSound(void) const
{
	std::cout << WCAT_PREFIX << "Cocorico !" << std::endl;
}
