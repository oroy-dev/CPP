/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:58:54 by oroy              #+#    #+#             */
/*   Updated: 2024/01/29 14:09:21 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

// Original Test

int main(void)
{
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}

// int main(void)
// {
// 	HumanA	*randomA;
// 	HumanB	randomB;
// 	HumanB	*ziggy = new HumanB("Ziggy");
// 	HumanB	*olivier;
// 	Weapon	weapon[4];

// 	weapon[0].setType("Sword");
// 	weapon[1].setType("Axe");
// 	weapon[2].setType("Lance");
// 	randomA = new HumanA("DudeA", weapon[3]);
// 	olivier = new HumanB("Olivier", weapon[0]);
	
// 	std::cout << std::endl;
// 	std::cout << "===================== Fight ! =====================" << std::endl;
// 	std::cout << std::endl;

// 	randomA->attack();
// 	randomB.attack();
// 	ziggy->attack();
// 	olivier->attack();

// 	randomB.setWeapon(weapon[0]);
// 	ziggy->setWeapon(weapon[1]);
// 	weapon[3].setType(weapon[2].getType());

// 	randomA->attack();
// 	randomB.attack();
// 	ziggy->attack();

// 	ziggy->setWeapon(weapon[2]);

// 	ziggy->attack();

// 	delete randomA;
// 	delete ziggy;
// 	delete olivier;
// 	return 0;
// }
