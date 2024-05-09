/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:03:09 by oroy              #+#    #+#             */
/*   Updated: 2024/02/02 17:55:23 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void )
{
	Point const	cop(10.8, 2);

	Point const	a(1, 2);
	Point const	b(5, 15);
	Point const	c(cop);

	Point const	point(4, 4);
	Point const	point2(11.8, 5);
	Point const	point3(5, 2);
	Point const	point4(10.8, 2);

	char		arr[25][25];

	for (int row = 0; row < 25; row++)
	{
		for (int col = 0; col < 25; col++)
			arr[row][col] = '.';
	}
	for (int row = 0; row < 25; row++)
	{
		if (roundf(a.getY().toFloat()) == 25 - row || roundf(b.getY().toFloat()) == 25 - row
			|| roundf(c.getY().toFloat()) == 25 - row || roundf(point.getY().toFloat()) == 25 - row
			|| roundf(point2.getY().toFloat()) == 25 - row || roundf(point3.getY().toFloat()) == 25 - row)
		{
			for (int col = 0; col < 25; col++)
			{
				if (roundf(a.getX().toFloat()) == col && roundf(a.getY().toFloat()) == 25 - row )
					arr[row][col] = 'A';
				else if (roundf(b.getX().toFloat()) == col && roundf(b.getY().toFloat()) == 25 - row)
					arr[row][col] = 'B';
				else if (roundf(c.getX().toFloat()) == col && roundf(c.getY().toFloat()) == 25 - row)
					arr[row][col] = 'C';
				else if (roundf(point.getX().toFloat()) == col && roundf(point.getY().toFloat()) == 25 - row)
					arr[row][col] = '1';
				else if (roundf(point2.getX().toFloat()) == col && roundf(point2.getY().toFloat()) == 25 - row)
					arr[row][col] = '2';
				else if (roundf(point3.getX().toFloat()) == col && roundf(point3.getY().toFloat()) == 25 - row)
					arr[row][col] = '3';
			}
		}
	}
	for (int row = 0; row < 25; row++)
	{
		for (int col = 0; col < 25; col++)
			std::cout << arr[row][col];
		std::cout << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Test - Inside: " << bsp(a, b, c, point) << std::endl;
	std::cout << "Test - Outside: " << bsp(a, b, c, point2) << std::endl;
	std::cout << "Test - On Line: " << bsp(a, b, c, point3) << std::endl;
	std::cout << "Test - On Point: " << bsp(a, b, c, point4) << std::endl;

	std::cout << std::endl;

	return (0);
}
