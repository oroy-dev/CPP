/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:57:49 by oroy              #+#    #+#             */
/*   Updated: 2024/01/29 14:07:29 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(void) : name("Nameless"), weapon(nullptr)
{
	std::cout << HUMANB_TEXT << this->name << " created | Equipment: No weapon" << std::endl;
	return ;
}

HumanB::HumanB(std::string name) : name(name), weapon(nullptr)
{
	std::cout << HUMANB_TEXT << this->name << " created | Equipment: No weapon" << std::endl;
	return ;
}

HumanB::HumanB(std::string name, Weapon &weapon) : name(name), weapon(&weapon)
{
	std::cout << HUMANB_TEXT << this->name << " created | Equipment: " << this->weapon->getType() << std::endl;
	return ;
}

HumanB::~HumanB(void)
{
	std::cout << HUMANB_TEXT << this->name << " destroyed" << std::endl;
	return ;
}

void	HumanB::attack(void) const
{
	if (this->weapon == nullptr)
		std::cout << HUMANB_TEXT << this->name << " attacks with their fists" << std::endl;
	else
		std::cout << HUMANB_TEXT << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
