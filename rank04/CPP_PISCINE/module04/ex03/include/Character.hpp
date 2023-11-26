#pragma once
#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include "ICharacter.hpp"
#include <string>
#define MAX_CHARACTER_SLOTS 4
#define UNEQUIPED_CHUNK_SIZE 16

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria *	_slots[MAX_CHARACTER_SLOTS];

		int			_unequiped_size;
		int			_unequiped_ammount;
		AMateria	**_unequiped;
	public:
		Character();
		Character(std::string const & name);
		Character(Character const &o);
		~Character();
		Character & operator=(Character const &o);

		std::string const &	getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
};
#endif

