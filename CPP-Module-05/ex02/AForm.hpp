/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:42:47 by oroy              #+#    #+#             */
/*   Updated: 2024/05/17 19:19:03 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_H
# define AForm_H

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

	class FormNotSigned : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Form not signed");
			}
	};

	virtual void	_doFormAction(void) const = 0;

public:
	
	AForm(void);
	AForm(AForm const &src);
	AForm &operator=(AForm const &rhs);
	virtual ~AForm(void);

	AForm(std::string name, std::string target, int gradeSign, int gradeExec);
	
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
