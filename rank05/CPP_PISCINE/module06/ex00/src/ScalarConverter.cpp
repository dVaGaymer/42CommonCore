#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const &o) { (void)o; }
ScalarConverter::~ScalarConverter() {}
ScalarConverter	& ScalarConverter::operator=(ScalarConverter const &o) { (void)o; return *this; }

static types	getType(std::string const & literal)
{
	//Special cases
	if (!literal.compare(".")
	|| !literal.compare("-")
	|| !literal.compare("-.")
	|| !literal.compare("-f")
	|| !literal.compare("-.f")
	|| !literal.compare(".f"))
		return UNDEFINED_TYPE;
	if (!literal.compare("+inff")
	|| !literal.compare("-inff")
	|| !literal.compare("nanf"))
		return FLOAT_TYPE_LARGE;
	if (!literal.compare("+inf")
	|| !literal.compare("-inf")
	|| !literal.compare("nan"))
		return DOUBLE_TYPE_LARGE;
	//Is char
	if (literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'')
		return CHAR_TYPE;
	//Is int
	size_t	i = (literal[0] == '-' && literal.size() != 1);
	for (; i < literal.size(); i++)
		if (literal[i] < '0' || literal[i] > '9')
			break ;
	if (i == literal.size() || !literal.compare("+inff"))
		return INT_TYPE;
	//Is double
	if (literal[i++] == '.')
		for (; i < literal.size(); i++)
			if (literal[i] < '0' || literal[i] > '9')
				break ;
	if (i == literal.size())
		return  DOUBLE_TYPE;
	//Is float
	if (literal[i++] == 'f' && i == literal.size() && i != 2)
		return  FLOAT_TYPE;
	return UNDEFINED_TYPE;
}

namespace utils
{
	static int	strtoi(std::string str)
	{
		int	n = 0;
		int neg = (str[0] == '-') ? -1 : 1;

		std::string::iterator	it = str.begin() + (neg == -1);
		for (; it != str.end(); it++)
		{
			if ((n * 10)+(*it - 48) - (neg == -1) < n)
			{
				errno = ERANGE;
				return MAX_INT;
			}
			n = (n * 10)+(*it - 48);
		}
		return (n * neg);
	}

	static double	strtof(std::string str)
	{
		float	n = 0, dec = 0;
		float neg = (str[0] == '-') ? -1.0f : 1.0f;

		std::string::iterator it;
		for (it = str.begin() + (neg == -1); *it != '.'; it++)
			n = (n * 10) + (*it - 48);
		if (*(it + 1) < '0' || *(it + 1) > '9')
			return (n);
		for (it = str.end() - 2; *it != '.'; it--)
			dec = (dec / 10.f) + (*it - 48)/10.f;
		return (neg * (n+dec));
	}

	static double	strtod(std::string str)
	{
		double	n = 0, dec = 0;
		double neg = (str[0] == '-') ? -1.0 : 1.0;

		std::string::iterator it;
		for (it = str.begin() + (neg == -1); *it != '.'; it++)
			n = (n * 10) + (*it - 48);
		if (*(it + 1) < '0' || *(it + 1) > '9')
			return (n);
		for (std::string::iterator it = str.end() - 1; *it != '.'; it--)
			dec = (dec / 10.) + (*it - 48)/10.;
		return (neg * (n+dec));
	}
}

