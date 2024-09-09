/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:08:48 by oroy              #+#    #+#             */
/*   Updated: 2024/09/09 16:29:48 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static bool	run(const char *arg)
{
	BitcoinExchange	btc;

	if (!btc.databaseIsValid())
	{
		std::cerr << "Error: invalid database" << std::endl;
		return false;
	}
	btc.evaluate(arg);
	return true;
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	if (!run(argv[1]))
		return 1;
}
