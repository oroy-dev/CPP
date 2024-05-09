/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:55:48 by oroy              #+#    #+#             */
/*   Updated: 2024/01/23 12:20:19 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

# include <iostream>
# include <string>
# include "Weapon.hpp"

# ifndef	HUMANA_TEXT
#  define 	HUMANA_TEXT "\033[1;32m[HumanA]\033[0m	"
# endif /*  HUMANA_TEXT */

class HumanA
{
private:
	
	std::string	name;
	Weapon		&weapon;

public:

	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);

	void		attack(void) const;

};

#endif
