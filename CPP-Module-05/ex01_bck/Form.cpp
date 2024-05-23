/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:07:07 by oroy              #+#    #+#             */
/*   Updated: 2024/05/15 15:13:11 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*	Canonical Form Requirements --------------------------------------------- */

Form::Form(void) : _name("DefaultForm"), _signed(false), _gradeSign(150), _gradeExec(150)
{
	return ;
}

Form::Form(Form const &src) : _name(src._name + "_copy"), _gradeSign(src._gradeSign), _gradeExec(src._gradeExec)
{
	*this = src;
	return ;
}

Form	&Form::operator=(Form const &rhs)
{
	_signed = rhs._signed;
	return (*this);
}

Form::~Form(void)
{
	std::cout << "[" << _name << "] Form burned" << std::endl;
	return ;
}

/*	Additional Constructors ------------------------------------------------- */

Form::Form(std::string name, int gradeSign, int gradeExec) : _name(name), _gradeSign(_testGrade(gradeSign)), _gradeExec(_testGrade(gradeExec))
{
	_signed = false;
	return ;
}

/*	Getters ----------------------------------------------------------------- */

std::string const	Form::getName(void) const
{
	return (_name);
}

bool	Form::getSigned(void) const
{
	return (_signed);
}

int	Form::getGradeSign(void) const
{
	return (_gradeSign);
}

int	Form::getGradeExec(void) const
{
	return (_gradeExec);
}

/*	Grade Functions --------------------------------------------------------- */

int	Form::_testGrade(int grade)
{
	try
	{
		if (grade < 1)
		{
			throw	GradeTooHighException();
		}
		else if (grade > 150)
		{
			throw	GradeTooLowException();
		}
	}
	catch(const GradeTooHighException& e)
	{
		std::cerr << RED << "[" << _name << "] " << e.what() << RESET << std::endl;
		std::cout << "└─> Trying for grade ──> " << grade << std::endl;
		grade = 1;
		std::cout << "└─> Going back to grade ──> " << grade << std::endl;
	}
	catch(const GradeTooLowException& e)
	{
		std::cerr << RED << "[" << _name << "] " << e.what() << RESET << std::endl;
		std::cout << "└─> Trying for grade ──> " << grade << std::endl;
		grade = 150;
		std::cout << "└─> Going back to grade ──> " << grade << std::endl;
	}
	return (grade);
}

/*	Printing ---------------------------------------------------------------- */

void	Form::printStatus(void) const
{
	std::cout << *this << std::endl;
}

std::ostream	&operator<<(std::ostream &o, Form const &rhs)
{
	o << BLUE << "Form" << RESET << std::endl;
	o << "└─> Name: " << rhs.getName() << std::endl;
	o << "└─> Signed: " << rhs.getSigned() << std::endl;
	o << "└─> Grade required to sign: " << rhs.getGradeSign() << std::endl;
	o << "└─> Grade required to execute: " << rhs.getGradeExec() << std::endl;
	return (o);
}

/*	Form -------------------------------------------------------------------- */

const char	*Form::beSigned(Bureaucrat const &brat)
{
	try
	{
		if (brat.getGrade() <= _gradeSign)
		{
			_signed = true;
			return (NULL);
		}
		else
		{
			_signed = false;	
			throw	GradeTooLowException();
		}
	}
	catch (const GradeTooLowException& e)
	{
		return (e.what());
	}
}
