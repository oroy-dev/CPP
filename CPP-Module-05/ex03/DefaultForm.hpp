/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DefaultForm.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:42:47 by oroy              #+#    #+#             */
/*   Updated: 2024/05/25 17:18:26 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFAULTFORM_H
# define DEFAULTFORM_H

# include <iostream>
# include <string>

# include "AForm.hpp"

class DefaultForm : public AForm
{
private:

	void	_doFormAction(void) const;

public:
	
	DefaultForm(std::string target);
	DefaultForm(DefaultForm const &src);
	DefaultForm &operator=(DefaultForm const &rhs);
	~DefaultForm();
};

#endif
