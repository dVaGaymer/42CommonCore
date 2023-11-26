#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

void l(){system("leaks materias");}

int main()
{
	std::cout << "---SUBJECT---" << std::endl;
	atexit(l);
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	std::cout << "---OWN---" << std::endl;
	ICharacter* paco = new Character("Paco");
	ICharacter* other = new Character("other");
	IMateriaSource* src1 = new MateriaSource();
	src1->learnMateria(new Ice());
	src1->learnMateria(new Cure());

	tmp = src1->createMateria("ice");
	paco->equip(tmp);
	tmp = src1->createMateria("ice");
	paco->equip(tmp);
	tmp = src1->createMateria("cure");
	paco->equip(tmp);
	tmp = src1->createMateria("ice");
	paco->equip(tmp);
	paco->use(0, *other);
	paco->use(1, *other);
	paco->use(2, *other);
	paco->use(3, *other);
	//---------------
	std::cout << "Unequip:" << std::endl;
	paco->unequip(0);
	paco->unequip(1);
	paco->unequip(2);
	paco->unequip(3);
	paco->unequip(4);
	paco->unequip(5);
	paco->unequip(6);
	//---------------
	tmp = src1->createMateria("cure");
	paco->equip(tmp);
	tmp = src1->createMateria("cure");
	paco->equip(tmp);
	tmp = src1->createMateria("ice");
	paco->equip(tmp);
	tmp = src1->createMateria("cure");
	paco->equip(tmp);
	paco->use(0, *other);
	paco->use(1, *other);
	paco->use(2, *other);
	paco->use(3, *other);
	paco->use(4, *other);
	paco->use(5, *other);
	delete paco;
	delete other;
	delete src1;
	return (0);
}
