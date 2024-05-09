/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:32:09 by oroy              #+#    #+#             */
/*   Updated: 2024/01/29 13:37:03 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "An unnamed Zombie was created" << std::endl;
	return ;
}

Zombie::Zombie(std::string name) : name(name)
{
	std::cout << this->name << " was created" << std::endl;
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
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
