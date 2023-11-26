#pragma once
#ifndef __WRONGANIMAL_HPP__
#define __WRONGANIMAL_HPP__

#include <iostream>

class WrongAnimal
{
	protected:
		std::string	_type;
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const &o);
		~WrongAnimal();
		WrongAnimal & operator=(WrongAnimal const &o);

		void	makeSound() const;
		std::string	getType() const;
};
#endif

