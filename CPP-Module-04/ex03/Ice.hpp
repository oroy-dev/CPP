/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:10:48 by oroy              #+#    #+#             */
/*   Updated: 2024/02/13 14:27:34 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H

# include "AMateria.hpp"

class Ice : public AMateria
{
public:

	Ice(void);
	Ice(Ice const &src);
	Ice(std::string const &type);
	Ice &operator=(Ice const &rhs);
	~Ice(void);

	AMateria	*clone() const;
	void		use(ICharacter &target);

};

#endif
