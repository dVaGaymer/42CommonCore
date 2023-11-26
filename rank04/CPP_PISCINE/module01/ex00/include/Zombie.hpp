#pragma once
#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string	_name;
	public:
		Zombie();
		Zombie(std::string name);
		Zombie(const Zombie &o);
		~Zombie();
		Zombie & operator=(const Zombie &o);

		void	announce(void);

		std::string	getName();
		void		setName(std::string name);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif

