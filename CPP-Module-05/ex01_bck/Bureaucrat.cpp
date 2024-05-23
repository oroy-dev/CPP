/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:36:27 by oroy              #+#    #+#             */
/*   Updated: 2024/05/15 15:13:27 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*	Canonical Form Requirements --------------------------------------------- */

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150)
{
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name + "_copy")
{
	*this = src;
	return ;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	this->_grade = rhs._grade;
	std::cout << "[" << _name << "] Copied grade from " << rhs._name << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "[" << _name << "] Bureaucrat destroyed" << std::endl;
	return ;
}

/*	Additional Constructors ------------------------------------------------- */

Bureaucrat::Bureaucrat(std::string const name) : _name(name), _grade(150)
{
	return ;
}

Bureaucrat::Bureaucrat(int grade) : _name("Unnamed"), _grade(grade)
{
	_testGrade();
	return ;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade)
{
	_testGrade();
	return ;
}

/*	Getters ----------------------------------------------------------------- */

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

std::string const	Bureaucrat::getName(void) const
{
	return (_name);
}

/*	Grade Functions --------------------------------------------------------- */

void	Bureaucrat::decrementGrade(void)
{
	++_grade;
	std::cout << "[" << _name << "] " << "Grade Decremented" << std::endl;
	_testGrade();
}

void	Bureaucrat::incrementGrade(void)
{
	--_grade;
	std::cout << "[" << _name << "] " << "Grade Incremented" << std::endl;
	_testGrade();
}

void	Bureaucrat::_testGrade(void)
{
	try
	{
		if (_grade < 1)
		{
			throw	GradeTooHighException();
		}
		else if (_grade > 150)
		{
			throw	GradeTooLowException();
		}
	}
	catch(const GradeTooHighException& e)
	{
		std::cerr << RED << "[" << _name << "] " << e.what() << RESET << std::endl;
		std::cout << "└─> Trying for grade ──> " << _grade << std::endl;
		_grade = 1;
		std::cout << "└─> Going back to grade ──> " << _grade << std::endl;
	}
	catch(const GradeTooLowException& e)
	{
		std::cerr << RED << "[" << _name << "] " << e.what() << RESET << std::endl;
		std::cout << "└─> Trying for grade ──> " << _grade << std::endl;
		_grade = 150;
		std::cout << "└─> Going back to grade ──> " << _grade << std::endl;
	}
}

/*	Printing ---------------------------------------------------------------- */

void	Bureaucrat::printStatus(void) const
{
	std::cout << GREEN << *this << RESET << std::endl;
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << "[" << rhs.getName() << "] bureaucrat grade " << rhs.getGrade();
	return (o);
}

/*	Form -------------------------------------------------------------------- */

void	Bureaucrat::signForm(Form &form) const
{
	const char	*error;
	
	error = form.beSigned(*this);
	if (form.getSigned())
		std::cout << GREEN << _name << " signed " << form.getName() << RESET << std::endl;
	else
		std::cout << RED << _name << " couldn't sign " << form.getName() << " because " << error << RESET << std::endl;
	std::cout << "└─> Bureaucrat Grade ──> " << _grade << std::endl;
	form.printStatus();
}
