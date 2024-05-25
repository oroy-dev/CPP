/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:14:54 by olivierroy        #+#    #+#             */
/*   Updated: 2024/05/25 17:35:45 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*	Canonical Form Requirements --------------------------------------------- */

Intern::Intern(void)
{
	std::cout << "[Intern] hired" << std::endl;
	return ;
}

Intern::Intern(Intern const &src)
{
	(void) src;
	std::cout << "[Intern] hired" << std::endl;
	return ;
}

Intern	&Intern::operator=(Intern const &rhs)
{
	(void) rhs;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "[Intern] fired" << std::endl;
	return ;
}

/*	Forms ------------------------------------------------------------------- */

AForm	*Intern::_getForm(unsigned int i, std::string target) const
{
	AForm	*form;

	switch (i)
	{
		case 0: form = new PresidentialPardonForm(target); break;
		case 1: form = new RobotomyRequestForm(target); break;
		case 2: form = new ShrubberyCreationForm(target); break;
	}
	return (form);
}

AForm	*Intern::makeForm(std::string name, std::string target) const
{
	AForm	*form = NULL;
	
	for (unsigned int i = 0; i < NUMBER_OF_FORMS; i++)
	{
		if (forms[i] == name)
		{
			form = _getForm(i, target);
			std::cout << "Intern creates " << name << std::endl;
			return (form);
		}
	}
	std::cout << RED << "No such form exists. Creating default form" << RESET << std::endl;
	return (new DefaultForm(target));
}

std::string Intern::forms[NUMBER_OF_FORMS] = \
{
	"presidential pardon",
	"robotomy request",
	"shrubbery creation"
};
