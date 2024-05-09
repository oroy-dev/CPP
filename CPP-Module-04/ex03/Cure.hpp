/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:10:48 by oroy              #+#    #+#             */
/*   Updated: 2024/02/13 14:27:34 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
# define CURE_H

# include "AMateria.hpp"

class Cure : public AMateria
{
public:

	Cure(void);
	Cure(Cure const &src);
	Cure(std::string const &type);
	Cure &operator=(Cure const &rhs);
	~Cure(void);

	AMateria	*clone() const;
	void		use(ICharacter &target);

};

#endif
