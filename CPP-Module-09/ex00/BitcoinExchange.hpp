/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:08:48 by oroy              #+#    #+#             */
/*   Updated: 2024/09/09 13:04:54 by oroy             ###   ########.fr       */
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
	bool				_dayAndMonthAreValid(int day, int month, int year) const;
	bool				_isFloat(std::string const &number) const;
	bool				_valueIsValid(std::string const &value) const;
	int					_findNumberOfDays(int month, int year) const;
	std::string const	_findInDatabase(std::string const &date) const;
	std::string const	_trim(std::string const &date) const;
	void				_printResult(std::string const &date, std::string const &rate, std::string const &value) const;

public:

	BitcoinExchange(void);
	BitcoinExchange(BitcoinExchange const &src);
	BitcoinExchange &operator=(BitcoinExchange const &rhs);
	~BitcoinExchange();

	bool				databaseIsValid(void) const;
	void				evaluate(const char *arg);

};

#endif
