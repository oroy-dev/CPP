/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:09:26 by oroy              #+#    #+#             */
/*   Updated: 2024/05/17 18:22:05 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	ShrubberyCreationForm	form;
	RobotomyRequestForm		form2("Dude");
	PresidentialPardonForm	form3("Ziggy");

	Bureaucrat				brat("Oli", 2);

	form.printStatus();

	brat.signForm(form3);
	brat.executeForm(form3);

	return (0);
}
