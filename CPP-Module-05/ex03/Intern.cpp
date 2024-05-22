/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:14:54 by olivierroy        #+#    #+#             */
/*   Updated: 2024/05/22 00:25:44 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

std::string Intern::forms[NUMBER_OF_FORMS] = \
{
	"presidential pardon",
	"robotomy request",
	"shrubbery creation"
};

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

/*	Make Form Function ------------------------------------------------------ */

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
	for (int i = 0; i < NUMBER_OF_FORMS; i++)
	{
		if (forms[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return (_getForm(i, target));
		}
	}
	std::cout << "No such form exists" << std::endl;
	return (NULL);
}
