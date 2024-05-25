/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:09:26 by oroy              #+#    #+#             */
/*   Updated: 2024/05/25 16:22:25 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int	main(void)
{
	Intern		someRandomIntern;
	Bureaucrat	squareEnix("SquareEnix", 2);

	std::cout << std::endl;

	AForm	*ppf;
	ppf = someRandomIntern.makeForm("presidential pardon", "Octo");
	squareEnix.signForm(*ppf);
	squareEnix.executeForm(*ppf);

	std::cout << std::endl;

	AForm	*rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Path");
	squareEnix.signForm(*rrf);
	squareEnix.executeForm(*rrf);

	std::cout << std::endl;

	AForm	*scf;
	scf = someRandomIntern.makeForm("shrubbery creation", "Traveler");
	squareEnix.signForm(*scf);
	squareEnix.executeForm(*scf);

	std::cout << std::endl;

	delete ppf;
	delete rrf;
	delete scf;

	return (0);
}
