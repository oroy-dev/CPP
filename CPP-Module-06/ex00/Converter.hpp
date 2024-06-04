/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:39:52 by oroy              #+#    #+#             */
/*   Updated: 2024/06/03 15:51:25 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
# define CONVERTER_H

class Converter
{
private:

	char	_valueC;
	int		_valueI;
	float	_valueF;
	double	_valueD;

public:

	Converter(void);
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
