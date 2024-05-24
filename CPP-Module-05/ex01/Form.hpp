/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:42:47 by oroy              #+#    #+#             */
/*   Updated: 2024/05/24 15:33:09 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# include <iostream>
# include <string>

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	
	std::string const	_name;
	bool				_signed;
	int const			_gradeSign;
	int const			_gradeExec;

	int					_testGrade(int grade);

	class FormAlreadySigned : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Form is already signed");
			}
	};

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Grade is too high");
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Grade is too low");
			}
	};

public:
	
	Form(std::string name, int gradeSign, int gradeExec);
	Form(Form const &src);
	Form &operator=(Form const &rhs);
	~Form();
	
	std::string const	getName(void) const;
	bool				getSigned(void) const;
	int					getGradeSign(void) const;
	int					getGradeExec(void) const;

	void				printStatus(void) const;

	const char			*beSigned(Bureaucrat const &brat);

};

std::ostream	&operator<<(std::ostream &o, Form const &rhs);

#endif
