/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:03:14 by oroy              #+#    #+#             */
/*   Updated: 2024/02/02 16:02:11 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors

Fixed::Fixed(void) : _n(0)
{
	return ;
}

Fixed::Fixed(int const n)
{
	setRawBits(n << _fracbits);
	return ;
}

Fixed::Fixed(float const f)
{
	setRawBits(roundf(f * (1 << _fracbits)));
	return ;
}

Fixed::Fixed(Fixed const &src)
{
	*this = src;
	return ;
}

Fixed::~Fixed(void)
{
	return ;
}

// Getter - Setter

int	Fixed::getRawBits(void) const
{
	return (_n);
}

void	Fixed::setRawBits(int const raw)
{
	_n = raw;
}

// Conversions

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(getRawBits()) / (1 << _fracbits));
}

int	Fixed::toInt(void) const
{
	return (getRawBits() >> _fracbits);
}

// Comparison Operators

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	setRawBits(rhs.getRawBits());
	return *this;
}

bool	Fixed::operator>(Fixed const &rhs) const
{
	return (getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const &rhs) const
{
	return (getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	return (getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	return (getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const &rhs) const
{
	return (getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
	return (getRawBits() != rhs.getRawBits());
}

// Arithmetic Operators

Fixed	Fixed::operator+(Fixed const &rhs) const
{
	Fixed	result;

	result._n = getRawBits() + rhs.getRawBits();
	return (result);
}

Fixed	Fixed::operator-(Fixed const &rhs) const
{
	Fixed	result;

	result._n = getRawBits() - rhs.getRawBits();
	return (result);
}

Fixed	Fixed::operator*(Fixed const &rhs) const
{
	Fixed	result;

	result._n = roundf((toFloat() * rhs.toFloat()) * (1 << _fracbits));
	return (result);
}

Fixed	Fixed::operator/(Fixed const &rhs) const
{
	Fixed	result;
	
	result._n = roundf((toFloat() / rhs.toFloat()) * (1 << _fracbits));
	return (result);
}

// ++ and -- operators

Fixed	&Fixed::operator++()
{
	setRawBits(getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;
	++(*this);
	return (temp);
}

Fixed	&Fixed::operator--()
{
	setRawBits(getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;
	--(*this);
	return (temp);
}

// Min - Max

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	return (a < b ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	return (a > b ? a : b);
}

// Outside Class

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o);
}
