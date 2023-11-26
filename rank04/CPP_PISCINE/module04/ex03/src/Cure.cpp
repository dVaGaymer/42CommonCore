#include "Cure.hpp"

Cure::Cure()
	:AMateria("cure"){}

Cure::Cure(Cure const &o)
	:AMateria(o){}

Cure::~Cure() {}

Cure & Cure::operator=(Cure const &o)
{
	if (!o._type.compare("cure"))
		return *this;
	this->_type = o._type;
	return (*this);
}

AMateria *	Cure::clone() const
{
	return (new Cure(*this));
}

void		Cure::use(ICharacter & target)
{
	(void)target;
	std::cout << "* heals";
	std::cout << " " << target.getName(); //target.name
	std::cout << "'s wounds *" << std::endl;
}

