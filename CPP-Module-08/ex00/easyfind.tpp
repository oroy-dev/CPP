/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:11:58 by oroy              #+#    #+#             */
/*   Updated: 2024/08/10 16:49:56 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
void	easyfind(T container, int entry)
{
	typename T::iterator it = std::find(container.begin(), container.end(), entry);

	if (it == container.end())
	{
		throw	entry;
	}
	std::cout << "Entry found: " << *it << std::endl;
}
