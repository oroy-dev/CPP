/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:40:40 by oroy              #+#    #+#             */
/*   Updated: 2024/06/06 19:06:37 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

/*	Canonical Form Requirements --------------------------------------------- */

Converter::Converter(std::string str) : _str(str), _type(_STRING), _char(0), _int(0), _float(0), _double(0)
{
	_convertString();
	printAllTypes();
	return ;
}

Converter::Converter(Converter const &src)
{
	*this = src;
	printAllTypes();
	return ;
}

Converter	&Converter::operator=(Converter const &rhs)
{
	_str = rhs._str;
	_type = rhs._type;
	_char = rhs._char;
	_int = rhs._int;
	_float = rhs._float;
	_double = rhs._double;
	return (*this);
}

Converter::~Converter()
{
	return ;
}

/*	Set Initial Type -------------------------------------------------------- */

void	Converter::_convertString(void)
{
	_detectType();
	switch (_type)
	{
		case _STRING: _checkExceptions(); break;
		case _CHAR: _setChar(); break;
		case _INT: _setInt(); break;
		case _FLOAT: _setFloat(); break;
		case _DOUBLE: _setDouble(); break;
	}
}

void	Converter::_detectType(void)
{
	size_t	len;
	bool	digit;
	bool	dot;
	bool	f;

	f = false;
	dot = false;
	digit = true;
	len = _str.length();
	for (size_t i = 0; i < len; i++)
	{
		if (i == 0 && len > 1 && (_str[i] == '+' || _str[i] == '-'))
			continue ;
		else if (!dot && len > 1 && _str[i] == '.')
			dot = true;
		else if (i > 1 && i == len - 1 && _str[i] == 'f')
			f = true;
		else if (!(_str[i] >= '0' && _str[i] <= '9'))
		{
			digit = false;
			break ;
		}
	}
	_type = _getType(len, digit, dot, f);
}

int	Converter::_getType(size_t len, bool digit, bool dot, bool f) const
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

void	Converter::_checkExceptions(void)
{
	if (_str == "-inff" || _str == "inff" || _str == "nanf")
	{
		_type = _FLOAT;
		if (_str == "nanf")
			_float = std::numeric_limits<float>::quiet_NaN();
		else if (_str == "-inff")
			_float = -std::numeric_limits<float>::infinity();
		else if (_str == "inff")
			_float = std::numeric_limits<float>::infinity();
	}
	else if (_str == "-inf" || _str == "inf" || _str == "nan")
	{
		_type = _DOUBLE;
		if (_str == "nan")
			_double = std::numeric_limits<double>::quiet_NaN();
		else if (_str == "-inf")
			_double = -std::numeric_limits<double>::infinity();
		else if (_str == "inf")
			_double = std::numeric_limits<double>::infinity();
	}
	else
		_type = _IMPOSSIBLE;
}

void	Converter::_setChar(void)
{
	_char = _str[0];
}

void	Converter::_setInt(void)
{
	int		c;
	int		data = 0;
	int		minus = 1;
	size_t	i = 0;

	if (_str[0] == '-' || _str[0] == '+')
	{
		if (_str[0] == '-')
			minus = -1;
		i++;
	}
	while (i < _str.length())
	{
		c = _str[i] - '0';
		if (_checkIntOverflow(minus, data, c))
		{
			_type = _IMPOSSIBLE;
			return ;
		}
		data = data * 10 + c;
		i++;
	}
	_int = data * minus;
}

void	Converter::_setFloat(void)
{
	int		c;
	int		minus = 1;
	float	multiplier = 1;
	float	data = 0;
	size_t	i = 0;

	if (_str[0] == '-' || _str[0] == '+')
	{
		if (_str[0] == '-')
			minus = -1;
		i++;
	}
	for (bool point_seen = false; i < _str.length() - 1; i++)
	{
		if (_str[i] == '.')
		{
			point_seen = true;
			continue ;
		}
		c = _str[i] - '0';
		if (point_seen)
			multiplier /= 10.0f;
		data = data * 10.0f + static_cast<float>(c);
	}
	_float = data * multiplier * static_cast<float>(minus);
}

void	Converter::_setDouble(void)
{
	int		c;
	int		minus = 1;
	double	multiplier = 1;
	double	data = 0;
	size_t	i = 0;

	if (_str[0] == '-' || _str[0] == '+')
	{
		if (_str[0] == '-')
			minus = -1;
		i++;
	}
	for (bool point_seen = false; i < _str.length(); i++)
	{
		if (_str[i] == '.')
		{
			point_seen = true;
			continue ;
		}
		c = _str[i] - '0';
		if (point_seen)
			multiplier /= 10.0;
		data = data * 10.0 + static_cast<double>(c);
	}
	_double = data * multiplier * static_cast<double>(minus);
}

/*	Print ------------------------------------------------------------------- */

void	Converter::printAllTypes(void) const
{
	if (_type == _CHAR)
	{
		std::cout << "char: " << _char << std::endl;
		std::cout << "int: " << static_cast<int>(_char) << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(_char) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(_char) << std::endl;
	}
	else if (_type == _INT)
	{
		// Char Printing
		if (!(_int >= 0 && _int <= 127))
			std::cout << "char: impossible" << std::endl;
		else if (!(_int >= 32 && _int <= 126))
			std::cout << "char: Non Displayable" << std::endl;
		else
			std::cout << "char: " << static_cast<char>(_int) << std::endl;
		// Int Printing
		std::cout << "int: " << _int << std::endl;
		// Float Printing
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(_int) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(_int) << std::endl;
	}
	else if (_type == _FLOAT)
	{
		// Char Printing
		if (!(_float >= 0 && _float <= 127))
			std::cout << "char: impossible" << std::endl;
		else if (!(_float >= 32 && _float <= 126))
			std::cout << "char: Non Displayable" << std::endl;
		else
			std::cout << "char: " << static_cast<char>(_float) << std::endl;
		// Int Printing
		if (_float != _float || _float < std::numeric_limits<int>::min() || _float > std::numeric_limits<int>::max())
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(_float) << std::endl;
		// Float Printing
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << _float << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(_float) << std::endl;
	}
	else if (_type == _DOUBLE)
	{
		// Char Printing
		if (!(_double >= 0 && _double <= 127))
			std::cout << "char: impossible" << std::endl;
		else if (!(_double >= 32 && _double <= 126))
			std::cout << "char: Non Displayable" << std::endl;
		else
			std::cout << "char: " << static_cast<char>(_double) << std::endl;
		// Int Printing
		if (_double != _double || _double < std::numeric_limits<int>::min() || _double > std::numeric_limits<int>::max())
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(_double) << std::endl;
		// Float Printing
		std::cout << std::fixed;
		std::cout << "float: " << static_cast<float>(_double) << "f" << std::endl;
		std::cout << "double: " << _double << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

/*	Utils ------------------------------------------------------------------- */

bool	Converter::_checkIntOverflow(int minus, int data, int c) const
{
	if ((minus == 1 && data > std::numeric_limits<int>::max() - 10 - c) \
	|| (minus == -1 && -data < std::numeric_limits<int>::min() + 10 + c))
		return (true);
	return (false);
}