//Test overflows: https://stackoverflow.com/questions/199333/how-do-i-detect-unsigned-integer-overflow
void	ScalarConverter::convert(std::string const & literal)
{
	char char_var; int int_var;
	float float_var; double double_var;
	switch (getType(literal))
	{
		case CHAR_TYPE:
			std::cout << "[char type]" << std::endl;
			char_var = literal[1];
			std::cout << "char: '" << char_var << "'" << std::endl;
			std::cout << "int: " << static_cast<int>(char_var) << std::endl;
			std::cout << "float: " << static_cast<float>(char_var) << ".0f" << std::endl;
			std::cout << "double: " << static_cast<double>(char_var) << ".0" << std::endl;
			break;
		case INT_TYPE:
			std::cout << "[int type]: " << std::endl;
			int_var = utils::strtoi(literal);
			if (errno == ERANGE)
			{
				std::cerr << "integer constant is too large for its type" << std::endl;
				break ;
			}

			std::cout << "char: ";
			if (int_var < MIN_CHAR || int_var > MAX_CHAR)
				std::cout << "impossible" << std::endl;
			else if (int_var < MIN_CHAR_DISPLAYABLE || int_var > MAX_CHAR_DISPLAYABLE)
				std::cout << "Non displayable" << std::endl;
			else
				std::cout << "'" << static_cast<char>(int_var) << "'" << std::endl;
			std::cout << "int: " << int_var << std::endl;
			std::cout << "float: " << static_cast<float>(int_var) << ".0f"  << std::endl;
			std::cout << "double: " << static_cast<double>(int_var) << ".0" << std::endl;
			break;
		case FLOAT_TYPE:
			std::cout << "[float type]" << std::endl;
			float_var = utils::strtof(literal);

			std::cout << "char: ";
			if (floor(float_var) < MIN_CHAR || floor(float_var) > MAX_CHAR)
				std::cout << "impossible" << std::endl;
			else if (float_var < MIN_CHAR_DISPLAYABLE || float_var > MAX_CHAR_DISPLAYABLE)
				std::cout << "Non displayable" << std::endl;
			else
				std::cout << "'" << static_cast<char>(float_var) << "'" << std::endl;

			std::cout << "int: ";
			if (floor(float_var) < MIN_INT || floor(float_var) > MAX_INT)
				std::cout << "impossible" << std::endl;
			else
				std::cout << static_cast<int>(float_var) << std::endl;

			std::cout << "float: ";
			if (float_var > MAX_FLOAT) std::cout << "+";
			if (float_var == floor(float_var) && float_var <= MAX_FLOAT && float_var >= MIN_FLOAT)
				std::cout << float_var << ".0f" << std::endl;
			else
				std::cout << float_var << "f" << std::endl;

			std::cout << "double: ";
			if (float_var > MAX_DOUBLE) std::cout << "+";
			if (float_var == floor(float_var) && float_var <= MAX_DOUBLE  && float_var >= MIN_DOUBLE)
				std::cout << static_cast<double>(float_var) << ".0" << std::endl;
			else
				std::cout << static_cast<double>(float_var) << std::endl;
			break;
		case DOUBLE_TYPE:
			std::cout << "[double type]: " << std::endl;
			double_var = utils::strtod(literal);

			std::cout << "char: ";
			if (floor(double_var) < MIN_CHAR || floor(double_var) > MAX_CHAR)
				std::cout << "impossible" << std::endl;
			else if (double_var < MIN_CHAR_DISPLAYABLE || double_var > MAX_CHAR_DISPLAYABLE)
				std::cout << "Non displayable" << std::endl;
			else
				std::cout << "'" << static_cast<char>(double_var) << "'" << std::endl;

			std::cout << "int: ";
			if (floor(double_var) < MIN_INT || floor(double_var) > MAX_INT)
				std::cout << "impossible" << std::endl;
			else
				std::cout << static_cast<int>(double_var) << std::endl;

			std::cout << "float: ";
			if (double_var > MAX_FLOAT) std::cout << "+";
			if (double_var == floor(double_var) && double_var <= MAX_FLOAT && double_var >= MIN_FLOAT)
				std::cout << static_cast<float>(double_var) << ".0f" << std::endl;
			else
				std::cout << static_cast<float>(double_var) << "f" << std::endl;

			std::cout << "double: ";
			if (double_var > MAX_DOUBLE) std::cout << "+";
			if (double_var == floor(double_var) && double_var <= MAX_DOUBLE  && double_var >= MIN_DOUBLE)
				std::cout << static_cast<double>(double_var) << ".0" << std::endl;
			else
				std::cout << static_cast<double>(double_var) << std::endl;
			break;
		case DOUBLE_TYPE_LARGE:
			std::cout << "[double inf type]: " << std::endl;
			std::cout << "char: " << "impossible" << std::endl;
			std::cout << "int: " << "impossible" << std::endl;
			std::cout << "float: " << literal << "f" << std::endl;
			std::cout << "double: " << literal << std::endl;
			break;
		case FLOAT_TYPE_LARGE:
			std::cout << "[double inf type]: " << std::endl;
			std::cout << "char: " << "impossible" << std::endl;
			std::cout << "int: " << "impossible" << std::endl;
			std::cout << "float: " << literal << std::endl;
			std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
			break;
		default:
			std::cout << "[bad literal]" << std::endl;
	}
}
