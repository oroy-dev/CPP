/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:39:52 by oroy              #+#    #+#             */
/*   Updated: 2024/06/04 21:35:50 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
# define CONVERTER_H

# define _STRING		-1
# define _CHAR			0
# define _INT			1
# define _FLOAT			2
# define _DOUBLE		3
# define _IMPOSSIBLE	4

# include <iostream>
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

	// int			_ft_stoi(std::string const str) const;

	// void		_setChar(char const valueC);
	void		_setInt(void);
	void		_setFloat(void);
	// void		_setDouble(double const valueD);

	void		_setOtherTypes(void);

public:

	Converter(std::string const str);
	// Converter(Converter const &src);
	// Converter &operator=(Converter const &rhs);
	~Converter();

	// char const		getChar(void) const;
	// int const		getInt(void) const;
	// float const		getFloat(void) const;
	// double const	getDouble(void) const;

	void			printResult(void) const;

};

#endif
