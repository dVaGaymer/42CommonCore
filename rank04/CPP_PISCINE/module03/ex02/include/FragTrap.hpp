#pragma once
#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string const name);
		FragTrap(FragTrap const  &o);
		~FragTrap();
		FragTrap & operator=(FragTrap const &o);

		void	attack(std::string const target);
		void	highFivesGuys(void);

		unsigned int	getDefaultHitPoints() const;
		unsigned int	getDefaultEnergyPoints() const;
		unsigned int	getDefaultAttackDamage() const;
};
#endif

