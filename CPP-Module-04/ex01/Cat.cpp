/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:04:06 by olivierroy        #+#    #+#             */
/*   Updated: 2024/02/06 21:07:45 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*	Canonical Form Requirements --------------------------------------------- */

Cat::Cat(void)
{
	std::cout << CAT_PREFIX << "Default constructor called" << std::endl;
	_brain = new Brain();
	_brain->setIdeas("Miaw");
	type = "Cat";
	return ; 
}

Cat::Cat(Cat const &src)
{
	std::cout << CAT_PREFIX << "Constructor by copy called" << std::endl;
	_brain = new Brain();
	*this = src;
	return ; 
}

Cat	&Cat::operator=(Cat const &rhs)
{
	std::cout << CAT_PREFIX << "Assignment to instance called" << std::endl;
	*_brain = *rhs._brain;
	type = rhs.type;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << CAT_PREFIX << "Destructor called" << std::endl;
	delete	_brain;
	return ;
}

/*	Member Functions -------------------------------------------------------- */

void	Cat::makeSound(void) const
{
	std::cout << CAT_PREFIX << "Meow !" << std::endl;
}

std::string	Cat::getBrainIdea(void) const
{
	return (_brain->getIdea());
}

void	Cat::setBrainIdeas(std::string const idea)
{
	_brain->setIdeas(idea);
}
