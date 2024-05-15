/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:42:47 by oroy              #+#    #+#             */
/*   Updated: 2024/05/15 15:14:58 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ShrubberyCreationForm_H
# define ShrubberyCreationForm_H

# include <iostream>
# include <fstream>
# include <string>

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:

	std::string	_getAscii(void) const;
	void		_writeShrubbery(std::string target) const;
	
public:
	
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(ShrubberyCreationForm const &src);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm(std::string target);

};

#endif
