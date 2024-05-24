/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:07:07 by oroy              #+#    #+#             */
/*   Updated: 2024/05/24 16:34:01 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*	Canonical Form Requirements --------------------------------------------- */

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", target, 145, 137)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src.getName() + "_copy", src.getTarget(), 145, 137)
{
	*this = src;
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	setSigned(rhs.getSigned());
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "[" << getName() << "] burned" << std::endl;
	return ;
}

/*	Form Action ------------------------------------------------------------- */

void	ShrubberyCreationForm::_doFormAction(void) const
{
	std::string		filename;
	std::ofstream	file;

	filename = getTarget() + "_shrubbery";
	file.open (filename, std::ofstream::app);
	if (file.is_open())
	{
		file << _getAscii();
		file.close();
		std::cout << "Wrote shrubbery in " << filename << std::endl;
	}
	else
		std::cerr << RED << "Failed to open file: " << filename << RESET << std::endl;
}

std::string	ShrubberyCreationForm::_getAscii(void) const
{
	std::string	shrubbery;

	shrubbery = "";
	shrubbery += "   ===   \n";
	shrubbery += " ======= \n";
	shrubbery += "=========\n";
	shrubbery += " ======= \n";
	shrubbery += "   ===   \n";
	return (shrubbery);
}
