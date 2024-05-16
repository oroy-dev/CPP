/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:42:47 by oroy              #+#    #+#             */
/*   Updated: 2024/05/16 16:11:38 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RobotomyRequestForm_H
# define RobotomyRequestForm_H

# include <cstdlib>
# include <iostream>
# include <string>

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:

	void	_robotize(std::string target) const;
	
public:
	
	RobotomyRequestForm(void);
	RobotomyRequestForm(RobotomyRequestForm const &src);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
	~RobotomyRequestForm(void);

	RobotomyRequestForm(std::string target);

};

#endif
