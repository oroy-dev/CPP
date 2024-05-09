/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:04:06 by olivierroy        #+#    #+#             */
/*   Updated: 2024/02/08 16:06:31 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*	Canonical Form Requirements --------------------------------------------- */

Animal::Animal(void)
{
	std::cout << ANIMAL_PREFIX << "Default constructor called" << std::endl;
	return ; 
}

Animal::Animal(Animal const &src)
{
	std::cout << ANIMAL_PREFIX << "Constructor by copy called" << std::endl;
	*this = src;
	return ; 
}

Animal	&Animal::operator=(Animal const &rhs)
{
	std::cout << ANIMAL_PREFIX << "Assignment to instance called" << std::endl;
	type = rhs.type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << ANIMAL_PREFIX << "Destructor called" << std::endl;
	return ; 
}

/*	Add-ons ----------------------------------------------------------------- */

std::string	Animal::getType(void) const
{
	return (type);
}

void	Animal::makeSound(void) const
{
	std::cout << ANIMAL_PREFIX << std::endl;
}
