/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:40:40 by oroy              #+#    #+#             */
/*   Updated: 2024/06/04 23:56:02 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

/*	Canonical Form Requirements --------------------------------------------- */

Converter::Converter(std::string const str) : _str(str), _type(_STRING)
{
	_convertString();
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

// /*	Getters/Setters --------------------------------------------------------- */

// char const	Converter::getChar(void) const
// {
// 	return (_char);
// }

// int const	Converter::getInt(void) const
// {
// 	return (_int);
// }

// float const	Converter::getFloat(void) const
// {
// 	return (_float);
// }

// double const	Converter::getDouble(void) const
// {
// 	return (_double);
// }

// void	Converter::_setChar(char const valueC)
// {
// 	_char = valueC;
// }

// void	Converter::_setInt(int const valueI)
// {
// 	_int = valueI;
// }

// void	Converter::_setFloat(float const valueF)
// {
// 	_float = valueF;
// }

// void	Converter::_setDouble(double const valueD)
// {
// 	_double = valueD;
// }

/*	Functions --------------------------------------------------------------- */

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

void	Converter::_convertString(void)
{
	_detectType();
	switch (_type)
	{
		case -1: _checkExceptions(); break;
		case 0: _char = _str[0]; break;
		case 1: _setInt(); break;
		case 2: _setFloat(); break;
		case 3: ;
	}
	if (_type != _IMPOSSIBLE)
		_setOtherTypes();
	printResult();
}

void	Converter::_setInt(void)
{
	int		c;
	int		data;
	bool	minus;

	data = 0;
	minus = false;
	for (size_t i = 0; i < _str.length(); i++)
	{
		c = _str[i] - '0';
		if ((!minus && data > std::numeric_limits<int>::max() - 10 - c)
			|| (minus && -data < std::numeric_limits<int>::min() + 10 + c))
		{
			_type = _IMPOSSIBLE;
			return ;
		}
		if (i == 0 && (_str[i] == '-' || _str[i] == '+'))
		{
			if (_str[i] == '-')
				minus = true;
			continue ;
		}
		data = data * 10 + c;
	}
	if (minus)
		_int = -data;
	else
		_int = data;
}

void	Converter::_setFloat(void)
{
	int		c;
	float	data;
	bool	minus;

	data = 0;
	minus = false;
	for (size_t i = 0; i < _str.length(); i++)
	{
		c = _str[i] - '0';
		if ((!minus && data > std::numeric_limits<float>::max() - 10 - c)
			|| (minus && -data < std::numeric_limits<float>::min() + 10 + c))
		{
			_type = _IMPOSSIBLE;
			return ;
		}
		if (i == 0 && (_str[i] == '-' || _str[i] == '+'))
		{
			if (_str[i] == '-')
				minus = true;
			continue ;
		}
		data = data * 10 + c;
	}
	if (minus)
		_float = -data;
	else
		_float = data;
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
		if (!(_char >= 32 && _char <= 126))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: " << _char << std::endl;
	}
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

// int	Converter::_ft_stoi(std::string const str) const
// {
// 	size_t	data;
// 	bool	minus;

// 	data = 0;
// 	minus = false;
// 	for (size_t i = 0; i < str.length(); i++)
// 	{
// 		if (i == 0 && str[i] == '-')
// 			minus = true;
// 		else
// 			data += str[i] - '0';
// 	}
// 	// if (minus)
		
// }
