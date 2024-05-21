/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:07:07 by oroy              #+#    #+#             */
/*   Updated: 2024/05/21 15:49:10 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/*	Canonical Form Requirements --------------------------------------------- */

AForm::AForm(void) : _name("DefaultForm"), _target("Default"), _gradeSign(150), _gradeExec(150)
{
	_signed = false;
	return ;
}

AForm::AForm(AForm const &src) : _name(src._name + "_copy"), _target(src._target), _gradeSign(src._gradeSign), _gradeExec(src._gradeExec)
{
	*this = src;
	return ;
}

AForm	&AForm::operator=(AForm const &rhs)
{
	_signed = rhs._signed;
	return (*this);
}

AForm::~AForm(void)
{
	std::cout << "[" << _name << "] AForm burned" << std::endl;
	return ;
}

/*	Additional Constructors ------------------------------------------------- */

AForm::AForm(std::string name, std::string target, int gradeSign, int gradeExec) : _name(name), _target(target), _gradeSign(_testGrade(gradeSign)), _gradeExec(_testGrade(gradeExec))
{
	_signed = false;
	return ;
}

/*	Getters ----------------------------------------------------------------- */

std::string const	AForm::getName(void) const
{
	return (_name);
}

std::string const	AForm::getTarget(void) const
{
	return (_target);
}

bool	AForm::getSigned(void) const
{
	return (_signed);
}

int	AForm::getGradeSign(void) const
{
	return (_gradeSign);
}

int	AForm::getGradeExec(void) const
{
	return (_gradeExec);
}

/*	Setters ----------------------------------------------------------------- */

void	AForm::setSigned(bool isSigned)
{
	_signed = isSigned;
}

/*	Grade Functions --------------------------------------------------------- */

int	AForm::_testGrade(int grade)
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

void	AForm::printStatus(void) const
{
	std::cout << *this << std::endl;
}

std::ostream	&operator<<(std::ostream &o, AForm const &rhs)
{
	o << BLUE << "Form" << RESET << std::endl;
	o << "└─> Name: " << rhs.getName() << std::endl;
	o << "└─> Signed: " << rhs.getSigned() << std::endl;
	o << "└─> Grade required to sign: " << rhs.getGradeSign() << std::endl;
	o << "└─> Grade required to execute: " << rhs.getGradeExec() << std::endl;
	return (o);
}

/*	AForm -------------------------------------------------------------------- */

const char	*AForm::beSigned(Bureaucrat const &brat)
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

const char	*AForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (!getSigned())
		{
			throw	FormNotSigned();
		}
		else if (executor.getGrade() > _gradeExec)
		{	
			throw	GradeTooLowException();
		}
		else
		{
			std::cout << BLUE << "Form Action" << RESET << std::endl;
			_doFormAction();
			std::cout << std::endl;
		}
	}
	catch (const FormNotSigned& e)
	{
		return (e.what());
	}
	catch (const GradeTooLowException& e)
	{
		return (e.what());
	}
	return (NULL);
}
