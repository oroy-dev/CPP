/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:09:26 by oroy              #+#    #+#             */
/*   Updated: 2024/05/24 15:12:56 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	Bob("Bob", 125);
	Bureaucrat	Dylan("Dylan", 57);

	Form		eazypeezy("eazypeezy", 124, 100);
	Form		hellish("hellish", -2147483648, 2147483647);

	Form		*flying;

	std::cout << std::endl;

	Bob.signForm(eazypeezy);

	Dylan.signForm(eazypeezy);
	Dylan.signForm(hellish);

	Bob.signForm(eazypeezy);
	
	flying = new Form(Form("Flying", 100, 50));
	flying->beSigned(Bob);
	Dylan.signForm(*flying);

	std::cout << std::endl;

	delete	flying;
	
	return (0);
}
