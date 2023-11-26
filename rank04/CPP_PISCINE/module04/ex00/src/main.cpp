#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	dog->makeSound();
	cat->makeSound();
	meta->makeSound();

	/*---------------------------------------------------------------------*/
	std::cout << std::endl << "WRONG ANIMALS" << std::endl << std::endl;

	const WrongAnimal* w_meta = new WrongAnimal();
	const WrongAnimal* w_cat = new WrongCat();

	w_cat->makeSound();
	w_meta->makeSound();

	/*---------------------------------------------------------------------*/
	std::cout << std::endl << "DELETES" << std::endl << std::endl;

	delete meta;
	delete dog;
	delete cat;
	delete w_meta;
	delete w_cat;
}
