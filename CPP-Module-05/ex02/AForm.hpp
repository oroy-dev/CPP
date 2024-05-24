/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:42:47 by oroy              #+#    #+#             */
/*   Updated: 2024/05/24 16:29:23 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
# define AFORM_H

# include <iostream>
# include <string>

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	
	std::string const	_name;
	std::string const	_target;
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

	class FormNotSigned : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Form not signed");
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

	virtual void	_doFormAction(void) const = 0;

protected:

	void			setSigned(bool isSigned);

public:
	
	AForm(std::string name, std::string target, int gradeSign, int gradeExec);
	AForm(AForm const &src);
	AForm &operator=(AForm const &rhs);
	virtual ~AForm();
	
	std::string const	getName(void) const;
	std::string const	getTarget(void) const;
	bool				getSigned(void) const;
	int					getGradeSign(void) const;
	int					getGradeExec(void) const;

	void				printStatus(void) const;

	const char			*beSigned(Bureaucrat const &brat);
	const char			*execute(Bureaucrat const &executor) const;

};

std::ostream	&operator<<(std::ostream &o, AForm const &rhs);

#endif
