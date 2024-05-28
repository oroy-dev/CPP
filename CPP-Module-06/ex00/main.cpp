/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:14:05 by oroy              #+#    #+#             */
/*   Updated: 2024/05/27 22:07:16 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

static void	print()
{
	std::cout << "char: " << "getValue(char);" << std::endl;
	std::cout << "int: " << "getValue(int);" << std::endl;
	std::cout << "float: " << "getValue(float);" << std::endl;
	std::cout << "double: " << "getValue(double);" << std::endl;
}

static void	convert(std::string str)
{

}

static void	detectType(std::string str)
{
	std::string::size_type	i;
	bool					letter = false;
	bool					comma = false;
	bool					f = false;
	
	for (i = 0; i < str.length(); i++)
	{
		if (!letter && str[i] >= 'a' && str[i] <= 'z')
			letter = true;
	}
}

int	main(int argc, char **argv)
{
	std::string	str;

	if (argc != 2)
	{
		std::cerr << "Please enter only one parameter" << std::endl;
		std::cerr << "└─> ./program_name \"parameter\"" << std::endl;
		return (1);
	}
	str = argv[1];
	detectType(str);
	convert(str);
	return (0);
}
