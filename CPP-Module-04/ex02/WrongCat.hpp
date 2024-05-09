/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:54:37 by olivierroy        #+#    #+#             */
/*   Updated: 2024/02/08 15:43:56 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
# define WRONGCAT_H

# include "WrongAnimal.hpp"

# ifndef	WCAT_PREFIX
#  define 	WCAT_PREFIX "\033[1;32m[WrongCat]\033[0m	"
# endif /*  WCAT_PREFIX */

class WrongCat : public WrongAnimal
{
public:

	WrongCat(void);
	WrongCat(WrongCat const &src);
	WrongCat &operator=(WrongCat const &rhs);
	~WrongCat(void);

	void	makeSound(void) const;
};

#endif
