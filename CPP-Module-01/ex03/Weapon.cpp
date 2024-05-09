/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:52:26 by oroy              #+#    #+#             */
/*   Updated: 2024/01/29 13:47:14 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) : type("Unknown weapon")
{
	std::cout << WEAPON_TEXT << getType() << " created" << std::endl;
	return ;
}

Weapon::Weapon(std::string type) : type(type)
{
	std::cout << WEAPON_TEXT << getType() << " created" << std::endl;
	return ;
}

Weapon::~Weapon(void)
{
	std::cout << WEAPON_TEXT << getType() << " destroyed" << std::endl;
	return ;
}

std::string const	&Weapon::getType(void) const
{
	return (this->type);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}
