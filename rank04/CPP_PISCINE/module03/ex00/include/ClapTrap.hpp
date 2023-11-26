#pragma once
#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <iostream>

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &o);
		~ClapTrap();
		ClapTrap & operator=(ClapTrap const &o);

		void attack(std::string const target);
		//Puede ser conveniente pasar los parametros como const &, es mas rapido entre otros
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		//Puede ser conveniente devolver como const &
		unsigned int	getHitPoints() const;
		unsigned int	getEnergyPoints() const;
		unsigned int	getAttackDamage() const;

		void	setHitPoints(unsigned int const hitPoints);
		void	setEnergyPoints(unsigned int const EnergyPoints);
		void	setAttackDamage(unsigned int const AttackDamage);
};
#endif

