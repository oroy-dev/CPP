/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:46:24 by olivierroy        #+#    #+#             */
/*   Updated: 2024/02/07 16:20:37 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("random"), _hitpoints(10), _energypoints(10), _attackdamage(0)
{
	std::cout << "A random ClapTrap created" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(10), _energypoints(10), _attackdamage(0)
{
	std::cout << "ClapTrap " << _name << " created" << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	*this = src;
	_name += "_copy";
	std::cout << "ClapTrap " << _name << " created by copy" << std::endl;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << _name << " destroyed!!!" << std::endl;
	return ;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs)
{
	_name = rhs._name;
	_hitpoints = rhs._hitpoints;
	_energypoints = rhs._energypoints;
	_attackdamage = rhs._attackdamage;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	std::cout << std::endl;
	if (_hitpoints > 0)
	{
		if (_energypoints)
		{
			std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackdamage << " points of damage!" << std::endl;
			--_energypoints;
		}
		else
			std::cout << "ClapTrap " << _name << " has no energy points left." << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " can't attack since it's dead." << std::endl;
	printStatus();
	std::cout << std::endl;
	std::cout << "-------------------------------" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << std::endl;
	std::cout << "ClapTrap " << _name << " takes " << amount << " damage points! " << std::endl;
	_hitpoints -= amount;
	printStatus();
	std::cout << std::endl;
	std::cout << "-------------------------------" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << std::endl;
	if (_hitpoints > 0)
	{
		if (_energypoints)
		{
			std::cout << "ClapTrap " << _name << " repairs itself by " << amount << " points! " << std::endl;
			_hitpoints += amount;
			--_energypoints;
		}
		else
			std::cout << "ClapTrap " << _name << " has no energy points left." << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " tries to repair itself, but forgot it can't since the thing is dead." << std::endl;
	printStatus();
	std::cout << std::endl;
	std::cout << "-------------------------------" << std::endl;
}

void	ClapTrap::printStatus(void) const
{
	std::cout << std::endl;
	std::cout << "ClapTrap " << _name << " status:" << std::endl;
	std::cout << "[Hit Points]	" << _hitpoints << std::endl;
	std::cout << "[Energy Points]	" << _energypoints << std::endl;
}
