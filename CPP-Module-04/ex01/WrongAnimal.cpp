/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:04:06 by olivierroy        #+#    #+#             */
/*   Updated: 2024/02/06 21:29:40 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/*	Canonical Form Requirements --------------------------------------------- */

WrongAnimal::WrongAnimal(void)
{
	std::cout << WANIMAL_PREFIX << "Default constructor called" << std::endl;
	type = "Captain Falcon";
	return ; 
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	std::cout << WANIMAL_PREFIX << "Constructor by copy called" << std::endl;
	*this = src;
	return ; 
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &rhs)
{
	std::cout << WANIMAL_PREFIX << "Assignment to instance called" << std::endl;
	type = rhs.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << WANIMAL_PREFIX << "Destructor called" << std::endl;
	return ; 
}

/*	Add-ons ----------------------------------------------------------------- */

std::string	WrongAnimal::getType(void) const
{
	return (type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << WANIMAL_PREFIX << "Show me your move !" << std::endl;
}
