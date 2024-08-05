/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:33:09 by oroy              #+#    #+#             */
/*   Updated: 2024/08/05 16:55:27 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	int			arr_i[3] = {-1, 0, 1};
	float		arr_f[5] = {0.1f, -2.5f, 3.6f, 4.1f, 5.0f};
	std::string	arr_s[2] = {"Allo", "Man"};

	std::cout << "-- Test: Array of ints --" << std::endl;
	iter(arr_i, sizeof(arr_i), f);
	std::cout << std::endl;
	
	std::cout << "-- Test: Array of floats --" << std::endl;
	iter(arr_f, sizeof(arr_f), f);
	std::cout << std::endl;

	std::cout << "-- Test: Array of strings --" << std::endl;
	iter(arr_s, sizeof(arr_s), f);
	std::cout << std::endl;

	return 0;
}
