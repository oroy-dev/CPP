/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:14:05 by oroy              #+#    #+#             */
/*   Updated: 2024/06/04 01:12:06 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int	main(int argc, char **argv)
{
	Converter	*convert = NULL;

	if (argc != 2)
	{
		std::cerr << "Please enter only one parameter" << std::endl;
		std::cerr << "└─> ./program_name \"parameter\"" << std::endl;
		return (1);
	}
	convert = new Converter(argv[1]);
	delete	convert;
	return (0);
}
