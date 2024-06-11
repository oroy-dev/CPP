/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:34:26 by oroy              #+#    #+#             */
/*   Updated: 2024/06/11 17:32:43 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T>
class Array
{
private:

	T				*_a;
	unsigned int	_n;

	class InvalidIndex : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Invalid Index");
			}
	};

public:

	Array<T>(void);
	Array<T>(unsigned int n);
	Array<T>(Array<T> const &src);
	Array<T> &operator=(Array<T> const &rhs);
	~Array<T>();

	T				*operator[](unsigned int i) const;

	unsigned int	size(void) const;

};

# include "Array.tpp"

#endif
