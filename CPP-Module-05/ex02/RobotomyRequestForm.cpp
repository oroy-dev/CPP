/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:16:42 by oroy              #+#    #+#             */
/*   Updated: 2024/05/15 16:02:00 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*	Canonical Form Requirements --------------------------------------------- */

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src._name + "_copy", 72, 45)
{
	*this = src;
	return ;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	_signed = rhs._signed;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "[" << _name << "] burned" << std::endl;
	return ;
}

/*	Additional Constructors ------------------------------------------------- */

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	_doOperation(target);
	return ;
}

void	RobotomyRequestForm::_doOperation(std::string target) const
{
	int	random;

	srand(time(0));
	random = rand();
	std::cout << random << std::endl;
	std::cout << "Drrrrrrrr Drrrrrrrr" << std::endl;
	if (random % 2 == 0)
		std::cout << GREEN << target << " was robotomized" << RESET << std::endl;
	else
		std::cout << RED << target << " was not robotomized" << RESET << std::endl;
}
