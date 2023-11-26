#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	:_name(std::string("")), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	:_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &o)
	:_name(o._name), _hitPoints(o._hitPoints),
	_energyPoints(o._energyPoints), _attackDamage(o._attackDamage)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const &o)
{
	this->_name = o._name;
	this->_hitPoints = o._hitPoints;
	this->_energyPoints = o._energyPoints;
	this->_attackDamage = o._attackDamage;
	return (*this);
}

void ClapTrap::attack(std::string const target)
{
	std::cout << "ClapTrap" << " ";
	std::cout << this->_name << " ";
	std::cout << "attack" << " ";
	std::cout << target << ", ";
	std::cout << "causing" << " ";
	std::cout << this->_attackDamage << " ";
	std::cout << "points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap" << " ";
		std::cout << this->_name << " ";
		std::cout << "is already dead!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap" << " ";
	std::cout << this->_name << " ";
	std::cout << "takes" << " ";
	std::cout << amount << " ";
	std::cout << "points of damage!" << std::endl;
	this->_hitPoints = (this->_hitPoints < amount)
		? 0
		: this->_hitPoints - amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints < amount)
	{
		if (this->_energyPoints != 0)
		{
			std::cout << "ClapTrap" << " ";
			std::cout << this->_name << " ";
			std::cout << "only restored" << " ";
			std::cout << this->_energyPoints << " ";
			std::cout << "energy points!" << std::endl;
			this->_hitPoints += this->_energyPoints;
			this->_energyPoints = 0;
			return ;
		}
		std::cout << "ClapTrap" << " ";
		std::cout << this->_name << " ";
		std::cout << "does not have enough energy!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap" << " ";
	std::cout << this->_name << " ";
	std::cout << "restores" << " ";
	std::cout << amount << " ";
	std::cout << "hit points!" << std::endl;
	this->_energyPoints = (this->_energyPoints < amount)
		? 0
		: this->_energyPoints - amount;
	this->_hitPoints += amount;
}
