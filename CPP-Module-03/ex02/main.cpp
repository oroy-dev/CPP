/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:46:26 by olivierroy        #+#    #+#             */
/*   Updated: 2024/02/07 16:12:33 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	olivier("olivier");
	FragTrap	random;
	FragTrap	ziggy("ziggy");
	FragTrap	cop(ziggy);

	ziggy.attack("Random");
	random.takeDamage(30);
	random.highFivesGuys();

	ziggy.takeDamage(100);
	ziggy.beRepaired(20);
	olivier.attack("ziggy");
	ziggy.takeDamage(0);

	return (0);
}
