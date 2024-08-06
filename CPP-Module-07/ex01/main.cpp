/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:33:09 by oroy              #+#    #+#             */
/*   Updated: 2024/08/05 19:02:12 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	int			arr_i[3] = {-1, 0, 1};
	float		arr_f[5] = {0.1f, -2.5f, 3.6f, 4.1f, 5.0f};
	char		arr_c[9] = "abcd \0gh";
	std::string	arr_s[2] = {"Allo", "Man"};

	std::cout << "-- Test: Array of ints --" << std::endl;
	std::cout << "Size of array = " << sizeof(arr_i)/sizeof(arr_i[0]) << std::endl; 
	iter(arr_i, 3, f);
	std::cout << std::endl;
	
	std::cout << "-- Test: Array of floats --" << std::endl;
	std::cout << "Size of array = " << sizeof(arr_f)/sizeof(arr_f[0]) << std::endl; 
	iter(arr_f, 5, f);
	std::cout << std::endl;

	std::cout << "-- Test: Array of chars --" << std::endl;
	std::cout << "Size of array = " << sizeof(arr_c)/sizeof(arr_c[0]) << std::endl; 
	iter(arr_c, 9, f);
	std::cout << std::endl;

	std::cout << "-- Test: Array of strings --" << std::endl;
	std::cout << "Size of array = " << sizeof(arr_s)/sizeof(arr_s[0]) << std::endl; 
	iter(arr_s, 2, f);
	std::cout << std::endl;

	return 0;
}
