/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:14:05 by oroy              #+#    #+#             */
/*   Updated: 2024/06/04 00:28:29 by olivierroy       ###   ########.fr       */
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

static void	*convert_string(std::string str, int type)
{
	void	*value;

	switch (type)
	{
		case 0: static_cast<char>(str);
		case 1: static_cast<int>(str);
		case 2: static_cast<float>(str);
		case 3: static_cast<double>(str);
	}
}

static int	getType(std::string::size_type len, bool dot, bool f, bool digit)
{
	if (!digit && len == 1)
		return (_CHAR);
	if (digit && !dot && !f)
		return (_INT);
	if (digit && dot && f)
		return (_FLOAT);
	if (digit && dot && !f)
		return (_DOUBLE);
	return (_STRING);
}

static int	detectType(std::string str)
{
	std::string::size_type	len;
	bool					digit;
	bool					dot;
	bool					f;

	f = false;
	dot = false;
	digit = true;
	len = str.length();
	for (std::string::size_type i = 0; i < len; i++)
	{
		if (!dot && i > 0 && i != len - 1 && str[i] == '.')
			dot = true;
		else if (i > 0 && i == len - 1 && str[i] == 'f')
			f = true;
		else if (!(str[i] >= '0' && str[i] <= '9'))
		{
			digit = false;
			break ;
		}
	}
	return (getType(len, dot, digit, f));
}

int	main(int argc, char **argv)
{
	std::string	str;
	int			type;
	void		*value;

	if (argc != 2)
	{
		std::cerr << "Please enter only one parameter" << std::endl;
		std::cerr << "└─> ./program_name \"parameter\"" << std::endl;
		return (1);
	}
	str = argv[1];
	type = detectType(str);
	if (type > -1)
		value = convert_string(str, type);
	return (0);
}
