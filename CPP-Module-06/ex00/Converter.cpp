/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:40:40 by oroy              #+#    #+#             */
/*   Updated: 2024/06/10 16:18:23 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

/*	Canonical Form Requirements --------------------------------------------- */

Converter::Converter(std::string str) : _str(str), _type(_STRING), _char(0), _int(0), _float(0), _double(0), _char_impossible(0), _int_impossible(0)
{
	_convertString();
	printResult();
	return ;
}

Converter::Converter(Converter const &src)
{
	*this = src;
	printResult();
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
	_char_impossible = rhs._char_impossible;
	_int_impossible = rhs._int_impossible;
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
	if (_type != _TOTALLY_IMPOSSIBLE)
		_convertOtherTypes();
}

void	Converter::_detectType(void)
{
	bool	sign = false;
	bool	digit = true;
	bool	dot = false;
	bool	f = false;
	size_t	len;

	len = _str.length();
	for (size_t i = 0; i < len; i++)
	{
		if (i == 0 && len > 1 && (_str[i] == '+' || _str[i] == '-'))
			sign = true;
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
	_type = _getType(len, digit, dot, f, sign);
}

int	Converter::_getType(size_t len, bool digit, bool dot, bool f, bool sign) const
{
	if ((dot && sign && len == 2) || (dot && f && sign && len == 3))
		return (_STRING); // Exceptions: "+.", "-.", "+.f", "-.f" 
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
		_type = _TOTALLY_IMPOSSIBLE;
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
		if (_checkIntOverflow(c, data, minus))
		{
			_type = _TOTALLY_IMPOSSIBLE;
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
		{
			multiplier /= 10.0f;
			data = data + static_cast<float>(c) * multiplier;
		}
		else
			data = data * 10.0f + static_cast<float>(c);
	}
	_float = data * static_cast<float>(minus);
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
		{
			multiplier /= 10.0;
			data = data + static_cast<double>(c) * multiplier;
		}
		else
			data = data * 10.0 + static_cast<double>(c);
	}
	_double = data * static_cast<double>(minus);
}

/*	Set Other Types --------------------------------------------------------- */

void	Converter::_convertOtherTypes(void)
{
	if (_type == _CHAR)
	{
		_int = static_cast<int>(_char);
		_float = static_cast<float>(_char);
		_double = static_cast<double>(_char);
	}
	else if (_type == _INT)
	{
		if (!(_int >= 0 && _int <= 127))
			_char_impossible = true;
		else
			_char = static_cast<char>(_int);
		_float = static_cast<float>(_int);
		_double = static_cast<double>(_int);
	}
	else if (_type == _FLOAT)
	{
		if (!(_float >= 0 && _float <= 127))
			_char_impossible = true;
		else
			_char = static_cast<char>(_float);
		if (_float != _float // Condition is true if float is NaN
			|| _float < std::numeric_limits<int>::min()
			|| _float > std::numeric_limits<int>::max())
			_int_impossible = true;
		else
			_int = static_cast<int>(_float);
		_double = static_cast<double>(_float);
	}
	else if (_type == _DOUBLE)
	{
		if (!(_double >= 0 && _double <= 127))
			_char_impossible = true;
		else
			_char = static_cast<char>(_double);
		if (_double != _double // Condition is true if double is NaN
			|| _double < std::numeric_limits<int>::min()
			|| _double > std::numeric_limits<int>::max())
			_int_impossible = true;
		else
			_int = static_cast<int>(_double);
		_float = static_cast<float>(_double);
	}
}

/*	Print ------------------------------------------------------------------- */

void	Converter::printResult(void) const
{
	if (_type == _TOTALLY_IMPOSSIBLE)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	else
	{
		if (_char_impossible)
			std::cout << "char: impossible" << std::endl;
		else if (!(_char >= 32 && _char <= 126))
			std::cout << "char: Non Displayable" << std::endl;
		else
			std::cout << "char: " << _char << std::endl;
		if (_int_impossible)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << _int << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << _float << "f" << std::endl;
		std::cout << "double: " << _double << std::endl;
	}
}

/*	Utils ------------------------------------------------------------------- */

bool	Converter::_checkIntOverflow(int c, int data, int minus) const
{
	if (data < 214748364 ||	(data == 214748364
		&& ((minus == 1 && c <= 7) || (minus == -1 && c <= 8))))
		return (false);
	else
		return (true);
}
