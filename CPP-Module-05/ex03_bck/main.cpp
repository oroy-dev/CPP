/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:09:26 by oroy              #+#    #+#             */
/*   Updated: 2024/05/23 17:07:16 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int	main(void)
{
	Intern		someRandomIntern;
	Bureaucrat	squareEnix("SquareEnix", 2);

	// AForm	*none;
	// none = someRandomIntern.makeForm("", "");
	// squareEnix.signForm(*none);
	// squareEnix.executeForm(*none);

	AForm	*ppf;
	ppf = someRandomIntern.makeForm("presidential pardon", "Octo");
	squareEnix.signForm(*ppf);
	squareEnix.executeForm(*ppf);

	AForm	*rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Path");
	squareEnix.signForm(*rrf);
	squareEnix.executeForm(*rrf);

	AForm	*scf;
	scf = someRandomIntern.makeForm("shrubbery creation", "Traveler");
	squareEnix.signForm(*scf);
	squareEnix.executeForm(*scf);

	delete ppf;
	delete rrf;
	delete scf;

	return (0);
}
