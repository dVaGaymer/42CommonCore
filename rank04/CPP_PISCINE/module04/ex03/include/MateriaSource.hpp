#pragma once
#ifndef __MATERIASOURCE_HPP__
#define __MATERIASOURCE_HPP__

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#define MAX_SOURCE_SLOTS 4

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_slots[MAX_SOURCE_SLOTS];
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &o);
		~MateriaSource();
		MateriaSource & operator=(MateriaSource const &o);

		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
};
#endif

