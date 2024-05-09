/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:04:06 by olivierroy        #+#    #+#             */
/*   Updated: 2024/02/06 21:07:45 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*	Canonical Form Requirements --------------------------------------------- */

Dog::Dog(void)
{
	std::cout << DOG_PREFIX << "Default constructor called" << std::endl;
	type = "Dog";
	return ; 
}

Dog::Dog(Dog const &src)
{
	std::cout << DOG_PREFIX << "Constructor by copy called" << std::endl;
	*this = src;
	return ; 
}

Dog	&Dog::operator=(Dog const &rhs)
{
	std::cout << DOG_PREFIX << "Assignment to instance called" << std::endl;
	type = rhs.type;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << DOG_PREFIX << "Destructor called" << std::endl;
	return ; 
}

/*	Add-ons ----------------------------------------------------------------- */

void	Dog::makeSound(void) const
{
	std::cout << DOG_PREFIX << "Woof !" << std::endl;
}
