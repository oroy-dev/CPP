/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:57:16 by oroy              #+#    #+#             */
/*   Updated: 2024/01/29 13:53:54 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_B
# define HUMANA_B

# include <iostream>
# include <string>
# include "Weapon.hpp"

# ifndef	HUMANB_TEXT
#  define 	HUMANB_TEXT "\033[1;31m[HumanB]\033[0m	"
# endif /*  HUMANB_TEXT */

class HumanB
{
private:

	std::string	name;
	Weapon		*weapon;

public:

	HumanB(void);
	HumanB(std::string name);
	HumanB(std::string name, Weapon &weapon);
	~HumanB();

	void		attack(void) const;
	void		setWeapon(Weapon &weapon);

};

#endif
