/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:16:42 by oroy              #+#    #+#             */
/*   Updated: 2024/05/16 16:36:15 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*	Canonical Form Requirements --------------------------------------------- */

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45)
{
	_robotize("default");
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src._name + "_copy", 72, 45)
{
	*this = src;
	_robotize("default");
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
	_robotize(target);
	return ;
}

void	RobotomyRequestForm::_robotize(std::string target) const
{
	static unsigned int	old_time;
	unsigned int		new_time;

	new_time = time(NULL);
	if (new_time != old_time)
		srand(new_time);
	old_time = new_time;
	std::cout << "Drrrrrrrr Drrrrrrrr" << std::endl;
	if (rand() % 2 == 0)
		std::cout << GREEN << target << " was robotized" << RESET << std::endl;
	else
		std::cout << RED << target << " was not robotized" << RESET << std::endl;
}
