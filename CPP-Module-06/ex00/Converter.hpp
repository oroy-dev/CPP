/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:39:52 by oroy              #+#    #+#             */
/*   Updated: 2024/06/04 01:08:46 by olivierroy       ###   ########.fr       */
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
# include <string>

class Converter
{
private:

	int		_type;
	char	_valueC;
	int		_valueI;
	float	_valueF;
	double	_valueD;

	void	_convertString(std::string str);
	void	_detectType(std::string str);
	int		_getType(size_t len, bool dot, bool f, bool digit) const;

public:

	Converter(std::string str);
	Converter(Converter const &src);
	Converter &operator=(Converter const &rhs);
	~Converter();

	char const		getChar(void) const;
	int const		getInt(void) const;
	float const		getFloat(void) const;
	double const	getDouble(void) const;

	void			setChar(char const valueC);
	void			setInt(int const valueI);
	void			setFloat(float const valueF);
	void			setDouble(double const valueD);

};

#endif
