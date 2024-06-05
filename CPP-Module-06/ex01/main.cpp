/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:14:05 by oroy              #+#    #+#             */
/*   Updated: 2024/06/05 17:20:05 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

static void	printData(Data &profile)
{
	std::cout << profile.name << " : " << profile.age << " years old" << std::endl;
}

static uintptr_t	serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

static Data	*deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int	main(void)
{
	Data		roberto = {"Roberto", 98};
	Data		*albertine = new Data();
	uintptr_t	raw;
	uintptr_t	raw2;

	albertine->name = "Albertine";
	albertine->age = 71;

	std::cout << std::endl;

	std::cout << "-- Initial Data --" << std::endl;
	printData(roberto);
	printData(*albertine);

	std::cout << std::endl;

	std::cout << "-- Serializing --" << std::endl;
	raw = serialize(&roberto);
	raw2 = serialize(albertine);
	std::cout << "Serialized data for Roberto: " << raw << std::endl;
	std::cout << "Serialized data for Albertine: " << raw2 << std::endl;

	std::cout << std::endl;

	std::cout << "-- Deserializing --" << std::endl;
	roberto = *deserialize(raw);
	albertine = deserialize(raw2);
	printData(roberto);
	printData(*albertine);

	std::cout << std::endl;

	delete	albertine;

	return (0);
}
