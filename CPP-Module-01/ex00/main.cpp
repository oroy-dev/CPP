/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:54:22 by oroy              #+#    #+#             */
/*   Updated: 2024/01/18 16:29:34 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	no_name;
	Zombie	*ziggy;

	ziggy = newZombie("Ziggy");
	ziggy->announce();
	randomChump("Joe");
	delete (ziggy);
	return (0);
}
