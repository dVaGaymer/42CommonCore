#include "Harl.hpp"

void	l(void){system("leaks harl");}

int	main(int argc, char **argv)
{
	Harl	h;

	atexit(l);
	(void)argv;
	if (argc != 1)
		return (-1);
	h.complain("DEBUG");
	h.complain("INFO");
	h.complain("WARNING");
	h.complain("ERROR");
	h.complain("INFO");
	return (0);
}
