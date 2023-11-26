#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < MAX_SOURCE_SLOTS; i++)
		this->_slots[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &o)
{
	for (int i = 0; i < MAX_SOURCE_SLOTS; i++)
		if (o._slots[i])
			this->_slots[i] = o._slots[i]->clone();
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MAX_SOURCE_SLOTS; i++)
		if (this->_slots[i])
			delete this->_slots[i];
}

MateriaSource & MateriaSource::operator=(MateriaSource const &o)
{
	for (int i = 0; i < MAX_SOURCE_SLOTS; i++)
		if (o._slots[i])
			this->_slots[i] = o._slots[i]->clone();
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < MAX_SOURCE_SLOTS; i++)
		if (!this->_slots[i])
		{
			this->_slots[i] = m;
			return ;
		}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < MAX_SOURCE_SLOTS; i++)
		if (this->_slots[i])
			if (!type.compare(this->_slots[i]->getType()))
				return (this->_slots[i]->clone());
	return (NULL);
}
