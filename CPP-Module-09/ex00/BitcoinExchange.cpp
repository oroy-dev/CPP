/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olivierroy <olivierroy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:01:25 by olivierroy        #+#    #+#             */
/*   Updated: 2024/08/20 00:35:58 by olivierroy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* Canonical */

BitcoinExchange::BitcoinExchange(void)
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
			pos = line.find(',');
			date = line.substr(0, pos);
			if (pos != std::string::npos)
				value = line.substr(pos + 1);
			else
				value = "";
			_database.insert(std::pair<std::string const, std::string const>(date, value));
			// _database[date] = value;
		}
		file.close();
	}
	else
	{
		std::cerr << "Error: could not open file." << std::endl;
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

std::string const	BitcoinExchange::_constructDate(t_date dateStruct) const
{
	std::string	date;

	date = dateStruct.year + '-' + dateStruct.month + '-' + dateStruct.day;

	return (date);
}

t_date	BitcoinExchange::_createDateStruct(std::string const &date) const
{
	t_date				dateStruct;
	std::string			tmp = date;
	std::istringstream	iss;

	std::replace(tmp.begin(), tmp.end(), '-', ' ');
	iss.str(tmp);
	iss >> dateStruct.year;
	iss >> dateStruct.month;
	iss >> dateStruct.day;
	return (dateStruct);
}

void	BitcoinExchange::_findInDatabase(t_date dateStruct) const
{
	std::map<std::string const, std::string const>::const_iterator	it;

	while ((it = _database.find(_constructDate(dateStruct))) == _database.end())
	{
		
	}

	// if (it != _database.end())
	// {
	// 	std::cout << "Date = " << it->first << " Rate = " << it->second << std::endl;
	// }
}

std::string const	BitcoinExchange::_trim(std::string const &date) const
{
	size_t	start_pos = date.find_first_not_of(" \t");
	size_t	end_pos = date.find_last_not_of(" \t");

	return (date.substr(start_pos, end_pos + 1));
}

/* Public */

void	BitcoinExchange::evaluate(const char *arg) const
{
	std::ifstream	file(arg);
	std::string		line;
	std::string		date;
	t_date			dateStruct;
	size_t			pos;

	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			pos = line.find('|');
			date = _trim(line.substr(0, pos));
			if (_dateIsValid(date))
			{
				dateStruct = _createDateStruct(date);
				// std::cout << dateStruct.year << "-" << dateStruct.month << "-" << dateStruct.day << std::endl;
				_findInDatabase(dateStruct);
			}
			else
				std::cerr << "Date is not valid" << std::endl;
		}
		file.close();
	}
	else
	{
		std::cerr << "Error: could not open file." << std::endl;
	}
}
