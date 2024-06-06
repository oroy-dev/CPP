/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:40:40 by oroy              #+#    #+#             */
/*   Updated: 2024/06/05 23:51:49 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

/*	Canonical Form Requirements --------------------------------------------- */

Converter::Converter(std::string str) : _str(str)
{
	_convertString();
	printResult();
	return ;
}

// Converter::Converter(Converter const &src)
// {
// 	*this = src;
// 	return ;
// }

// Converter	&Converter::operator=(Converter const &rhs)
// {
// 	_char = rhs._char;
// 	_int = rhs._int;
// 	_float = rhs._float;
// 	_double = rhs._double;
// 	return (*this);
// }

Converter::~Converter()
{
	return ;
}

/*	Functions --------------------------------------------------------------- */

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

void	Converter::_setOtherTypes(void)
{
	if (_type == _CHAR)
	{
		_int = static_cast<int>(_char);
		_float = static_cast<float>(_char);
		_double = static_cast<double>(_char);
	}
	else if (_type == _INT)
	{
		_char = static_cast<char>(_int);
		_float = static_cast<float>(_int);
		_double = static_cast<double>(_int);
	}
	else if (_type == _FLOAT)
	{
		_char = static_cast<char>(_float);
		_int = static_cast<int>(_float);
		_double = static_cast<double>(_float);
	}
	else if (_type == _DOUBLE)
	{
		_char = static_cast<char>(_double);
		_int = static_cast<int>(_double);
		_float = static_cast<float>(_double);
	}
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
		else if (!dot && i > 0 && i != len - 1 && _str[i] == '.')
			dot = true;
		else if (i > 0 && i == len - 1 && _str[i] == 'f')
			f = true;
		else if (!(_str[i] >= '0' && _str[i] <= '9'))
		{
			digit = false;
			break ;
		}
	}
	_type = _getType(len, digit, dot, f);
}

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
	if (_type != _IMPOSSIBLE)
		_setOtherTypes();
}

void	Converter::printResult(void) const
{
	if (_type == _IMPOSSIBLE)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	else
	{
		std::cout << "char: " << _char << std::endl;
		std::cout << "int: " << _int << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << _float << "f" << std::endl;
		std::cout << "double: " << _double << std::endl;
	}
}

/*	Conversions ------------------------------------------------------------- */

void	Converter::_toChar(void) const
{

}

void	Converter::_toInt(void) const
{
	
}

void	Converter::_toFloat(void) const
{
	
}

void	Converter::_toDouble(void) const
{
	
}

/*	Utils ------------------------------------------------------------------- */

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

bool	Converter::_checkIntOverflow(int minus, int data, int c) const
{
	if ((minus == 1 && data > std::numeric_limits<int>::max() - 10 - c) \
	|| (minus == -1 && -data < std::numeric_limits<int>::min() + 10 + c))
		return (true);
	return (false);
}
