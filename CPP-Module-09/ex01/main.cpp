/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:01:25 by olivierroy        #+#    #+#             */
/*   Updated: 2024/09/09 17:00:47 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	RPN	*rpn;

	if (argc == 1)
	{
		std::cerr << "Please enter an argument" << std::endl;
		return 1;
	}
	rpn = new RPN(argv[1]);
	delete rpn;
	return 0;
}
