/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:51:11 by oroy              #+#    #+#             */
/*   Updated: 2024/02/13 15:31:07 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/*	Canonical Form Requirements --------------------------------------------- */

Brain::Brain(void)
{
	std::cout << BRAIN_PREFIX << "Default constructor called" << std::endl;
	return ; 
}

Brain::Brain(Brain const &src)
{
	std::cout << BRAIN_PREFIX << "Constructor by copy called" << std::endl;
	*this = src;
	return ;
}

Brain	&Brain::operator=(Brain const &rhs)
{
	std::cout << BRAIN_PREFIX << "Assignment to instance called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = rhs._ideas[i];
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << BRAIN_PREFIX << "Destructor called" << std::endl;
	return ; 
}

/*	Member Functions -------------------------------------------------------- */

void	Brain::setIdeas(std::string const idea)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = idea;
}

std::string	Brain::getIdea(void) const
{
	return (_ideas[0]);
}
