/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:14:05 by oroy              #+#    #+#             */
/*   Updated: 2024/05/28 23:32:20 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#define _STRING	-1
#define	_CHAR	0
#define	_INT	1
#define	_FLOAT	2
#define	_DOUBLE	3

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

static int	correctType(std::string::size_type i, bool comma, bool f, bool digit)
{
	if (!digit && i == 0)
		return (_CHAR);
	if (digit && !comma && !f)
		return (_INT);
	if (digit && comma && f)
		return (_FLOAT);
	if (digit && comma && !f)
		return (_DOUBLE);
	return (_STRING);
}

static int	detectType(std::string str)
{
	std::string::size_type	i;
	size_t					len;
	bool					comma = false;
	bool					digit = true;
	bool					f = false;

	len = str.length();
	for (i = 0; i < len; i++)
	{
		if (!comma && i > 0 && i != len - 1 && str[i] == ',')
			comma = true;
		else if (i > 0 && i == len - 1 && str[i] == 'f')
			f = true;
		else if (!(str[i] >= '0' && str[i] <= '9'))
		{
			digit = false;
			break ;
		}
	}
	return (correctType(i, comma, digit, f));
}

int	main(int argc, char **argv)
{
	std::string	str;
	int			type;

	if (argc != 2)
	{
		std::cerr << "Please enter only one parameter" << std::endl;
		std::cerr << "└─> ./program_name \"parameter\"" << std::endl;
		return (1);
	}
	str = argv[1];
	type = detectType(str);
	convert(str);
	return (0);
}
