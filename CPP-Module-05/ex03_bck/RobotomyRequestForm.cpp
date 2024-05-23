/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:16:42 by oroy              #+#    #+#             */
/*   Updated: 2024/05/21 14:37:25 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*	Canonical Form Requirements --------------------------------------------- */

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", target, 72, 45)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src.getName() + "_copy", src.getTarget(), 72, 45)
{
	*this = src;
	return ;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	setSigned(rhs.getSigned());
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "[" << getName() << "] burned" << std::endl;
	return ;
}

/*	Form Action ------------------------------------------------------------- */

void	RobotomyRequestForm::_doFormAction(void) const
{
	static unsigned int	old_time;
	unsigned int		new_time;

	new_time = time(NULL);
	if (new_time != old_time)
		srand(new_time);
	old_time = new_time;
	std::cout << "Drrrrrrrr Drrrrrrrr" << std::endl;
	if (rand() % 2 == 0)
		std::cout << GREEN << getTarget() << " was robotized" << RESET << std::endl;
	else
		std::cout << RED << getTarget() << " was not robotized" << RESET << std::endl;
}
