/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:24:21 by oroy              #+#    #+#             */
/*   Updated: 2024/01/17 18:21:09 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	myphonebook;
	std::string	cmd;

	myphonebook.contact_idx = 0;
	while (1)
	{
		std::cout << "Please enter a command (ADD, SEARCH, EXIT): ";
		getline(std::cin, cmd);
		if (cmd == "ADD")
		{
			if (!myphonebook.add_contact())
				break ;
		}
		else if (cmd == "SEARCH")
		{
			myphonebook.display_phonebook();
			if (!myphonebook.get_contact_by_index())
				break ;
		}
		else if (cmd == "EXIT" || std::cin.eof())
			break ;
	}
	return (0);
}
