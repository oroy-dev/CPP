/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:32:09 by oroy              #+#    #+#             */
/*   Updated: 2024/01/19 16:32:01 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "An unnamed Zombie was created" << std::endl;
	this->set_number(1);
	return ;
}

Zombie::Zombie(std::string name) : name(name)
{
	std::cout << this->name << " was created" << std::endl;
	this->set_number(1);
	return ;
}

Zombie::~Zombie(void)
{
	if (!this->name.empty())
		std::cout << this->name << " was destroyed." << std::endl;
	else
		std::cout << "An unnamed Zombie was destroyed." << std::endl;
	return ;
}

void	Zombie::announce(void)
{
	for (int i = 0; i < this->_N; i++)
		std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->name = name;
}

void	Zombie::set_number(int N)
{
	this->_N = N;
}
