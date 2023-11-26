#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void log_value(T n) { std::cout << "\tEpic value: " << n << std::endl; }

int main( void )
{
	std::cout << "Int iter:" << std::endl;
	int		a[8] = {0, 1, 2, 3, 4, 5, 6, 7};
	iter<int>(a, 8, log_value<int>);

	std::cout << "\nFloat iter" << std::endl;
	float	b[8] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
	iter<float>(b, 8, log_value<float>);

	std::cout << "\nString iter" << std::endl;
	std::string	c[8] = {"Alvaro", "Cristina", "Pedro", "Algarpe", "Alfonso", "Adela", "Dalas", "Aurora"};
	iter<std::string>(c, 8, log_value<std::string>);
	return 0;
}
