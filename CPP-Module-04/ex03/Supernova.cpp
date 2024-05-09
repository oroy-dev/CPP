/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Supernova.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:10:33 by oroy              #+#    #+#             */
/*   Updated: 2024/02/14 15:14:24 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Supernova.hpp"

/*	Canonical Form Requirements --------------------------------------------- */

Supernova::Supernova(void) : AMateria("supernova")
{
	return ;
}

Supernova::Supernova(Supernova const &src) : AMateria(src.getType())
{
	return ;
}

Supernova::Supernova(std::string const &type) : AMateria(type)
{
	return ;
}

Supernova	&Supernova::operator=(Supernova const &rhs)
{
	(void) rhs;
	return (*this);
}

Supernova::~Supernova(void)
{
	return ;
}

/*	Member Functions -------------------------------------------------------- */

AMateria	*Supernova::clone() const
{
	return (new Supernova());
}

void	Supernova::use(ICharacter &target)
{
	std::cout << "* throws all the planets of the galaxy at " << target.getName() << ", decimating pretty much everything at the same time *" << std::endl;
}
