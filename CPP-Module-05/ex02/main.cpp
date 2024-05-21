/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:09:26 by oroy              #+#    #+#             */
/*   Updated: 2024/05/21 16:02:46 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	ShrubberyCreationForm	form1("Jardin");
	RobotomyRequestForm		form2("Wall-E");
	PresidentialPardonForm	form3("Trump");

	Bureaucrat				olivier("Olivier", 2);
	Bureaucrat				ziggy("Ziggy", 21);
	Bureaucrat				cederic("Cederic", 72);
	Bureaucrat				ecole42("Ecole", 45);

	form1.printStatus();
	form2.printStatus();
	form3.printStatus();

	cederic.signForm(form1);
	cederic.executeForm(form1);
	cederic.signForm(form2);
	cederic.executeForm(form2);

	ecole42.executeForm(form2);
	ecole42.executeForm(form3);
	ecole42.signForm(form3);
	ziggy.signForm(form3);
	olivier.signForm(form3);
	olivier.executeForm(form3);

	return (0);
}
