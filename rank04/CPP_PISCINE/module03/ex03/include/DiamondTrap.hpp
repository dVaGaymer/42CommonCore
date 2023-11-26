#pragma once
#ifndef __DIAMONDTRAP_HPP__
#define __DIAMONDTRAP_HPP__

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string		_name;
	public:
		DiamondTrap();
		DiamondTrap(std::string const name);
		DiamondTrap(DiamondTrap const &o);
		~DiamondTrap();
		DiamondTrap & operator=(DiamondTrap const &o);

		using	ScavTrap::attack;
		void	whoAmI();
};
#endif

