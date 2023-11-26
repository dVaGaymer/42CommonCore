#pragma once
#ifndef __CAT_HPP__
#define __CAT_HPP__

#include "Brain.hpp"
#include "Animal.hpp"

class Cat : public Animal
{
	private:
		Brain	*_brain;
	public:
		Cat();
		Cat(Cat const &o);
		~Cat();
		Cat & operator=(Cat const &o);

		void	makeSound() const;
		void	printBrain() const;
};
#endif

