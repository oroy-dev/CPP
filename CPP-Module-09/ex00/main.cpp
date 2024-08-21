/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:08:48 by oroy              #+#    #+#             */
/*   Updated: 2024/08/20 20:33:18 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static void	run(const char *arg)
{
	BitcoinExchange	btc;

	if (btc.databaseIsValid())
		btc.evaluate(arg);
	else
		std::cerr << "Error: invalid database" << std::endl;
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
