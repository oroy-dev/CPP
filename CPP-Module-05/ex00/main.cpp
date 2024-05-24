/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:09:26 by oroy              #+#    #+#             */
/*   Updated: 2024/05/24 14:23:44 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	random("", '0');
	Bureaucrat	po("PO", 150);
	Bureaucrat	ced("Ced", 2);
	Bureaucrat	copycat("Copycat", 67);
	Bureaucrat	*copycat2 = new Bureaucrat(ced);

	std::cout << std::endl;

	random.printStatus();

	std::cout << std::endl;

	po.printStatus();
	po.decrementGrade();
	po.printStatus();

	std::cout << std::endl;

	ced.printStatus();
	ced.incrementGrade();
	ced.printStatus();
	ced.incrementGrade();
	ced.printStatus();

	std::cout << std::endl;

	copycat.printStatus();
	copycat.incrementGrade();
	copycat.printStatus();
	copycat = Bureaucrat("random", -2147483648);
	copycat.printStatus();

	std::cout << std::endl;

	copycat2->printStatus();
	copycat2->decrementGrade();
	copycat2->printStatus();
	
	std::cout << std::endl;

	delete	copycat2;
	
	return (0);
}
