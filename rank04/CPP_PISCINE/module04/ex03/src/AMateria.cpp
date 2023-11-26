#include "AMateria.hpp"

AMateria::AMateria()
	:_type(""){}

AMateria::AMateria(std::string const & type)
	:_type(type){}

AMateria::AMateria(AMateria const &o)
	:_type(o._type){}

AMateria::~AMateria() {}

AMateria & AMateria::operator=(AMateria const &o)
{
	this->_type = o._type;
	return (*this);
}

std::string const &	AMateria::getType() const { return (this->_type); }

void		AMateria::use(ICharacter & target)
{
	(void)target;
	std::cout << "Unknown" << std::endl;
}
