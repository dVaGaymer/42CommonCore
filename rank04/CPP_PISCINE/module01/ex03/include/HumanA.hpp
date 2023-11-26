#pragma once
#ifndef __HUMANA_HPP__
#define __HUMANA_HPP__

#include <iostream>
#include "Weapon.hpp"

/*
	Reference vars (Weapon &weapon MUST ALWAYS BE INITIALICED)
*/

class HumanA
{
	private:
		std::string	_name;
		Weapon		&_weapon;
	public:
		HumanA(Weapon &weapon);
		HumanA(std::string name, Weapon &weapon);

		Weapon				getWeapon();
		void				setWeapon(Weapon &weapon);
		const std::string	getName();
		void				setName(const std::string name);

		void	attack();
};
#endif

