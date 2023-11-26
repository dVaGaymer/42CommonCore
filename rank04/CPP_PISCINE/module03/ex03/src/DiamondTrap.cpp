#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	:ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->_name = "";
	this->_hitPoints = FragTrap::getDefaultHitPoints();
	this->_energyPoints = ScavTrap::getDefaultEnergyPoints();
	this->_attackDamage = FragTrap::getDefaultAttackDamage();
}

/* Being parent ClapTrap virtual it is not possible to have different values
	for ScavTrap and FragTrap attributes because they both share them */
DiamondTrap::DiamondTrap(std::string const name)
	:ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(DiamondTrap const &o)
	:ScavTrap(o), FragTrap(o)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	this->_name = o._name;
	this->_hitPoints = o._hitPoints;
	this->_energyPoints = o._energyPoints;
	this->_attackDamage = o._attackDamage;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const &o)
{
	this->_name = o._name;
	this->_hitPoints = o._hitPoints;
	this->_energyPoints = o._energyPoints;
	this->_attackDamage = o._attackDamage;
	return (*this);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
	std::cout << "Name: " << this->_name << std::endl;
}
