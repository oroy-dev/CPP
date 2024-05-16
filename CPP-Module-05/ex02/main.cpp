/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:09:26 by oroy              #+#    #+#             */
/*   Updated: 2024/05/16 17:02:27 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{
	ShrubberyCreationForm	form;
	RobotomyRequestForm		form2("Dude");
	RobotomyRequestForm		form3;

	Bureaucrat				brat("Oli", 100);

	form.printStatus();

	brat.executeForm(form3);
	return (0);
}
