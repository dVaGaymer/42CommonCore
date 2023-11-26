#include "Harl.hpp"

void	l(void){system("leaks harl");}

int	main(int argc, char **argv)
{
	Harl	h;

	atexit(l);
	if (argc != 2)
	{
		std::cout << "Harl is making uninteligible sounds\n";
		return (-1);
	}
	h.complain(*(argv + 1));
	return (0);
}
