/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:22:32 by oroy              #+#    #+#             */
/*   Updated: 2024/01/17 18:19:41 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	// std::cout << "PhoneBook instance created" << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	// std::cout << "PhoneBook instance destroyed" << std::endl;
	return ;
}

bool	PhoneBook::_is_positivenumber(std::string const str)
{
	std::string::const_iterator	it;

	it = str.begin();
	while (it != str.end() && std::isdigit(*it))
		it++;
	return (!str.empty() && it == str.end());
}

std::string	PhoneBook::_get_substr(std::string const str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	else
		return (str);
}

bool	PhoneBook::add_contact(void)
{
	std::cout << std::endl;
	if (!contact[contact_idx].set_contact())
		return (false);
	std::cout << std::endl;
	contact_idx = ++contact_idx % CONTACT_TOTAL;
	return (true);
}

void	PhoneBook::display_contact(Contact *contact) const
{
	std::cout << std::endl;
	std::cout << "First Name: " << contact->get_firstname() << std::endl;
	std::cout << "Last Name: " << contact->get_lastname() << std::endl;
	std::cout << "Nick Name: " << contact->get_nickname() << std::endl;
	std::cout << "Phone Number: " << contact->get_phonenumber() << std::endl;
	std::cout << "Darkest Secret: " << contact->get_darkestsecret() << std::endl;
	std::cout << std::endl;
}

void	PhoneBook::display_phonebook(void) const
{
	std::cout << std::endl;
	std::cout << std::right << std::setw(10) << "Index" << '|';
	std::cout << std::right << std::setw(10) << "First Name" << '|';
	std::cout << std::right << std::setw(10) << "Last Name" << '|';
	std::cout << std::right << std::setw(10) << "Nick Name" << std::endl;
	for (int i = 0; i < CONTACT_TOTAL; i++)
	{
		std::cout << std::right << std::setw(10) << i + 1 << '|';
		std::cout << std::right << std::setw(10) << _get_substr(contact[i].get_firstname()) << '|';
		std::cout << std::right << std::setw(10) << _get_substr(contact[i].get_lastname()) << '|';
		std::cout << std::right << std::setw(10) << _get_substr(contact[i].get_nickname()) << std::endl;
	}
	std::cout << std::endl;
}

bool	PhoneBook::get_contact_by_index(void)
{
	std::string	idx_str;
	int			idx_num;

	while (1)
	{
		std::cout << "Enter index to display (1 to " << CONTACT_TOTAL << "): ";
		getline(std::cin, idx_str);
		if (_is_positivenumber(idx_str))
		{
			std::istringstream(idx_str) >> idx_num;
			if (idx_num > 0 && idx_num <= CONTACT_TOTAL)
			{
				display_contact(&contact[idx_num - 1]);
				break ;
			}
		}
		else if (std::cin.eof())
			return (false);
		std::cout << "[Incorrect value] ";
	}
	return (true);
}
