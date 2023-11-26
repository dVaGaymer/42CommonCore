#include "HumanB.hpp"

HumanB::HumanB()
	:_name("unnamed human"), _weapon(NULL){}
HumanB::HumanB(const std::string name)
	:_name(name), _weapon(NULL){}

Weapon				*HumanB::getWeapon(){ return (this->_weapon);}
void				HumanB::setWeapon(Weapon &weapon){ this->_weapon = &weapon; }
const std::string	HumanB::getName(){ return (this->_name); }
void				HumanB::setName(const std::string name){ this->_name = name; }

void	HumanB::attack()
{
	std::cout << this->_name;
	std::cout << " attacks with their ";
	if (_weapon)
		std::cout << this->_weapon->getType();
	std::cout << "\n";
}
