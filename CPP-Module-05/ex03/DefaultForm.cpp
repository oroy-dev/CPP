/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DefaultForm.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:07:07 by oroy              #+#    #+#             */
/*   Updated: 2024/05/25 17:18:37 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DefaultForm.hpp"

/*	Canonical Form Requirements --------------------------------------------- */

DefaultForm::DefaultForm(std::string target) : AForm("DefaultForm", target, 25, 5)
{
	return ;
}

DefaultForm::DefaultForm(DefaultForm const &src) : AForm(src.getName() + "_copy", src.getTarget(), 25, 5)
{
	*this = src;
	return ;
}

DefaultForm	&DefaultForm::operator=(DefaultForm const &rhs)
{
	setSigned(rhs.getSigned());
	return (*this);
}

DefaultForm::~DefaultForm(void)
{
	std::cout << "[" << getName() << "] burned" << std::endl;
	return ;
}

/*	Form Action ------------------------------------------------------------- */

void	DefaultForm::_doFormAction(void) const
{
	std::cout << getName() << " does whatever to " << getTarget() << std::endl;
}
