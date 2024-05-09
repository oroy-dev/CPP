/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:20:36 by oroy              #+#    #+#             */
/*   Updated: 2024/02/02 17:54:14 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0)
{
	return ;
}

Point::Point(float const f1, float const f2) : x(f1), y(f2)
{
	return ;
}

Point::Point(Point const &src)
{
	*this = src;
	return ;
}

Point::~Point(void)
{
	return ;
}

Point	&Point::operator=(Point const &rhs)
{
	const_cast<Fixed &>(this->x) = rhs.x;
	const_cast<Fixed &>(this->y) = rhs.y;
	return (*this);
}

Fixed const	&Point::getX(void) const
{
	return (x);
}

Fixed const	&Point::getY(void) const
{
	return (y);
}
