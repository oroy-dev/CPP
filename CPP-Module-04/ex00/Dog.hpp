/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:54:37 by olivierroy        #+#    #+#             */
/*   Updated: 2024/02/08 16:09:47 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"

# ifndef	DOG_PREFIX
#  define 	DOG_PREFIX "\033[1;31m[Dog]\033[0m		"
# endif /*  DOG_PREFIX */

class Dog : public Animal
{
public:

	Dog(void);
	Dog(Dog const &src);
	Dog &operator=(Dog const &rhs);
	~Dog(void);

	void	makeSound(void) const;
};

#endif
