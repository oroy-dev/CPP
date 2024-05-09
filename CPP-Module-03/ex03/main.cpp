/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:46:26 by olivierroy        #+#    #+#             */
/*   Updated: 2024/02/08 14:40:41 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	ClapTrap	olivier("olivier");
	DiamondTrap	random;
	DiamondTrap	ziggy("ziggy");
	DiamondTrap	cop(ziggy);

	random.whoAmI();
	ziggy.whoAmI();
	cop.whoAmI();

	ziggy.attack("Random");
	random.takeDamage(30);

	ziggy.takeDamage(200);
	olivier.attack("ziggy");
	ziggy.attack("olivier");
	cop.attack("random");
	random.takeDamage(30);

	cop.beRepaired(50);

	return (0);
}
