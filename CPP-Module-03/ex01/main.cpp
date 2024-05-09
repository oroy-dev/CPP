/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:46:26 by olivierroy        #+#    #+#             */
/*   Updated: 2024/02/06 16:35:30 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	olivier("olivier");
	ScavTrap	random;
	ScavTrap	ziggy("ziggy");
	ScavTrap	cop(ziggy);

	ziggy.attack("Random");
	random.takeDamage(20);
	random.guardGate();

	for (int i = 0; i < 6; i++)
		ziggy.takeDamage(20);

	ziggy.beRepaired(100);
	olivier.attack("ziggy");
	ziggy.takeDamage(0);

	for (int i = 0; i < 51; i++)
		random.beRepaired(10);

	return (0);
}
