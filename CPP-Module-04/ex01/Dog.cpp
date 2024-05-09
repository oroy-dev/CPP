/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:04:06 by olivierroy        #+#    #+#             */
/*   Updated: 2024/02/06 21:07:45 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*	Canonical Form Requirements --------------------------------------------- */

Dog::Dog(void)
{
	std::cout << DOG_PREFIX << "Default constructor called" << std::endl;
	_brain = new Brain();
	_brain->setIdeas("Woof");
	type = "Dog";
	return ; 
}

Dog::Dog(Dog const &src)
{
	std::cout << DOG_PREFIX << "Constructor by copy called" << std::endl;
	_brain = new Brain();
	*this = src;
	return ; 
}

Dog	&Dog::operator=(Dog const &rhs)
{
	std::cout << DOG_PREFIX << "Assignment to instance called" << std::endl;
	*_brain = *rhs._brain;
	type = rhs.type;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << DOG_PREFIX << "Destructor called" << std::endl;
	delete	_brain;
	return ;
}

/*	Member Functions -------------------------------------------------------- */

void	Dog::makeSound(void) const
{
	std::cout << DOG_PREFIX << "Woof !" << std::endl;
}

std::string	Dog::getBrainIdea(void) const
{
	return (_brain->getIdea());
}

void	Dog::setBrainIdeas(std::string const idea)
{
	_brain->setIdeas(idea);
}
