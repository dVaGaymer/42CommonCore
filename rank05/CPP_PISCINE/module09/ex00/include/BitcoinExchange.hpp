#pragma once
#ifndef __BITCOINEXCHANGE_HPP__
# define __BITCOINEXCHANGE_HPP__

# include <map>
# include <string>
# include <fstream>
# include <iostream>
#include <stdlib.h>

# define DEFAULT_DATABASE "./data/data.csv"

class BitcoinExchange
{
	private:
		std::map<unsigned long int, double>	_defaultDatabase;
		BitcoinExchange(std::string const & database);

	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &o);
		~BitcoinExchange();
		BitcoinExchange & operator=(BitcoinExchange const &o);

		void	evaluateDatabase(std::string const & input_database);
		double	getPriceOfNearestDate(std::string const & date);
		void	logDatabase();
};
#endif

