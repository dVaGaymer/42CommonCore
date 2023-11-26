#pragma once
#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <iostream>

class Animal
{
	protected:
		std::string	_type;
	public:
		Animal();
		Animal(Animal const &o);
		virtual ~Animal(); //Needed so it is called if a child is stored in parent pointer
		Animal & operator=(Animal const &o);

		virtual void	makeSound() const = 0;
		std::string		getType() const;
};
#endif

