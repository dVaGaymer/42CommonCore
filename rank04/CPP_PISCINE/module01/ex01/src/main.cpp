#include "Zombie.hpp"
#define N 15

void	announceHorde(Zombie *horde)
{
	for(int i = 0; i < N; i++)
		horde[i].announce();
}

void	l(){system("leaks horde");}

int	main(int argc, char **argv)
{
	Zombie*	horde;
	(void)argc;(void)argv;

	atexit(l);
	horde = zombieHorde(N, "Julian");
	announceHorde(horde);
	delete[] horde;
	return (0);
}
