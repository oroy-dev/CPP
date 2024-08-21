/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:08:48 by oroy              #+#    #+#             */
/*   Updated: 2024/08/20 21:04:53 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <iostream>
# include <map>
# include <sstream>
# include <string>

class BitcoinExchange
{
private:
	
	std::map<std::string const, std::string const>	_database;

	bool				_databaseIsValid;

	bool				_dateIsValid(std::string const &date) const;
	bool				_isFloat(std::string const &number) const;
	bool				_valueIsValid(std::string const &value) const;
	std::string const &	_findInDatabase(std::string const &date);
	std::string const	_trim(std::string const &date) const;
	void				_printResult(std::string const &date, std::string const &rate, std::string const &value) const;

public:

	BitcoinExchange(void);
	BitcoinExchange(BitcoinExchange const &src);
	BitcoinExchange &operator=(BitcoinExchange const &rhs);
	~BitcoinExchange();

	bool	databaseIsValid(void) const;
	void	evaluate(const char *arg);

};

#endif
