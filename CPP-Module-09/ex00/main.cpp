/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:08:48 by oroy              #+#    #+#             */
/*   Updated: 2024/08/20 00:24:48 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static void	run(const char *arg)
{
	BitcoinExchange	btc;

	btc.evaluate(arg);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	run(argv[1]);
}
