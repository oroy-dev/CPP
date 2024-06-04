/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:40:40 by oroy              #+#    #+#             */
/*   Updated: 2024/06/03 15:54:39 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

/*	Canonical Form Requirements --------------------------------------------- */

Converter::Converter(/* args */)
{
}

Converter::~Converter()
{
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

void	Converter::setChar(char const valueC)
{
	_valueC = valueC;
}

void	Converter::setInt(int const valueI)
{
	_valueI = valueI;
}

void	Converter::setFloat(float const valueF)
{
	_valueF = valueF;
}

void	Converter::setDouble(double const valueD)
{
	_valueD = valueD;
}

/*	Functions --------------------------------------------------------------- */

