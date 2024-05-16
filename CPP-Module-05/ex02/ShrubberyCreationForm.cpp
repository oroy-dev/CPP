/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:07:07 by oroy              #+#    #+#             */
/*   Updated: 2024/05/16 16:08:37 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*	Canonical Form Requirements --------------------------------------------- */

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137)
{
	_writeShrubbery("default");
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src._name + "_copy", 145, 137)
{
	*this = src;
	_writeShrubbery("default");
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	_signed = rhs._signed;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "[" << _name << "] burned" << std::endl;
	return ;
}

/*	Additional Constructors ------------------------------------------------- */

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	_writeShrubbery(target);
	return ;
}

void	ShrubberyCreationForm::_writeShrubbery(std::string target) const
{
	std::string		filename;
	std::ofstream	file;

	filename = target + "_shrubbery";
	file.open (filename, std::ofstream::app);
	if (file.is_open())
	{
		file << _getAscii();
		file.close();
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
