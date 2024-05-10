/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:32:05 by oroy              #+#    #+#             */
/*   Updated: 2024/05/10 16:41:27 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <string>

class Bureaucrat
{
private:
	
	std::string _name;
	int			_grade;

	static int	_inc;
	int			_getBureaucratIncrement(void);

public:

	Bureaucrat(void);
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat &operator=(Bureaucrat const &rhs);
	~Bureaucrat(void);
	
	void	getGrade(void) const;
	void	getName(void) const;

	void	decrementGrade(void);
	void	incrementGrade(void);

	void	operator<<(void) const;

};

#endif
