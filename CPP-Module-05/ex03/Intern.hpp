/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:10:38 by olivierroy        #+#    #+#             */
/*   Updated: 2024/05/24 16:50:53 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

# define NUMBER_OF_FORMS 3

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
private:

	static std::string	forms[NUMBER_OF_FORMS];
	AForm				*_getForm(unsigned int i, std::string target) const;

public:

	Intern(void);
	Intern(Intern const &src);
	Intern &operator=(Intern const &rhs);
	~Intern();

	AForm	*makeForm(std::string name, std::string target) const;

};

#endif
