/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:04:06 by olivierroy        #+#    #+#             */
/*   Updated: 2024/02/12 23:08:08 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/*	Canonical Form Requirements --------------------------------------------- */

AAnimal::AAnimal(void)
{
	std::cout << AANIMAL_PREFIX << "Default constructor called" << std::endl;
	return ; 
}

AAnimal::AAnimal(AAnimal const &src)
{
	std::cout << AANIMAL_PREFIX << "Constructor by copy called" << std::endl;
	*this = src;
	return ; 
}

AAnimal	&AAnimal::operator=(AAnimal const &rhs)
{
	std::cout << AANIMAL_PREFIX << "Assignment to instance called" << std::endl;
	type = rhs.type;
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << AANIMAL_PREFIX << "Destructor called" << std::endl;
	return ; 
}

/*	Member Functions -------------------------------------------------------- */

std::string	AAnimal::getType(void) const
{
	return (type);
}
