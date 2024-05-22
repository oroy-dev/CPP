/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:32:05 by oroy              #+#    #+#             */
/*   Updated: 2024/05/21 16:03:39 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <stdexcept>
# include <string>

# include "AForm.hpp"

# define RESET	"\033[0m"
# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"

class AForm;

class Bureaucrat
{
private:
	
	std::string const	_name;
	int					_grade;

	void				_testGrade(void);

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

	Bureaucrat(void);
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat &operator=(Bureaucrat const &rhs);
	~Bureaucrat(void);

	Bureaucrat(int grade);
	Bureaucrat(std::string const name);
	Bureaucrat(std::string const name, int grade);
	
	std::string const	getName(void) const;
	int					getGrade(void) const;

	void				decrementGrade(void);
	void				incrementGrade(void);

	void				printStatus(void) const;

	void				signForm(AForm &form) const;
	void				executeForm(AForm const &form) const;

};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif
