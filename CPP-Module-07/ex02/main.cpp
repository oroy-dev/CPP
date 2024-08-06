/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:33:09 by oroy              #+#    #+#             */
/*   Updated: 2024/08/05 21:32:04 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	try
	{
		// Empty Array

		Array<int>	arr_1;

		std::cout << "[Empty Array]" << std::endl;
		std::cout << "Size = " << arr_1.size() << std::endl;

		std::cout << std::endl;

		// Array with uint parameter

		Array<float>	arr_2(3);

		std::cout << "[Array with uint parameter]" << std::endl;
		std::cout << "Size = " << arr_2.size() << std::endl;
		std::cout << "arr_2 - Index 0: " << arr_2[0] << std::endl;
		std::cout << "arr_2 - Index 1: " << arr_2[1] << std::endl;
		std::cout << "arr_2 - Index 2: " << arr_2[2] << std::endl;

		std::cout << std::endl;

		// Array by copy

		arr_2[0] = 0.1f;
		arr_2[1] = 0.2f;
		arr_2[2] = 0.3f;

		Array<float>	arr_3(arr_2);

		std::cout << "[Array by copy]" << std::endl;
		std::cout << "Size = " << arr_3.size() << std::endl;
		std::cout << "arr_3 - Index 0: " << arr_3[0] << std::endl;
		std::cout << "arr_3 - Index 1: " << arr_3[1] << std::endl;
		std::cout << "arr_3 - Index 2: " << arr_3[2] << std::endl;
		std::cout << std::endl;

		arr_2[0] = 5.7f;

		std::cout << "└─> Deep Copy Check" << std::endl;
		std::cout << "arr_2 - Index 0: " << arr_2[0] << std::endl;
		std::cout << "arr_3 - Index 0: " << arr_3[0] << std::endl;

		std::cout << std::endl;

		// Assignment Test

		arr_2 = arr_3;

		std::cout << "[Assignment Test]" << std::endl;
		std::cout << "Size = " << arr_2.size() << std::endl;
		std::cout << "arr_2 - Index 0: " << arr_2[0] << std::endl;
		std::cout << "arr_2 - Index 1: " << arr_2[1] << std::endl;
		std::cout << "arr_2 - Index 2: " << arr_2[2] << std::endl;
		std::cout << std::endl;

		arr_3[2] = 4.2f;
		
		std::cout << "└─> Deep Copy Check" << std::endl;
		std::cout << "arr_2 - Index 2: " << arr_2[2] << std::endl;
		std::cout << "arr_3 - Index 2: " << arr_3[2] << std::endl;

		std::cout << std::endl;

		// String Array

		Array<std::string>	arr_4(5);

		arr_4[0] = "Yo";
		arr_4[1] = "Comment";
		arr_4[2] = "Ça";
		arr_4[3] = "Va";
		arr_4[4] = "Man ?";

		std::cout << "[String Array]" << std::endl;
		std::cout << "Size = " << arr_4.size() << std::endl;
		std::cout << arr_4[0] << " " << arr_4[1] << " " << arr_4[2] << " " << arr_4[3] << " " << arr_4[4] << std::endl;
	}
	catch(const InvalidIndex &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
