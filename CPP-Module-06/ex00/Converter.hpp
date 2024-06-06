/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:39:52 by oroy              #+#    #+#             */
/*   Updated: 2024/06/06 16:55:08 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://stackoverflow.com/questions/4392665/converting-string-to-float-without-atof-in-c

#ifndef CONVERTER_H
# define CONVERTER_H

# define _STRING		-1
# define _CHAR			0
# define _INT			1
# define _FLOAT			2
# define _DOUBLE		3
# define _IMPOSSIBLE	4

# include <iostream>
# include <iomanip>
# include <limits>
# include <string>

class Converter
{
private:

	std::string	_str;
	int			_type;

	char		_char;
	int			_int;
	float		_float;
	double		_double;

	void		_checkExceptions(void);

	void		_convertString(void);
	void		_detectType(void);
	int			_getType(size_t len, bool digit, bool dot, bool f) const;

	void		_setChar(void);
	void		_setInt(void);
	void		_setFloat(void);
	void		_setDouble(void);

	void		_setOtherTypes(void);

	bool		_checkIntOverflow(int minus, int data, int c) const;

public:

	Converter(std::string const str);
	Converter(Converter const &src);
	Converter &operator=(Converter const &rhs);
	~Converter();

	void		printAllTypes(void) const;

};

#endif
