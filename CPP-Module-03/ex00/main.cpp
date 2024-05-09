/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:46:26 by olivierroy        #+#    #+#             */
/*   Updated: 2024/02/07 15:27:34 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	random;
	ClapTrap	ziggy("Ziggy");
	ClapTrap	olivier("Olivier");
	ClapTrap	random2(ziggy);

	ziggy.attack("Olivier");
	olivier.takeDamage(9);
	olivier.beRepaired(5);
	olivier.attack("Ziggy");
	ziggy.takeDamage(2);
	random.attack("Random2");

	random2.attack("Random");
	random.takeDamage(20);
	random.beRepaired(10);
	random.attack("Ziggy");

	random.takeDamage(7);

	for (int i = 0; i < 10; i++)
		olivier.attack("Test to reach 0 ep");

	return (0);
}
