/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:39:52 by oroy              #+#    #+#             */
/*   Updated: 2024/06/04 15:24:58 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
# define CONVERTER_H

# define _STRING	-1
# define _CHAR		0
# define _INT		1
# define _FLOAT		2
# define _DOUBLE	3

# include <iostream>
# include <limits>
# include <string>

class Converter
{
private:

	int		_type;
	char	_valueC;
	int		_valueI;
	float	_valueF;
	double	_valueD;

	void	_convertString(std::string const str);
	void	_detectType(std::string const str);
	int		_getType(size_t len, bool digit, bool dot, bool f) const;

	int		_ft_stoi(std::string const str) const;

	void	_setChar(char const valueC);
	void	_setInt(int const valueI);
	void	_setFloat(float const valueF);
	void	_setDouble(double const valueD);

public:

	Converter(std::string str);
	// Converter(Converter const &src);
	// Converter &operator=(Converter const &rhs);
	~Converter();

	char const		getChar(void) const;
	int const		getInt(void) const;
	float const		getFloat(void) const;
	double const	getDouble(void) const;


};

#endif
