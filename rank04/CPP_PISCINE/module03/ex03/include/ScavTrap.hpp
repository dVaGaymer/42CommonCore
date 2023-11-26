#pragma once
#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(ScavTrap const &o);
		ScavTrap(std::string const name);
		~ScavTrap();
		ScavTrap & operator=(ScavTrap const &o);

		void	attack(std::string const target);
		void	guardGate();

		unsigned int	getDefaultHitPoints() const;
		unsigned int	getDefaultEnergyPoints() const;
		unsigned int	getDefaultAttackDamage() const;
};
#endif

