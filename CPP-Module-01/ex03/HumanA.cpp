/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:58:18 by oroy              #+#    #+#             */
/*   Updated: 2024/01/23 12:24:30 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
	std::cout << HUMANA_TEXT << this->name << " created | Equipment: " << this->weapon.getType() << std::endl;
	return ;
}

HumanA::~HumanA(void)
{
	std::cout << HUMANA_TEXT << this->name << " destroyed" << std::endl;
	return ;
}

void	HumanA::attack(void) const
{
	std::cout << HUMANA_TEXT << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
