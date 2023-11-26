#include "Dog.hpp"

Dog::Dog()
	:Animal()
{
	std::cout << "Dog Constructor" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(Dog const &o)
	:Animal()
{
	std::cout << "Dog Copy Constructor" << std::endl;
	this->_type = o._type;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor" << std::endl;
}

Dog & Dog::operator=(Dog const &o)
{
	std::cout << "Dog Copy operator" << std::endl;
	this->_type = o._type;
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "guau-guau gua gua jau jau aahhsaa aasshhh grrgggrrr uufgg" << std::endl;
}
