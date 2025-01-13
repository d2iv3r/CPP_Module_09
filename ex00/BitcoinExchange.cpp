/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:44:36 by efarhat           #+#    #+#             */
/*   Updated: 2024/01/08 11:51:35 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<std::string, double> BitcoinExchange::data;

BitcoinExchange::BitcoinExchange()
{
}

void BitcoinExchange::getData()
{
	std::ifstream dataFile(DATAFILE);
	if (!dataFile.is_open())
		throw std::ios_base::failure("Error: could not open data file.");
	std::string key, value;
	std::getline(dataFile, key);
	if (dataFile.fail())
		throw std::iostream::failure("Error: could not read from file.");
	while (!dataFile.eof())
	{
		std::getline(dataFile, key, ',');
		std::getline(dataFile, value);
		data.insert(std::pair<std::string, double>(key, std::strtod(value.c_str(), NULL)));
	}
	dataFile.close();
}

bool isLeapYear(int year)
{
	return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

bool daysInMonth(t_date const &date)
{
	switch (date.month)
	{
		case 2:
			return (!isLeapYear(date.year) && date.day > 28) ? false : true;
		case 4: case 6: case 9: case 11:
			return (date.day > 30) ? false : true;
		default:
			return true;
	}
}

int get_date(std::string const &line, t_date &d)
{
	size_t p1 = line.find('-', 0);
	size_t p2 = line.find('-', p1 + 1);
	if (p1 == std::string::npos || p2 == std::string::npos || p1 > 4
		|| p2 - p1 != 3 || line.size() - p2 != 3)
		return 0;
	std::istringstream date(line);
	date >> d.year >> d.d1 >> d.month >> d.d2 >> d.day >> d.end;
	if (d.d1 != '-' || d.d2 != '-' || !d.end.empty())
		return 0;
	if (d.month < 1 || d.month > 12 || d.day < 1 || d.day > 31 || !daysInMonth(d))
		return 0;
	return 1;
}

void  BitcoinExchange::check_line(std::string const &line)
{
	if (line.empty() || !std::isdigit(line.at(0)) || !std::isdigit(line.at(line.size() - 1)))
		throw std::runtime_error("Error: bad input => " + line);
	size_t p = line.find('|');
	if (p == std::string::npos || p < 11 || p + 2 > line.size()
		|| line.at(p - 1) != ' ' || !std::isdigit(line.at(p - 2))
		|| line.at(p + 1) != ' ' || (line.at(p + 2) != '+' && line.at(p + 2) != '-'
			&& !std::isdigit(line.at(p + 2))))
		throw std::runtime_error("Error: bad input => " + line);
	key = line.substr(0, p - 1);
	t_date	d;
	if (!get_date(key, d))
		throw std::runtime_error("Error: bad input => " + line);
	std::map<std::string, double>::iterator it = ++data.begin();
	t_date ld;
	get_date(it->first, ld);
	if (d.year < ld.year)
		throw std::runtime_error("Error: date not exist => " + line);
	char *end;
	value = std::strtod(line.substr(p + 1, std::string::npos).c_str(), &end);
	if (*end)
		throw std::runtime_error("Error: bad input => " + line);
	if (value <= 0)
		throw std::runtime_error("Error: not a positive number.");
	else if (value >= 1000)
		throw std::runtime_error("Error: too large a number.");
}

void BitcoinExchange::findExchange()
{
	std::map<std::string, double>::iterator it = data.find(key);
	if (it == data.end())
		it = --data.lower_bound(key);
	std::cout << key << " => " << value << " = " << (it->second * value)  << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string const &f)
{
	if (data.empty())
		BitcoinExchange::getData();
	std::ifstream infile(f.c_str());
	if (!infile.is_open())
		throw std::iostream::failure("Error: could not open file.");
	std::string line;
	std::getline(infile, line);
	if (line.empty() || line.compare("date | value") != 0)
		throw std::logic_error("Error: Invalid file format!");
	if (infile.fail())
		throw std::iostream::failure("Error: could not read from file.");
	while (std::getline(infile, line))
	{
		try
		{
			check_line(line);
			findExchange();
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	infile.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy)
{
	*this = cpy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &cpy)
{
	if (this != &cpy)
	{
		key = cpy.key;
		value = cpy.value;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}
