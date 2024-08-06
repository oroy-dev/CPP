/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:34:26 by oroy              #+#    #+#             */
/*   Updated: 2024/08/05 21:45:28 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>
# include <string>

template <typename T>
class Array
{
private:

	T				*_a;
	unsigned int	_n;

public:

	Array<T>(void);
	Array<T>(unsigned int n);
	Array<T>(Array<T> const &src);
	Array<T> &operator=(Array<T> const &rhs);
	~Array<T>();

	T				&operator[](unsigned int i) const;

	unsigned int	size(void) const;

};

class InvalidIndex : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Invalid Index");
		}
};

# include "Array.tpp"

#endif
