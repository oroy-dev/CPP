/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:36:27 by oroy              #+#    #+#             */
/*   Updated: 2024/05/10 16:41:37 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*	Canonical Form Requirements --------------------------------------------- */

Bureaucrat::Bureaucrat(void)
{
	std::cout << "Default constructor called" << std::endl;
	_name = "Fonctionnaire" + _getBureaucratIncrement();
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	std::cout << "Constructor by copy called" << std::endl;
	*this = src;
	return ; 
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	std::cout << "Assignment to instance called" << std::endl;
	this->_grade = rhs._grade;
	this->_name = rhs._name;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor called" << std::endl;
	return ; 
}

/*	Add-ons ----------------------------------------------------------------- */

void	Bureaucrat::getGrade(void) const
{
	std::cout << _grade << std::endl;
}

void	Bureaucrat::getName(void) const
{
	std::cout << _name << std::endl;
}

void	Bureaucrat::decrementGrade(void)
{
	_grade++;
}

void	Bureaucrat::incrementGrade(void)
{
	_grade--;
}

void	Bureaucrat::operator<<(void) const
{
	std::cout << _name << "bureaucrat grade" << _grade << std::endl;
}

int	Bureaucrat::_getBureaucratIncrement(void)
{
	_inc = ++inc % 151;
	if (_inc == 0)
		++_inc;
	return (_inc);
}

int	Bureaucrat::_inc = 0;