#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define DEEP

int main()
{
	Dog	dog;
	{
		Dog	tmp = dog;
		dog.printBrain();
		(void)tmp;
	}
	dog.printBrain();
	(void)dog;
}
