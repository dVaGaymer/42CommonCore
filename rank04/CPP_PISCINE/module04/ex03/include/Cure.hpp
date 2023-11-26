#pragma once
#ifndef __CURE_HPP__
#define __CURE_HPP__

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(Cure const &o);
		~Cure();
		Cure & operator=(Cure const &o);

		AMateria *	clone() const;
		void		use(ICharacter & target);
};
#endif
