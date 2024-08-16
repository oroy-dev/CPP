/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:08:48 by oroy              #+#    #+#             */
/*   Updated: 2024/08/16 16:41:21 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static void	run(char const *arg)
{
	size_t								pos;
	std::ifstream						file(arg);
	std::map<std::string, std::string>	entries;
	std::string							line;
	std::string							date;
	std::string							value;

	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			pos = line.find('|');
			date = line.substr(0, pos);
			if (pos != std::string::npos)
				value = line.substr(pos);
			entries[date] = value;
		}
		file.close();
		for (std::map<std::string, std::string>::const_iterator it = entries.begin(); it != entries.end(); ++it)
		{
			std::cout << it->first << " == " << it->second << std::endl;
		}
		// BitcoinExchange	input(file);
	}
	else
	{
		std::cerr << "Error: could not open file." << std::endl;
	}
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
