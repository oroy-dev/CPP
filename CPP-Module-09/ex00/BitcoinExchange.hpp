/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:08:48 by oroy              #+#    #+#             */
/*   Updated: 2024/08/20 00:32:05 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <algorithm>
# include <cstring>
# include <fstream>
# include <iostream>
# include <map>
# include <sstream>
# include <string>

typedef struct s_date
{
	int	year;
	int	month;
	int	day;
}	t_date;

class BitcoinExchange
{
private:
	
	std::map<std::string const, std::string const>	_database;

	bool				_dateIsValid(std::string const &date) const;
	std::string const	_constructDate(t_date dateStruct) const;
	t_date				_createDateStruct(std::string const &date) const;
	void				_findInDatabase(t_date date) const;
	std::string const	_trim(std::string const &date) const;

public:

	BitcoinExchange(void);
	BitcoinExchange(BitcoinExchange const &src);
	BitcoinExchange &operator=(BitcoinExchange const &rhs);
	~BitcoinExchange();

	void	evaluate(const char *arg) const;

};

#endif
