/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:21:48 by olivierroy        #+#    #+#             */
/*   Updated: 2024/02/06 00:08:16 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl    harl;
    
    if (argc != 2)
    {
        std::cerr << "Please provide only one argument" << std::endl;
		return (1);
    }
    harl.complain(argv[1]);
    return (0);
}
