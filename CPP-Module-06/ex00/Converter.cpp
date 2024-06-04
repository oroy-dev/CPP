/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:40:40 by oroy              #+#    #+#             */
/*   Updated: 2024/06/04 15:51:28 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

/*	Canonical Form Requirements --------------------------------------------- */

Converter::Converter(std::string str) : _type(_STRING)
{
	_convertString(str);
	return ;
}

// Converter::Converter(Converter const &src)
// {
// 	*this = src;
// 	return ;
// }

// Converter	&Converter::operator=(Converter const &rhs)
// {
// 	_valueC = rhs._valueC;
// 	_valueI = rhs._valueI;
// 	_valueF = rhs._valueF;
// 	_valueD = rhs._valueD;
// 	return (*this);
// }

Converter::~Converter()
{
	return ;
}

/*	Getters/Setters --------------------------------------------------------- */

char const	Converter::getChar(void) const
{
	return (_valueC);
}

int const	Converter::getInt(void) const
{
	return (_valueI);
}

float const	Converter::getFloat(void) const
{
	return (_valueF);
}

double const	Converter::getDouble(void) const
{
	return (_valueD);
}

void	Converter::_setChar(char const valueC)
{
	_valueC = valueC;
}

void	Converter::_setInt(int const valueI)
{
	_valueI = valueI;
}

void	Converter::_setFloat(float const valueF)
{
	_valueF = valueF;
}

void	Converter::_setDouble(double const valueD)
{
	_valueD = valueD;
}

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

void	Converter::_detectType(std::string const str)
{
	size_t	len;
	bool	digit;
	bool	dot;
	bool	f;

	f = false;
	dot = false;
	digit = true;
	len = str.length();
	for (size_t i = 0; i < len; i++)
	{
		if (i == 0 && len > 1 && (str[i] == '+' || str[i] == '-'))
			continue ;
		else if (!dot && i > 0 && i != len - 1 && str[i] == '.')
			dot = true;
		else if (i > 0 && i == len - 1 && str[i] == 'f')
			f = true;
		else if (!(str[i] >= '0' && str[i] <= '9'))
		{
			digit = false;
			break ;
		}
	}
	_type = _getType(len, digit, dot, f);
}

void	Converter::_convertString(std::string const str)
{
	_detectType(str);
	switch (_type)
	{
		case 0: _setChar(str[0]); break;
		case 1: _setInt(_ft_stoi(str));
		case 2: ;
		case 3: ;
	}
}

/*	Utils ------------------------------------------------------------------- */

int	Converter::_ft_stoi(std::string const str) const
{
	size_t	data;
	bool	minus;

	data = 0;
	minus = false;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (i == 0 && str[i] == '-')
			minus = true;
		else
			data += str[i] - '0';
	}
	// if (minus)
		
}
