/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:11:58 by oroy              #+#    #+#             */
/*   Updated: 2024/08/15 16:13:17 by oroy             ###   ########.fr       */
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
