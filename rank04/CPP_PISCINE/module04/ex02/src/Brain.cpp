#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Constructor" << std::endl;
	for (int i = 0; i < BRAIN_IDEAS; i++)
		this->_ideas[i] = "Idea";
}

Brain::Brain(std::string idea_type)
{
	std::cout << "Brain Constructor" << std::endl;
	for (int i = 0; i < BRAIN_IDEAS; i++)
		this->_ideas[i] = idea_type;
}

Brain::Brain(Brain const &o)
{
	std::cout << "Brain Copy Constructor" << std::endl;
	for (int i = 0; i < BRAIN_IDEAS; i++)
		this->_ideas[i] = o._ideas[i];
}

Brain::~Brain()
{
	std::cout << "Brain Destructor" << std::endl;
}

Brain & Brain::operator=(Brain const &o)
{
	for (int i = 0; i < BRAIN_IDEAS; i++)
		this->_ideas[i] = o._ideas[i];
	return (*this);
}

void	Brain::printIdeas() const
{
	std::cout << "-------------" << std::endl;
	for (int i = 0; i < BRAIN_IDEAS; i++)
		std::cout << "[" << this->_ideas[i] << "]";
	std::cout << std::endl << "-------------" << std::endl;
}
