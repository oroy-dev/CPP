/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:54:37 by olivierroy        #+#    #+#             */
/*   Updated: 2024/02/12 23:22:20 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
private:

	Brain	*_brain;

public:

	Cat(void);
	Cat(Cat const &src);
	Cat &operator=(Cat const &rhs);
	~Cat(void);

	std::string	getBrainIdea(void) const;
	void		makeSound(void) const;
	void		setBrainIdeas(std::string const idea);

};

# ifndef	CAT_PREFIX
#  define 	CAT_PREFIX "\033[1;32m[Cat]\033[0m		"
# endif /*  CAT_PREFIX */

#endif
