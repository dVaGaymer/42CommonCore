#include "ClapTrap.hpp"

int	main(void)
{
	/* Main 00 */
	std::cout << "EX00 -------------------------------" << std::endl;
	ClapTrap	ct1;
	ClapTrap	epic("Epic_ClapTraper");
	ClapTrap	shit("Piece_of_Shit_ClapTrapper");
	ClapTrap	ct4(shit);

	epic.attack("Piece_of_Shit_ClapTrapper");
	shit.takeDamage(0);
	shit.takeDamage(5);

	shit.beRepaired(5);
	shit.beRepaired(100);

	shit.takeDamage(100);

	shit.beRepaired(50);

	shit.takeDamage(10);

	return (0);
}
