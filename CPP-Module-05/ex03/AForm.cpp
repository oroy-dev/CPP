/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:07:07 by oroy              #+#    #+#             */
/*   Updated: 2024/05/24 16:31:44 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/*	Canonical Form Requirements --------------------------------------------- */

AForm::AForm(std::string name, std::string target, int gradeSign, int gradeExec) : _name(name), _target(target), _gradeSign(_testGrade(gradeSign)), _gradeExec(_testGrade(gradeExec))
{
	_signed = false;
	std::cout << "[" << _name << "] Form created" << std::endl;
	return ;
}

AForm::AForm(AForm const &src) : _name(src._name + "_copy"), _target(src._target), _gradeSign(src._gradeSign), _gradeExec(src._gradeExec)
{
	*this = src;
	std::cout << "[" << _name << "] Form created by copy" << std::endl;
	return ;
}

AForm	&AForm::operator=(AForm const &rhs)
{
	_signed = rhs._signed;
	std::cout << "[" << _name << "] Copied 'signed' attribute from " << rhs._name << std::endl;
	return (*this);
}

AForm::~AForm(void)
{
	std::cout << "[" << _name << "] AForm burned" << std::endl;
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
		if (_signed)
		{
			throw	FormAlreadySigned();
		}
		else if (brat.getGrade() > _gradeSign)
		{
			throw	GradeTooLowException();
		}
		else
			_signed = true;
	}
	catch (const FormAlreadySigned& e)
	{
		return (e.what());
	}
	catch (const GradeTooLowException& e)
	{
		return (e.what());
	}
	return (NULL);
}

const char	*AForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (!_signed)
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
