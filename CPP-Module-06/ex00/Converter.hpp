/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:39:52 by oroy              #+#    #+#             */
/*   Updated: 2024/06/09 14:07:52 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://stackoverflow.com/questions/4392665/converting-string-to-float-without-atof-in-c
// https://www.programiz.com/cpp-programming/string-float-conversion

#ifndef CONVERTER_H
# define CONVERTER_H

# define _STRING				-1
# define _CHAR					0
# define _INT					1
# define _FLOAT					2
# define _DOUBLE				3
# define _TOTALLY_IMPOSSIBLE	4

# include <iostream>
# include <sstream>
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

	bool		_char_impossible;
	bool		_int_impossible;
	
	bool		_checkIntOverflow(int c, int data, int minus) const;

	void		_convertString(void);
	void		_detectType(void);
	int			_getType(size_t len, bool digit, bool dot, bool f, bool sign) const;

	void		_checkExceptions(void);
	void		_setChar(void);
	void		_setInt(void);
	void		_setFloat(void);
	void		_setDouble(void);

	void		_convertOtherTypes(void);

public:

	Converter(std::string const str);
	Converter(Converter const &src);
	Converter &operator=(Converter const &rhs);
	~Converter();

	// void		printAllTypes(void) const;
	void		printResult(void) const;

};

#endif
