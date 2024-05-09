/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:54:22 by oroy              #+#    #+#             */
/*   Updated: 2024/01/19 16:34:49 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*joe = new Zombie("Joe");
	Zombie	*ziggy;
	Zombie	*olivier;
	Zombie	random;

	ziggy = zombieHorde(5, "Ziggy");
	olivier = zombieHorde(2, "Olivier");
	joe->announce();
	ziggy->announce();
	olivier->announce();
	delete joe;
	delete [] ziggy;
	delete [] olivier;
	return (0);
}
