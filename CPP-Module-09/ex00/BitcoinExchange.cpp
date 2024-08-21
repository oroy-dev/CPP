/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:01:25 by olivierroy        #+#    #+#             */
/*   Updated: 2024/08/21 00:25:45 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* Canonical */

BitcoinExchange::BitcoinExchange(void) : _databaseIsValid(true)
{
	std::ifstream	file("data.csv");
	std::string		line;
	std::string		date;
	std::string		value;
	size_t			pos;

	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			line = _trim(line);
			if (line == "date,exchange_rate" || line.empty())
				continue ;
			pos = line.find(',');
			if (pos == std::string::npos)
			{
				_databaseIsValid = false;
				break ;
			}
			date = _trim(line.substr(0, pos));
			if (!_dateIsValid(date))
			{
				_databaseIsValid = false;
				break ;
			}
			value = _trim(line.substr(pos + 1));
			if (!_isFloat(value))
			{
				_databaseIsValid = false;
				break ;
			}
			_database.insert(std::pair<std::string const, std::string const>(date, value));
		}
		file.close();
	}
	else
	{
		std::cerr << "Error: could not open file." << std::endl;
		_databaseIsValid = false;
	}
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	if (this != &rhs)
	{
		_database = rhs._database;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

/* Private */

bool	BitcoinExchange::_dateIsValid(std::string const &date) const
{
	std::string const	pattern = "YYYY-MM-DD";
	ssize_t				i = -1;

	while (date[++i])
	{
		if ((pattern[i] == 'Y' && strchr("0123456789", date[i])) \
		||	(pattern[i] == 'M' && strchr("0123456789", date[i])) \
		||	(pattern[i] == 'D' && strchr("0123456789", date[i])))
			continue ;
		else if (pattern[i] == '-' && date[i] == '-')
			continue ;
		else
			return (false);
	}
	if (pattern[i])
		return (false);
	return (true);
}

bool	BitcoinExchange::_isFloat(std::string const &number) const
{
	std::istringstream	iss(number);
	float				f;

	iss >> f;
	if (iss.fail() || !iss.eof())
		return (false);
	return (true);
}

bool	BitcoinExchange::_valueIsValid(std::string const &value) const
{
	std::istringstream	iss(value);
	float				f;

	iss >> f;
	if (iss.fail() || !iss.eof())
	{
		std::cerr << "Error: invalid number => " << value << std::endl;
		return (false);
	}
	if (f < 0)
	{
		std::cerr << "Error: not a positive number => " << f << std::endl;
		return (false);
	}
	if (f > 1000)
	{
		std::cerr << "Error: too large a number => " << f << std::endl;
		return (false);
	}
	return (true);
}

std::string const	&BitcoinExchange::_findInDatabase(std::string const &date)
{
	std::pair<std::map<std::string const, std::string const>::const_iterator, bool>	rtn;

	rtn = _database.insert(std::pair<std::string const, std::string const>(date, ""));
	if (rtn.second == true)	// Meaning a new element was inserted in the map
	{
		--rtn.first;
		_database.erase(date);
	}
	return (rtn.first->second);
}

std::string const	BitcoinExchange::_trim(std::string const &date) const
{
	size_t	startPos = date.find_first_not_of(" \t");
	size_t	endPos = date.find_last_not_of(" \t");

	if (startPos == std::string::npos || endPos == std::string::npos)
		return ("");
	return (date.substr(startPos, endPos + 1));
}

void	BitcoinExchange::_printResult(std::string const &date, std::string const &rate, std::string const &value) const
{
	float				fRate;
	float				fValue;
	std::istringstream	iRate(rate);
	std::istringstream	iValue(value);

	iRate >> fRate;
	iValue >> fValue;
	std::cout << date << " => " << value << " = " << fRate * fValue << std::endl; 
}

/* Public */

bool	BitcoinExchange::databaseIsValid(void) const
{
	return (_databaseIsValid);
}

void	BitcoinExchange::evaluate(const char *arg)
{
	std::ifstream	file(arg);
	std::string		line;
	std::string		date;
	std::string		value;
	std::string		rate;
	size_t			pos;

	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			pos = line.find('|');
			if (pos == std::string::npos)
			{
				std::cerr << "Error: bad input => " << line << std::endl;
				continue ;
			}
			date = _trim(line.substr(0, pos));
			if (!_dateIsValid(date))
			{
				std::cerr << "Error: invalid date => " << date << std::endl;
				continue ;
			}
			value = _trim(line.substr(pos + 1));
			if (!_valueIsValid(value))
				continue ;
			rate = _findInDatabase(date);
			if (rate.empty())
			{
				std::cerr << "Error: no entry found => " << date << std::endl;
				continue ;
			}
			_printResult(date, rate, value);
		}
		file.close();
	}
	else
	{
		std::cerr << "Error: could not open file." << std::endl;
	}
}
