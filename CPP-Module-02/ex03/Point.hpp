/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:20:33 by oroy              #+#    #+#             */
/*   Updated: 2024/02/02 17:55:18 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

#include "Fixed.hpp"

class Point
{
private:

	Fixed const	x;
	Fixed const	y;

public:

	Point(void);
	Point(float const f1, float const f2);
	Point(Point const &src);
	~Point(void);

	Point	&operator=(Point const &rhs);

	Fixed const	&getX(void) const;
	Fixed const	&getY(void) const;

};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
