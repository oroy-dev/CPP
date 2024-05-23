/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:09:26 by oroy              #+#    #+#             */
/*   Updated: 2024/05/15 13:45:46 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	Bob("Bob", 125);
	Bureaucrat	Dylan("Dylan", 57);

	Form		random;
	Form		eazypeezy("eazypeezy", 124, 100);
	Form		hellish("hellish", -2147483648, 2147483647);

	std::cout << std::endl;

	Bob.signForm(random);
	Bob.signForm(eazypeezy);

	Dylan.signForm(eazypeezy);
	Dylan.signForm(hellish);
	
	return (0);
}
