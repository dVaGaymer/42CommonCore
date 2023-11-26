#include "HumanA.hpp"

HumanA::HumanA(Weapon &weapon)
	:_name("unnamed human"), _weapon(weapon){}
HumanA::HumanA(const std::string name, Weapon &weapon)
	:_name(name), _weapon(weapon){}

Weapon				HumanA::getWeapon(){ return (this->_weapon);}
void				HumanA::setWeapon(Weapon &weapon){ this->_weapon = weapon; }
const std::string	HumanA::getName(){ return (this->_name); }
void				HumanA::setName(const std::string name){ this->_name = name; }

void	HumanA::attack()
{
	std::cout << this->_name;
	std::cout << " attacks with their ";
	std::cout << this->_weapon.getType();
	std::cout << "\n";
}
