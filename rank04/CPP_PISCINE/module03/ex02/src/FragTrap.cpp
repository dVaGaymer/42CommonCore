#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap()
	:ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_name = "";
	this->_hitPoints = this->getDefaultHitPoints();
	this->_energyPoints = this->getDefaultEnergyPoints();
	this->_attackDamage = this->getDefaultAttackDamage();
}

FragTrap::FragTrap(std::string name)
	:ClapTrap(name)
{
	this->_name = name;
	this->_hitPoints = this->getDefaultHitPoints();
	this->_energyPoints = this->getDefaultEnergyPoints();
	this->_attackDamage = this->getDefaultAttackDamage();
}

FragTrap::FragTrap(FragTrap const &o)
	:ClapTrap(o)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

void FragTrap::attack(std::string const target)
{
	std::cout << "FragTrap" << " ";
	std::cout << this->_name << " ";
	std::cout << "attack" << " ";
	std::cout << target << ", ";
	std::cout << "causing" << " ";
	std::cout << this->_attackDamage << " ";
	std::cout << "points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap" << " ";
	std::cout << this->_name << " ";
	std::cout << "accepted your high fives" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const &o)
{
	this->_name = o._name;
	this->_hitPoints = o._hitPoints;
	this->_energyPoints = o._energyPoints;
	this->_attackDamage = o._attackDamage;
	return (*this);
}

unsigned int	FragTrap::getDefaultHitPoints() const { return (100); }
unsigned int	FragTrap::getDefaultEnergyPoints() const { return (100); }
unsigned int	FragTrap::getDefaultAttackDamage() const { return (30); }
