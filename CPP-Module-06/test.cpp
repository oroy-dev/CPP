/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:13:17 by oroy              #+#    #+#             */
/*   Updated: 2024/06/05 18:35:40 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>

int	main(void)
{
	double	num;

	std::cout << std::fixed << std::numeric_limits<double>::max() << std::endl;
	std::cout << -std::numeric_limits<double>::max() << std::endl;
	std::cout << std::numeric_limits<double>::min() << std::endl;

	num = -std::numeric_limits<double>::max() * 10.0;

	if (num < -std::numeric_limits<double>::max())
		std::cout << "Hello" << std::endl;

	std::cout << num << std::endl;

	return (0);	
}
