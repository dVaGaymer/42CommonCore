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
		virtual ~Animal();
		Animal & operator=(Animal const &o);

		std::string		getType() const;
		virtual void	makeSound() const;
};
#endif

