/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:54:37 by olivierroy        #+#    #+#             */
/*   Updated: 2024/02/12 14:27:08 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_H
# define AANIMAL_H

# include <iostream>
# include <string>

# ifndef	AANIMAL_PREFIX
#  define 	AANIMAL_PREFIX "\033[1;33m[AAnimal]\033[0m	"
# endif /*  AANIMAL_PREFIX */

class AAnimal
{
protected:

	std::string	type;

public:

	AAnimal(void);
	AAnimal(AAnimal const &src);
	AAnimal &operator=(AAnimal const &rhs);
	virtual ~AAnimal(void);

	std::string		getType(void) const;
	virtual void	makeSound(void) const = 0;
};

#endif
