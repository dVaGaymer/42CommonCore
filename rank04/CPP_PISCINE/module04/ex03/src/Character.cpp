#include "Character.hpp"

Character::Character()
	:_name(""), _unequiped_size(UNEQUIPED_CHUNK_SIZE),
	_unequiped_ammount(0)
{
	this->_unequiped = new AMateria *[UNEQUIPED_CHUNK_SIZE];
	for (int i = 0; i < MAX_CHARACTER_SLOTS; i++)
		this->_slots[i] = NULL;
}

Character::Character(std::string const & name)
	:_name(name), _unequiped_size(UNEQUIPED_CHUNK_SIZE),
	_unequiped_ammount(0)
{
	this->_unequiped = new AMateria *[UNEQUIPED_CHUNK_SIZE];
	for (int i = 0; i < MAX_CHARACTER_SLOTS; i++)
		this->_slots[i] = NULL;
}

Character::Character(Character const &o)
	:_name(o._name)
{
	this->_unequiped_ammount = 0;
	this->_unequiped = new AMateria *[UNEQUIPED_CHUNK_SIZE];
	this->_unequiped_size = o._unequiped_size;
	for (int i = 0; i < MAX_CHARACTER_SLOTS; i++)
		if (o._slots[i])
		{
			if (this->_slots[i])
				delete this->_slots[i];
			this->_slots[i] = o._slots[i]->clone();
		}
}

Character::~Character()
{
	for (int i = 0; i < this->_unequiped_ammount; i++)
		delete this->_unequiped[i];
	delete[] this->_unequiped;
	for (int i = 0; i < MAX_CHARACTER_SLOTS; i++)
		if (this->_slots[i])
			delete this->_slots[i];
}

Character & Character::operator=(Character const &o)
{
	this->_name = o._name;
	for (int i = 0; i < MAX_CHARACTER_SLOTS; i++)
		if (o._slots[i])
		{
			if (this->_slots[i])
				delete this->_slots[i];
			this->_slots[i] = o._slots[i]->clone();
		}
	return (*this);
}

std::string const &	Character::getName() const { return (this->_name); }

void				Character::equip(AMateria* m)
{
	for (int i = 0; i < MAX_CHARACTER_SLOTS; i++)
		if (!this->_slots[i])
		{
			this->_slots[i] = m;
			return ;
		}
}

void				Character::unequip(int idx)
{
	if (idx < 0 || idx >= MAX_CHARACTER_SLOTS)
		return ;
	if (!this->_slots[idx])
		return ;
	if (this->_unequiped_ammount >= this->_unequiped_size)
	{
		this->_unequiped_size += UNEQUIPED_CHUNK_SIZE;
		AMateria	**new_unequiped = new AMateria *[this->_unequiped_size];
		for (int i = 0; i < this->_unequiped_size; i++)
	 		new_unequiped[i] = NULL;
		for (int i = 0; i < this->_unequiped_ammount; i++)
			new_unequiped[i] = this->_unequiped[i];
		delete this->_unequiped;
		this->_unequiped = new_unequiped;
	}
	this->_unequiped[this->_unequiped_ammount] = this->_slots[idx];
	this->_unequiped_ammount++;
	this->_slots[idx] = NULL;
}

void				Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= MAX_CHARACTER_SLOTS)
		return ;
	if (!this->_slots[idx])
		return ;
	this->_slots[idx]->use(target);
}
