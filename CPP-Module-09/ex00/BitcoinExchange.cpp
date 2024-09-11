/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:01:25 by olivierroy        #+#    #+#             */
/*   Updated: 2024/09/11 15:28:58 by oroy             ###   ########.fr       */
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

	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		_databaseIsValid = false;
	}
	while (std::getline(file, line))
	{
		line = _trimWhiteSpace(line);
		if (line == "date,exchange_rate" || line.empty())
			continue ;
		pos = line.find(',');
		if (pos == std::string::npos)
		{
			_databaseIsValid = false;
			break ;
		}
		date = _trimWhiteSpace(line.substr(0, pos));
		if (!_dateIsValid(date))
		{
			_databaseIsValid = false;
			break ;
		}
		value = _trimWhiteSpace(line.substr(pos + 1));
		if (!_isFloat(value))
		{
			_databaseIsValid = false;
			break ;
		}
		_database.insert(std::pair<std::string const, std::string const>(date, value));
	}
	file.close();
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
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

/* Private */

// std::get_time

bool	BitcoinExchange::_dayAndMonthAreValid(int day, int month, int year) const
{
	int	daysInMonth;

	if (!(month >= 1 && month <= 12))
		return false;
	daysInMonth = _findNumberOfDays(month, year);
	if (!(day >= 1 && day <= daysInMonth))
		return false;
	return true;
}

bool	BitcoinExchange::_dateIsValid(std::string const &date) const
{
	std::string const	pattern = "YYYY-MM-DD";
	int					day = 0;
	int					month = 0;
	int					year = 0;
	ssize_t				i = -1;

	if (date.size() != pattern.size())
		return false;
	while (date[++i])
	{
		if (pattern[i] == '-' && date[i] == '-')
			continue ;
		else if (pattern[i] == 'Y' && strchr("0123456789", date[i]))
			year = (year * 10) + (date[i] - '0');
		else if (pattern[i] == 'M' && strchr("0123456789", date[i]))
			month = (month * 10) + (date[i] - '0');
		else if (pattern[i] == 'D' && strchr("0123456789", date[i]))
			day = (day * 10) + (date[i] - '0');
		else
			return false;
	}
	if (!_dayAndMonthAreValid(day, month, year))
		return false;
	return true;
}

bool	BitcoinExchange::_isFloat(std::string const &number) const
{
	std::istringstream	iss(_trimFloat(number));
	float				f;

	iss >> f;
	if (iss.fail())
		return false;
	return true;
}

bool	BitcoinExchange::_valueIsValid(std::string const &value) const
{
	std::istringstream	iss(_trimFloat(value));
	float				f;

	iss >> f;
	if (iss.fail())
	{
		std::cerr << "Error: invalid number => " << value << std::endl;
		return false;
	}
	if (f < 0)
	{
		std::cerr << "Error: not a positive number => " << f << std::endl;
		return false;
	}
	if (f > 1000)
	{
		std::cerr << "Error: too large a number => " << f << std::endl;
		return false;
	}
	return true;
}

int	BitcoinExchange::_findNumberOfDays(int month, int year) const
{
	switch (month)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			return 31;
		case 4: case 6: case 9: case 11:
			return 30;
		case 2:
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
				return 29;
			else
				return 28;
		default:
			return -1;
	}
}

std::string const	BitcoinExchange::_findInDatabase(std::string const &date) const
{
	std::map<std::string const, std::string const>::const_iterator	it;

	it = _database.lower_bound (date);
	if (it->first != date)
	{
		if (it == _database.begin())
			return "";
		--it;
	}
	// std::cout << it->first << std::endl;
	return it->second;
}

std::string const	BitcoinExchange::_trimFloat(std::string const &value) const
{
	if (value.back() != 'f' || value.find('.') == std::string::npos)
		return value;
	return value.substr(0, value.size() - 1);
}

std::string const	BitcoinExchange::_trimWhiteSpace(std::string const &date) const
{
	size_t	startPos = date.find_first_not_of(" \t");
	size_t	endPos = date.find_last_not_of(" \t");

	if (startPos == std::string::npos || endPos == std::string::npos)
		return "";
	return date.substr(startPos, endPos - startPos + 1);
}

void	BitcoinExchange::_printResult(std::string const &date, std::string const &rate, std::string const &value) const
{
	float				fRate;
	float				fValue;
	std::istringstream	iRate(_trimFloat(rate));
	std::istringstream	iValue(_trimFloat(value));

	iRate >> fRate;
	iValue >> fValue;
	std::cout << date << " => " << value << " = " << fRate * fValue << std::endl;
}

/* Public */

bool	BitcoinExchange::databaseIsValid(void) const
{
	return _databaseIsValid;
}

void	BitcoinExchange::evaluate(const char *arg)
{
	std::ifstream	file(arg);
	std::string		line;
	std::string		date;
	std::string		value;
	std::string		rate;
	size_t			pos;

	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}
	while (std::getline(file, line))
	{
		if (line.empty())
			continue ;
		pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}
		date = _trimWhiteSpace(line.substr(0, pos));
		if (!_dateIsValid(date))
		{
			std::cerr << "Error: invalid date => " << date << std::endl;
			continue ;
		}
		value = _trimWhiteSpace(line.substr(pos + 1));
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
