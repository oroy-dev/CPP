/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:20:35 by oroy              #+#    #+#             */
/*   Updated: 2024/01/17 18:20:20 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iomanip>
# include <iostream>
# include <sstream>
# include <string>
# include "Contact.hpp"

# define CONTACT_TOTAL 8

class PhoneBook
{
private:

	bool		_is_positivenumber(std::string const str);
	std::string	_get_substr(std::string const str) const;

public:

	PhoneBook(void);
	~PhoneBook(void);
	
	Contact		contact[CONTACT_TOTAL];
	int			contact_idx;
	
	bool		add_contact(void);
	bool		get_contact_by_index(void);
	void		display_contact(Contact *contact) const;
	void		display_phonebook(void) const;

};

#endif
