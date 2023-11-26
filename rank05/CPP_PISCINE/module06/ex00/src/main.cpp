#include "ScalarConverter.hpp"

int foo(int n, int n1) {return n + n1;}

int	main(int argc, char **argv)
{
	if (argc != 2) return (-1);
	ScalarConverter::convert(*(argv + 1));

	return (0);
}
