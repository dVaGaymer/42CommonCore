#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::Zombie(std::string name)
	:_name(name){}

Zombie::Zombie(const Zombie &o)
	:_name(o._name){}

Zombie::~Zombie()
{
	std::cout << this->_name << " suffered severe 🧠 damage...\n";
}

Zombie & Zombie::operator=(const Zombie &o)
{
	this->_name = o._name;
	return (*this);
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}

std::string	Zombie::getName(){ return (this->_name); }
void		Zombie::setName(std::string name){ this->_name = name; }
