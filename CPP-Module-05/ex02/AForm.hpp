/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:42:47 by oroy              #+#    #+#             */
/*   Updated: 2024/05/16 16:56:06 by oroy             ###   ########.fr       */
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
protected:
	
	std::string const	_name;
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

public:
	
	AForm(void);
	AForm(AForm const &src);
	AForm &operator=(AForm const &rhs);
	virtual ~AForm(void);

	AForm(std::string name, int gradeSign, int gradeExec);
	
	std::string const	getName(void) const;
	bool				getSigned(void) const;
	int					getGradeSign(void) const;
	int					getGradeExec(void) const;

	void				printStatus(void) const;

	const char			*beSigned(Bureaucrat const &brat);
	const char			*execute(Bureaucrat const &executor) const;

};

std::ostream	&operator<<(std::ostream &o, AForm const &rhs);

#endif
