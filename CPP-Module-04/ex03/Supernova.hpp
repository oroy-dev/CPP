/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Supernova.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:10:48 by oroy              #+#    #+#             */
/*   Updated: 2024/02/13 14:27:34 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERNOVA_H
# define SUPERNOVA_H

# include "AMateria.hpp"

class Supernova : public AMateria
{
public:

	Supernova(void);
	Supernova(Supernova const &src);
	Supernova(std::string const &type);
	Supernova &operator=(Supernova const &rhs);
	~Supernova(void);

	AMateria	*clone() const;
	void		use(ICharacter &target);

};

#endif
