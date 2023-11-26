#pragma once
#ifndef __ICE_HPP__
#define __ICE_HPP__

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(Ice const &o);
		~Ice();
		Ice & operator=(Ice const &o);

		AMateria *	clone() const;
		void		use(ICharacter & target);
};
#endif

