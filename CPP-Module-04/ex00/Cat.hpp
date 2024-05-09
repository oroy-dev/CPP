/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:54:37 by olivierroy        #+#    #+#             */
/*   Updated: 2024/02/08 16:09:45 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include "Animal.hpp"

# ifndef	CAT_PREFIX
#  define 	CAT_PREFIX "\033[1;32m[Cat]\033[0m		"
# endif /*  CAT_PREFIX */

class Cat : public Animal
{
public:

	Cat(void);
	Cat(Cat const &src);
	Cat &operator=(Cat const &rhs);
	~Cat(void);

	void	makeSound(void) const;
};

#endif
