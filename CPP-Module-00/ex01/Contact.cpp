/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:19:23 by oroy              #+#    #+#             */
/*   Updated: 2024/01/17 18:20:57 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	// std::cout << "Contact instance created" << std::endl;
	return ;
}

Contact::~Contact(void)
{
	// std::cout << "Contact instance destroyed" << std::endl;
	return ;
}

std::string	Contact::get_firstname(void) const
{
	return (_firstname);
}

std::string	Contact::get_lastname(void) const
{
	return (_lastname);
}

std::string	Contact::get_nickname(void) const
{
	return (_nickname);
}

std::string	Contact::get_phonenumber(void) const
{
	return (_phonenumber);
}

std::string	Contact::get_darkestsecret(void) const
{
	return (_darkestsecret);
}

bool	Contact::_set_field(std::string field, std::string *input)
{
	while (1)
	{
		std::cout << field;
		getline (std::cin, *input);
		if (!input->empty())
			break ;
		if (std::cin.eof())
			return (false);
		std::cout << "[Field cannot be empty]: ";
	}
	return (true);
}

bool	Contact::set_contact(void)
{
	if (!_set_field("First Name: ", &_firstname)
		|| !_set_field("Last Name: ", &_lastname)
		|| !_set_field("Nick Name: ", &_nickname)
		|| !_set_field("Phone Number: ", &_phonenumber)
		|| !_set_field("Darkest Secret: ", &_darkestsecret))
		return (false);
	return (true);
}
