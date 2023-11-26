#include <RPN.hpp>

int main(int argc, char **argv)
{
	if (argc != 2)
		return (-1);
	try
	{
		RPN rpn(*(argv + 1));
		std::cout << rpn.getResult() << std::endl;
	}
	catch(const std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
