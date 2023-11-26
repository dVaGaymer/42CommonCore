#include "Zombie.hpp"

void	l(void){system("leaks zombie");}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	Zombie	*z0, *z1, *z2;

	atexit(l);
	z0 = newZombie("Rober");
	z0->announce();
	z1 = newZombie("Nicolasqueis");
	z1->announce();
	z2 = newZombie("Lailarros");
	z2->announce();
	std::cout << "---\n";
	randomChump("Enrique");
	randomChump("Meteo");
	randomChump("Alfonso");
	std::cout << "---\n";
	delete z0;
	delete z1;
	delete z2;
	return (0);
}
