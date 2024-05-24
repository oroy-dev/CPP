/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:09:26 by oroy              #+#    #+#             */
/*   Updated: 2024/05/24 16:25:05 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	ShrubberyCreationForm	form1("jardin");
	RobotomyRequestForm		form2("Wall-E");
	PresidentialPardonForm	form3("Trump");

	Bureaucrat				olivier("Olivier", 2);
	Bureaucrat				ziggy("Ziggy", 21);
	Bureaucrat				cederic("Cederic", 72);
	Bureaucrat				po("PO", 45);

	std::cout << std::endl;

	form1.printStatus();
	form2.printStatus();
	form3.printStatus();

	// form1
	cederic.signForm(form1);
	cederic.executeForm(form1);

	std::cout << std::endl;

	// form2
	cederic.signForm(form2);
	cederic.executeForm(form2);
	po.executeForm(form2);

	std::cout << std::endl;

	// form3
	po.executeForm(form3);
	po.signForm(form3);
	ziggy.signForm(form3);
	olivier.signForm(form3);
	olivier.executeForm(form3);

	std::cout << std::endl;

	return (0);
}
