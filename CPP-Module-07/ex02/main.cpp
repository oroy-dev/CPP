/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:33:09 by oroy              #+#    #+#             */
/*   Updated: 2024/06/12 16:37:31 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	// Empty Array

	Array<int>	arr_1;

	std::cout << "[Empty Array]" << std::endl;
	std::cout << arr_1.size() << std::endl;

	std::cout << std::endl;

	// Array with uint parameter

	Array<float>	arr_2(3);

	std::cout << "[Array with uint parameter]" << std::endl;
	std::cout << "arr_2 - Index 0: " << arr_2[0] << std::endl;
	std::cout << "arr_2 - Index 1: " << arr_2[1] << std::endl;
	std::cout << "arr_2 - Index 2: " << arr_2[2] << std::endl;

	std::cout << std::endl;

	// Array by copy

	Array<float>	arr_3(arr_2);

	std::cout << "[Array by copy]" << std::endl;

	arr_3[0] = 0.1f;
	arr_3[1] = 0.5f;
	arr_3[2] = 0.6f;

	arr_2[0] = 5.7f;

	std::cout << "arr_2 - Index 0: " << arr_2[0] << std::endl;
	std::cout << "arr_3 - Index 0: " << arr_3[0] << std::endl;

	std::cout << std::endl;

	// Assignment Test

	arr_2 = arr_3;

	std::cout << "[Assignment Test]" << std::endl;
	std::cout << "arr_2 - Index 0: " << arr_2[0] << std::endl;
	std::cout << "arr_2 - Index 1: " << arr_2[1] << std::endl;
	std::cout << "arr_2 - Index 2: " << arr_2[2] << std::endl;

	arr_2[2] = 4.2f;
	
	std::cout << std::endl;
	std::cout << "arr_2 - Index 2: " << arr_2[2] << std::endl;
	std::cout << "arr_3 - Index 2: " << arr_3[2] << std::endl;

	std::cout << std::endl;

	// Not accessible index

	std::cout << "[Index not accessible]" << std::endl;

	try
	{
		arr_3[5] = 9;
		std::cout << arr_3[5] << std::endl;
	}
	catch(const InvalidIndex &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	// String Array

	Array<std::string>	arr_4(5);

	arr_4[0] = "Yo";
	arr_4[1] = "Comment";
	arr_4[2] = "Ça";
	arr_4[3] = "Va";
	arr_4[4] = "Man ?";

	std::cout << "[String Array]" << std::endl;
	std::cout << arr_4[0] << " " << arr_4[1] << " " << arr_4[2] << " " << arr_4[3] << " " << arr_4[4] << std::endl;

	return 0;
}
