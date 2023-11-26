#pragma once
#ifndef __DOG_HPP__
#define __DOG_HPP__

#include "Brain.hpp"
#include "Animal.hpp"

class Dog : public Animal
{
	private:
		Brain	*_brain;
	public:
		Dog();
		Dog(Dog const &o);
		~Dog();
		Dog & operator=(Dog const &o);

		void	makeSound() const;
		void	printBrain() const;
};
#endif

