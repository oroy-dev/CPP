/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:10:48 by oroy              #+#    #+#             */
/*   Updated: 2024/02/16 16:19:18 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
# define AMATERIA_H

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:

	std::string const	_type;

public:

	AMateria(void);
	AMateria(AMateria const &src);
	AMateria(std::string const &type);
	AMateria &operator=(AMateria const &rhs);
	virtual ~AMateria(void);

	std::string const &getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

};

#endif
