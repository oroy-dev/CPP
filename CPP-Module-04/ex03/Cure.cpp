/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:59:24 by oroy              #+#    #+#             */
/*   Updated: 2024/02/14 15:14:27 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

/*	Canonical Form Requirements --------------------------------------------- */

Cure::Cure(void) : AMateria("cure")
{
	return ;
}

Cure::Cure(Cure const &src) : AMateria(src.getType())
{
	return ;
}

Cure::Cure(std::string const &type) : AMateria(type)
{
	return ;
}

Cure	&Cure::operator=(Cure const &rhs)
{
	(void) rhs;
	return (*this);
}

Cure::~Cure(void)
{
	return ;
}

/*	Member Functions -------------------------------------------------------- */

AMateria	*Cure::clone() const
{
	return (new Cure());
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
