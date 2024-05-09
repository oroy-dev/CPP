/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:51:19 by oroy              #+#    #+#             */
/*   Updated: 2024/01/24 16:36:21 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>
# include <string>

# ifndef	WEAPON_TEXT
#  define 	WEAPON_TEXT "\033[1;33m[Weapon]\033[0m	"
# endif /*  WEAPON_TEXT */

class Weapon
{
private:

	std::string			type;

public:

	Weapon(void);
	Weapon(std::string type);
	~Weapon(void);

	std::string const	&getType(void) const;
	void				setType(std::string type);

};

#endif
