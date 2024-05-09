/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:34:04 by oroy              #+#    #+#             */
/*   Updated: 2024/01/18 16:26:26 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <string>

class	Zombie
{
	private:

		std::string name;

	public:

		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);

		void		announce(void);

};

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

#endif
