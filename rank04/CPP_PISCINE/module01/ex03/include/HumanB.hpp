#pragma once
#ifndef __HUMANB_HPP__
#define __HUMANB_HPP__

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string	_name;
		Weapon	*_weapon;
	public:
		HumanB();
		HumanB(const std::string name);

		Weapon				*getWeapon();
		void				setWeapon(Weapon &weapon);
		const std::string	getName();
		void				setName(const std::string name);

		void	attack();
};
#endif

