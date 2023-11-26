#include "Cat.hpp"

Cat::Cat()
	:Animal()
{
	std::cout << "Cat Constructor" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain("Cat Idea");
}

Cat::Cat(Cat const &o)
	:Animal()
{
	std::cout << "Cat Copy Constructor" << std::endl;
	this->_type = o._type;

	this->_brain = new Brain(*o._brain);	//DEEP COPY
	// this->_brain = o._brain;				//SHALLOW COPY
}

Cat::~Cat()
{
	std::cout << "Cat Destructor" << std::endl;
	delete this->_brain;
}

Cat & Cat::operator=(Cat const &o)
{
	std::cout << "Cat Copy operator" << std::endl;
	this->_type = o._type;

	this->_brain = new Brain(*o._brain);	//DEEP COPY
	// this->_brain = o._brain;				//SHALLOW COPY
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "meow mow mrow mrrr prr hh mrrrrrrrrrrawr mew rrrr e-e-e-e-e-e awr hiiiiiiiiiss mEEEwr aaaaaaaaaaaa" << std::endl;
}

void	Cat::printBrain() const
{
	this->_brain->printIdeas();
}
