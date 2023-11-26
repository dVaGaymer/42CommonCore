#include "Ice.hpp"

Ice::Ice()
	:AMateria("ice"){}

Ice::Ice(Ice const &o)
	:AMateria(o){}

Ice::~Ice() {}

Ice & Ice::operator=(Ice const &o)
{
	if (!o._type.compare("ice"))
		return *this;
	this->_type = o._type;
	return (*this);
}

AMateria *	Ice::clone() const
{
	return (new Ice(*this));
}

void		Ice::use(ICharacter & target)
{
	(void)target;
	std::cout << "* shots an ice bolt at";
	std::cout << " " << target.getName() << " "; //target.name
	std::cout << "*" << std::endl;
}
