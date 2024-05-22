/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:14:54 by olivierroy        #+#    #+#             */
/*   Updated: 2024/05/22 13:58:30 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*	Canonical Form Requirements --------------------------------------------- */

Intern::Intern(void)
{
	return ;
}

Intern::Intern(Intern const &src)
{
	(void) src;
	return ;
}

Intern	&Intern::operator=(Intern const &rhs)
{
	(void) rhs;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern killed" << std::endl;
	return ;
}

/*	Forms ------------------------------------------------------------------- */

AForm	*Intern::_getForm(unsigned int i, std::string target) const
{
	switch (i)
	{
		case 0: return (new PresidentialPardonForm(target));
		case 1: return (new RobotomyRequestForm(target));
		case 2: return (new ShrubberyCreationForm(target));
	}
	return (NULL);
}

AForm	*Intern::makeForm(std::string name, std::string target) const
{
	AForm	*form;

	for (unsigned int i = 0; i < NUMBER_OF_FORMS; i++)
	{
		if (forms[i] == name)
		{
			form = _getForm(i, target);
			if (!form)
				std::cout << "Unusual problem occurred while trying to get form" << std::endl;
			else
				std::cout << "Intern creates " << name << std::endl;
			return (form);
		}
	}
	std::cout << "No such form exists" << std::endl;
	return (NULL);
}

std::string Intern::forms[NUMBER_OF_FORMS] = \
{
	"presidential pardon",
	"robotomy request",
	"shrubbery creation"
};
