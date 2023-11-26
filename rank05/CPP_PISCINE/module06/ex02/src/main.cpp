#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

int	main(void)
{
	//Using pointer
	std::cout << "USING POINTERS:\n\n";

	std::cout << "identify(A):" << "\n\t";
	Base::identify(new A);

	std::cout << "\nidentify(B):" << "\n\t";
	Base::identify(new B);

	std::cout << "\nidentify(C):" << "\n\t";
	Base::identify(new C);

	std::cout << "\nidentify(Base):" << "\n\t";
	Base::identify(new Base);

	std::cout << "\nidentify(NULL):" << "\n\t";
	Base::identify(NULL);

	std::cout << "\nidentify(random):" << "\n\t";
	Base::identify(Base::generate());

	//Using reference
	std::cout << "\n\n----------------\n";
	std::cout << "USING References:\n\n";

	std::cout << "identify(A):" << "\n\t";
	A a = A();
	Base::identify(a);

	std::cout << "\nidentify(B):" << "\n\t";
	B b = B();
	Base::identify(b);

	std::cout << "\nidentify(C):" << "\n\t";
	C c = C();
	Base::identify(c);

	std::cout << "\nidentify(Base):" << "\n\t";
	Base base = Base();
	Base::identify(base);

	std::cout << "\nidentify(random):" << "\n\t";
	Base *ptr = Base::generate();
	Base::identify(*ptr);
	return (0);
}
