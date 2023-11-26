#include "Animal.hpp"

Animal::Animal()
	:_type("")
{
	std::cout << "Animal Constructor" << std::endl;
}

Animal::Animal(Animal const &o)
	:_type(o._type)
{
	std::cout << "Animal Copy Constructor" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor" << std::endl;
}

Animal & Animal::operator=(Animal const &o)
{
	std::cout << "Animal Copy operator" << std::endl;
	this->_type = o._type;
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << "Generic animal sound" << std::endl;
}

std::string	Animal::getType() const
{
	return this->_type;
}
