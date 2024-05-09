/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:03:09 by oroy              #+#    #+#             */
/*   Updated: 2024/02/02 16:08:46 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}

// My own test
// int	main(void)
// {
// 	Fixed a;
// 	Fixed b(12);
// 	Fixed c(0.5f);
// 	Fixed d(b);
// 	Fixed const e(21);
// 	Fixed const f(42.2f);

// 	std::cout << "[TEST1]		Operator = : " << "a = " << a << " e = " << e << "		| Result from operation: " << (a = e) << std::endl;
// 	std::cout << "[TEST2]		Operator > : " << "a = " << a << " b = " << b << "		| Result from operation: " << (a > b) << std::endl;
// 	std::cout << "[TEST3]		Operator < : " << "a = " << a << " b = " << b << "		| Result from operation: " << (a < b) << std::endl;
// 	a = b;
// 	std::cout << "[TEST4]		Operator >= : " << "a = " << a << " b = " << b << "		| Result from operation: " << (a >= b) << std::endl;
// 	--d;
// 	std::cout << "[TEST5]		Operator <= : " << "d = " << d << " b = " << b << "	| Result from operation: " << (d <= b) << std::endl;
// 	std::cout << "[TEST6]		Operator == : " << "d = " << d << " b = " << b << "	| Result from operation: " << (d == b) << std::endl;
// 	std::cout << "[TEST7]		Operator != : " << "d = " << d << " b = " << b << "	| Result from operation: " << (d != b) << std::endl;
// 	std::cout << "[TEST8]		Operator + : " << "a = " << a << " f = " << f << " b = " << b << "	| Result from operation: " << (a + f + b) << std::endl;
// 	std::cout << "[TEST9]		Operator - : " << "a = " << a << " b = " << b << "		| Result from operation: " << (a - b) << std::endl;
// 	std::cout << "[TEST10]	Operator * : " << "a = " << a << " b = " << b << "		| Result from operation: " << (a * b) << std::endl;
// 	std::cout << "[TEST11]	Operator / : " << "a = " << a << " b = " << b << "		| Result from operation: " << (a / b) << std::endl;
// 	std::cout << "[TEST12]	Operator ++i : " << "a = " << a << "			| Result from operation: " << ++a << std::endl;
// 	std::cout << "[TEST13]	Operator i++ : " << "a = " << a << "		| Result from operation: " << a++ << std::endl;
// 	std::cout << "a = " << a << std::endl;
// 	std::cout << "[TEST14]	Operator --i : " << "a = " << a << "		| Result from operation: " << --a << std::endl;
// 	std::cout << "[TEST15]	Operator i-- : " << "a = " << a << "		| Result from operation: " << a-- << std::endl;
// 	std::cout << "a = " << a << std::endl;
// 	std::cout << "[TEST16]	min: " << "d = " << d << " b = " << b << "			| Result from function: " << Fixed::min(d, b) << std::endl;
// 	std::cout << "[TEST17]	min (const): " << "e = " << e << " f = " << f << "		| Result from function: " << Fixed::min(e, f) << std::endl;
// 	std::cout << "[TEST18]	max: " << "d = " << d << " b = " << b << "			| Result from function: " << Fixed::max(d, b) << std::endl;
// 	std::cout << "[TEST19]	max (const): " << "e = " << e << " f = " << f << "		| Result from function: " << Fixed::max(e, f) << std::endl;
// 	return (0);
// }
