#include "BitcoinExchange.hpp"

static double	stof(std::string str)
{
	int		neg = (str[0] == '-') ? -1 : 1;
	float	n = 0, dec = 0;

	std::string::iterator it;
	for (it = str.begin() + (neg == -1); (*it >= '0' && *it <= '9') && it != str.end(); it++)
		n = (n * 10) + (*it - 48);
	if (it == str.end()) return (neg * n);
	if (*it != '.')
		throw std::runtime_error("Error: bad syntax.");
	for (it = str.end() - 1; (*it >= '0' && *it <= '9'); it--)
		dec = (dec / 10.f) + (*it - 48)/10.f;
	if (*it != '.')
		throw std::runtime_error("Error: bad syntax.");
	return (neg * (n+dec));
}

static unsigned long int	datetoui(std::string const & date)
{
	unsigned long int	sec;
	int	year;
	int	month;
	int	day;

	for (int i = 0 ; date[i]; i++)
		if (((date[i] != '-') && !(date[i] >= '0' && date[i] <= '9')) || (date.size() != 10))
			throw std::runtime_error(std::string("Error: bad input => ") + date);
	year = static_cast<int>(::stof(date.substr(0, 4)));
	if (year < 2009 || year > 2022)
		throw std::runtime_error(std::string("Error: bad input => ") + date);
	month = static_cast<int>(::stof(date.substr(5, 2)));
	if (month < 1 || month > 12)
		throw std::runtime_error(std::string("Error: bad input => ") + date);
	day = static_cast<int>(::stof(date.substr(8, 2)));
	if (day < 1 || day > 31)
		throw std::runtime_error(std::string("Error: bad input => ") + date);
	sec = static_cast<unsigned long int>(year) * (365 * 24 * 60 * 60)
		+ static_cast<unsigned long int>(month) * (30 * 24 * 60 * 60)
		+ static_cast<unsigned long int>(day) * (24 * 60 * 60);
	return (sec);
}

BitcoinExchange::BitcoinExchange()
{
	*this = BitcoinExchange(DEFAULT_DATABASE);
}

BitcoinExchange::BitcoinExchange(std::string const & database)
{
	std::string		line;
	unsigned int	sep;
	std::ifstream	src_database(database.c_str());

	if (!src_database.good())
		throw std::runtime_error("Error: Couldn't open database.");
	std::getline(src_database, line);
	while (std::getline(src_database, line))
	{
		sep = line.find(',') + 1;
		this->_defaultDatabase.insert(
			std::make_pair<unsigned long int, double>(
				::datetoui(line.substr(0, sep - 1)),
				::stof(line.substr(sep, line.size()-sep))));
	}
	src_database.close();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &o)
{
	this->_defaultDatabase = o._defaultDatabase;
}

BitcoinExchange::~BitcoinExchange()
{ }

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const &o)
{
	this->_defaultDatabase = o._defaultDatabase;
	return *this;
}

void	BitcoinExchange::logDatabase()
{
	std::map< unsigned long int, double >::iterator	itb
		= this->_defaultDatabase.begin();
	std::map<unsigned long int, double>::iterator	ite
		= this->_defaultDatabase.end();
	std::cout << itb->first;
	for (; itb != ite; itb++)
		std::cout << itb->first << " | " << itb->second << std::endl;
}

double	BitcoinExchange::getPriceOfNearestDate(std::string const & date)
{
	unsigned long int	num_date = ::datetoui(date);
	unsigned long int	len = num_date - this->_defaultDatabase.begin()->first;

	std::map< unsigned long int, double >::iterator	itb
		= this->_defaultDatabase.begin();
	std::map<unsigned long int, double>::iterator	ite
		= this->_defaultDatabase.end();
	std::map<unsigned long int, double>::iterator	nearest = itb;
	for (++itb; itb != ite; itb++)
	{
		if ((num_date - itb->first) < len)
		{
			len = num_date - itb->first;
			nearest = itb;
		}
	}
	return (nearest->second);
}

void	BitcoinExchange::evaluateDatabase(std::string const & database)
{
	std::string		line;
	unsigned int	sep;
	std::ifstream	input_database(database.c_str());
	double			input_value;
	double			database_value;

	if (!input_database.good())
		throw std::runtime_error("Error: Couldn't open database.");
	while (std::getline(input_database, line))
	{
		sep = line.find('|');
		try
		{
			database_value = this->getPriceOfNearestDate(line.substr(0, sep - 1));
			input_value = ::stof(line.substr(sep+2, line.size()-sep-1));
			if (input_value < 0)
				std::cout << "Error: not a positive number." << std::endl;
			else if (input_value > 1000)
				std::cout << "Error: too large a number." << std::endl;
			else
				std::cout << line.substr(0, sep - 1) << " => " << input_value << " = " << input_value * database_value << std::endl;
		} catch (std::runtime_error & e)
		{std::cout << e.what() << std::endl; }
	}
	input_database.close();
}
