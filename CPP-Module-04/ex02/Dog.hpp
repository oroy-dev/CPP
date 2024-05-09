/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:54:37 by olivierroy        #+#    #+#             */
/*   Updated: 2024/02/12 23:22:13 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
private:

	Brain	*_brain;

public:

	Dog(void);
	Dog(Dog const &src);
	Dog &operator=(Dog const &rhs);
	~Dog(void);

	std::string	getBrainIdea(void) const;
	void		makeSound(void) const;
	void		setBrainIdeas(std::string const idea);

};

# ifndef	DOG_PREFIX
#  define 	DOG_PREFIX "\033[1;31m[Dog]\033[0m		"
# endif /*  DOG_PREFIX */

#endif
