#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
	:_type("")
{
	std::cout << "Wrong Animal Constructor" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &o)
	:_type(o._type)
{
	std::cout << "Wrong Animal Copy Constructor" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong Animal Destructor" << std::endl;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const &o)
{
	this->_type = o._type;
	return (*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal fake sound" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return this->_type;
}
