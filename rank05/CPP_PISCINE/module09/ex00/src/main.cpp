#include "BitcoinExchange.hpp"

#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: Couldn't open database.\n";
		return (-1);
	}
	BitcoinExchange	btc;
	try
	{
		btc.evaluateDatabase(*(argv + 1));
	} catch (std::runtime_error & e)
	{ std::cout << e.what() << std::endl; }
	return (0);
}
