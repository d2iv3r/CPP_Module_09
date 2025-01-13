/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:38:38 by efarhat           #+#    #+#             */
/*   Updated: 2024/01/08 14:18:27 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <exception>

typedef struct s_date
{
	int	year;
	char d1;
	int	month;
	char d2;
	int	day;
	std::string end;
}		t_date;

#define DATAFILE "data.csv"

class BitcoinExchange
{
	private:
		static std::map<std::string, double> data;
		static void getData();
		void check_line(std::string const &line);
		std::string key;
		double 		value;
		void findExchange();
		BitcoinExchange();
	public:
		BitcoinExchange(std::string const &f);
		BitcoinExchange(const BitcoinExchange &cpy);
		BitcoinExchange& operator=(const BitcoinExchange &cpy);
		~BitcoinExchange();
};

#endif
