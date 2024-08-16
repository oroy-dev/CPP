/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:08:48 by oroy              #+#    #+#             */
/*   Updated: 2024/08/16 16:00:02 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <iostream>
# include <map>
# include <string>

class BitcoinExchange
{
private:
	
	std::map<std::string, float>	_database;

public:
	BitcoinExchange(/* args */);
	~BitcoinExchange();
};

#endif
