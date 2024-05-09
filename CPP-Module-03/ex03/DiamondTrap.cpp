/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:13:30 by olivierroy        #+#    #+#             */
/*   Updated: 2024/02/08 14:40:36 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	_name = "random";
	ClapTrap::_name = "random_clap_name";
	_hitpoints = FragTrap::getHitPoints();
	_energypoints = ScavTrap::getEnergyPoints();
	_attackdamage = FragTrap::getAttackDamage();
	std::cout << "A random DiamondTrap created" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(std::string name)
{
	_name = name;
	ClapTrap::_name = _name + "_clap_name";
	_hitpoints = FragTrap::getHitPoints();
	_energypoints = ScavTrap::getEnergyPoints();
	_attackdamage = FragTrap::getAttackDamage();
	std::cout << "DiamondTrap " << _name << " created" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src)
{
	*this = src;
	_name += "_copy";
	ClapTrap::_name = _name + "_clap_name";
	std::cout << "DiamondTrap " << _name << " created by copy" << std::endl;
	return ;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << _name << " destroyed!!!" << std::endl;
	return ;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &rhs)
{
	_name = rhs._name;
	_hitpoints = rhs._hitpoints;
	_energypoints = rhs._energypoints;
	_attackdamage = rhs._attackdamage;
	return (*this);
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << std::endl;
	std::cout << "DiamondTrap name = " << _name << std::endl;
	std::cout << "ClapTrap name = " << ClapTrap::_name << std::endl;
	std::cout << std::endl;
	std::cout << "-------------------------------" << std::endl;
}
