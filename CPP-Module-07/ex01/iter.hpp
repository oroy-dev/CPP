/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:34:26 by oroy              #+#    #+#             */
/*   Updated: 2024/08/05 19:02:02 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template <typename T>
void	f(T &data)
{
	std::cout << data << std::endl;
}

template <typename T>
void	iter(T *arr, size_t size, void (*f)(T &))
{
	for (size_t i = 0; i < size; ++i)
	{
		f(arr[i]);
	}
}

#endif
