#include "Dog.hpp"

Dog::Dog()
	:Animal()
{
	std::cout << "Dog Constructor" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain("Dog Idea");
}

Dog::Dog(Dog const &o)
	:Animal()
{
	std::cout << "Dog Copy Constructor" << std::endl;
	this->_type = o._type;

	this->_brain = new Brain(*o._brain);	//DEEP COPY
	// this->_brain = o._brain;				//SHALLOW COPY
}

Dog::~Dog()
{
	std::cout << "Dog Destructor" << std::endl;
	delete this->_brain;
}
#define SHALLOW
Dog & Dog::operator=(Dog const &o)
{
	std::cout << "Dog Copy operator" << std::endl;
	this->_type = o._type;

	this->_brain = new Brain(*o._brain);	//DEEP COPY
	// this->_brain = o._brain;				//SHALLOW COPY
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "guau-guau gua gua jau jau aahhsaa aasshhh grrgggrrr uufgg" << std::endl;
}

void	Dog::printBrain() const
{
	this->_brain->printIdeas();
}
