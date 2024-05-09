/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:28:08 by oroy              #+#    #+#             */
/*   Updated: 2024/01/29 14:18:57 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void	create_output(std::string s1, std::string s2, std::ifstream &ifs, std::ofstream &ofs)
{
	std::string::size_type	len;
	std::string::size_type	pos;
	std::string				line;

	len = s1.length();
	while (ifs.good())
	{
		std::getline(ifs, line);
		while ((pos = line.find(s1)) != std::string::npos)
		{
			line.erase(pos, len);
			line.insert(pos, s2);
		}
		ofs << line;
		if (!ifs.eof())
			ofs << std::endl;
	}
}

int	main(int argc, char **argv)
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		ifs_name, ofs_name;

	if (argc != 4)
	{
		std::cerr << "\033[1;33m[ERROR]\033[0m	Please provide the required arguments (3):" << std::endl;
		std::cerr << "	<filename>, <string to find>, <string used as replacement>" << std::endl;
		return (1);
	}
	ifs.open(argv[1]);
	if (!ifs.is_open())
	{
		std::cerr << "\033[1;33m[ERROR]\033[0m	Could not open file. Please check permissions." << std::endl;
		return (1);
	}
	ifs_name = argv[1];
	ofs_name = ifs_name + ".replace";
	ofs.open(ofs_name);
	create_output(argv[2], argv[3], ifs, ofs);
	ifs.close();
	ofs.close();
	return (0);
}
