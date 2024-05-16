/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:42:47 by oroy              #+#    #+#             */
/*   Updated: 2024/05/15 23:21:49 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPardonForm_H
# define PresidentialPardonForm_H

# include <iostream>
# include <string>

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:

	void	_pardon(std::string target) const;

public:
	
	PresidentialPardonForm(void);
	PresidentialPardonForm(PresidentialPardonForm const &src);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);
	~PresidentialPardonForm(void);

	PresidentialPardonForm(std::string target);

};

#endif
