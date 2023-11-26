#pragma once
#ifndef __AMATERIA_HPP__
#define __AMATERIA_HPP__

#include <string>
#include <iostream>

#include "ICharacter.hpp"
class ICharacter;

class AMateria
{
	protected:
		std::string	_type;
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(AMateria const &o);
		virtual ~AMateria();
		AMateria & operator=(AMateria const &o);

		std::string const & getType() const;
		virtual AMateria *	clone() const = 0; //Pure Virtual func
											   //Make class an interface
											   //Must be defined in derived
		virtual void		use(ICharacter & target); //Should be defined from base
};
#endif

