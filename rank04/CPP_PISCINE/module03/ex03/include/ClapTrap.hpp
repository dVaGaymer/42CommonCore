#pragma once
#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <iostream>

class ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &o);
		virtual ~ClapTrap();
		ClapTrap & operator=(ClapTrap const &o);

		void attack(std::string const target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};
#endif

