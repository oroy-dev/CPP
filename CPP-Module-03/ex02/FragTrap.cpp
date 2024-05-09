/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:34:27 by olivierroy        #+#    #+#             */
/*   Updated: 2024/02/07 16:06:26 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	_name = "random";
	_hitpoints = 100;
	_energypoints = 100;
	_attackdamage = 30;
	std::cout << "A random FragTrap created" << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name)
{
	_name = name;
	_hitpoints = 100;
	_energypoints = 100;
	_attackdamage = 30;
	std::cout << "FragTrap " << _name << " created" << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const &src)
{
	*this = src;
	_name += "_copy";
	std::cout << "FragTrap " << _name << " created by copy" << std::endl;
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << _name << " destroyed!!!" << std::endl;
	return ;
}

FragTrap	&FragTrap::operator=(FragTrap const &rhs)
{
	_name = rhs._name;
	_hitpoints = rhs._hitpoints;
	_energypoints = rhs._energypoints;
	_attackdamage = rhs._attackdamage;
	return (*this);
}

void	FragTrap::attack(const std::string& target)
{
	std::cout << std::endl;
	if (_hitpoints > 0)
	{
		if (_energypoints)
		{
			std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackdamage << " points of damage!" << std::endl;
			--_energypoints;
		}
		else
			std::cout << "FragTrap " << _name << " has no energy points left." << std::endl;
	}
	else
		std::cout << "FragTrap " << _name << " can't attack since it's dead." << std::endl;
	printStatus();
	std::cout << std::endl;
	std::cout << "-------------------------------" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << std::endl;
	std::cout << "FragTrap " << _name << " does a high five to the evaluator!!!" << std::endl;
}
