#include "Cat.hpp"

Cat::Cat()
	:Animal()
{
	std::cout << "Cat Constructor" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(Cat const &o)
	:Animal()
{
	std::cout << "Cat Copy Constructor" << std::endl;
	this->_type = o._type;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor" << std::endl;
}

Cat & Cat::operator=(Cat const &o)
{
	std::cout << "Cat Copy operator" << std::endl;
	this->_type = o._type;
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "meow mow mrow mrrr prr hh mrrrrrrrrrrawr mew rrrr e-e-e-e-e-e awr hiiiiiiiiiss mEEEwr aaaaaaaaaaaa" << std::endl;
}
