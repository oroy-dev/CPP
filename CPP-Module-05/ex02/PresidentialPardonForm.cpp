/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:07:07 by oroy              #+#    #+#             */
/*   Updated: 2024/05/16 16:37:02 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*	Canonical Form Requirements --------------------------------------------- */

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5)
{
	_pardon("default");
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src._name + "_copy", 25, 5)
{
	*this = src;
	_pardon("default");
	return ;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	_signed = rhs._signed;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "[" << _name << "] burned" << std::endl;
	return ;
}

/*	Additional Constructors ------------------------------------------------- */

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
	_pardon(target);
	return ;
}

void	PresidentialPardonForm::_pardon(std::string target) const
{
	std::cout << target << " was pardonned by Zaphod Beeblebrox" << std::endl;
}
