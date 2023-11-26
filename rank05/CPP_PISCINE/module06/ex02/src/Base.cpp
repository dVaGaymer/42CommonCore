#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base * Base::generate(void)
{
	std::srand(std::time(NULL));
	switch (std::rand() % 3)
	{
		case 0:
			std::cout << "Type A was randomly generated\n\t";
			return (new A);
		case 1:
			std::cout << "Type B was randomly generated\n\t";
			return (new B);
		case 2:
			std::cout << "Type C was randomly generated\n\t";
			return (new C);
		default:
			return (NULL);
	}
}

void Base::identify(Base * p)
{
	if (dynamic_cast<A *>(p) != 0)
		std::cout << "Type A was identified" << std::endl;
	else if (dynamic_cast<B *>(p) != 0)
		std::cout << "Type B was identified" << std::endl;
	else if (dynamic_cast<C *>(p) != 0)
		std::cout << "Type C was identified" << std::endl;
	else if (dynamic_cast<Base *>(p) != 0)
		std::cout << "Type Base was identified" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void Base::identify(Base & p)
{
	try
	{
		A a = dynamic_cast<A&>(p);
		std::cout << "Type A was identified" << std::endl;
		return ;
	}
	catch (std::exception& e) {}
	try
	{
		B b = dynamic_cast<B&>(p);
		std::cout << "Type B was identified" << std::endl;
		return ;
	}
	catch (std::exception& e) {}
	try
	{
		C c = dynamic_cast<C&>(p);
		std::cout << "Type C was identified" << std::endl;
		return ;
	}
	catch (std::exception& e) {}
	std::cout << "Type Base was identified" << std::endl;
	return ;
}

