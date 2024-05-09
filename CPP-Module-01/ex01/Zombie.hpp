/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:34:04 by oroy              #+#    #+#             */
/*   Updated: 2024/01/19 16:28:21 by oroy             ###   ########.fr       */
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
		int			_N;

	public:

		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		
		void		announce(void);
		void		set_name(std::string name);
		void		set_number(int N);

};

Zombie	*zombieHorde(int N, std::string name);

#endif
