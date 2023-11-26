#include <iostream>
#include <Serializer.hpp>

int	main()
{
	uintptr_t ptr;
	Data dat = {.element_0 = std::string("Viva Lorca")};
	std::cout << "Data Pointer: " << &dat << std::endl;
	std::cout << "Data data: " << dat.element_0 << std::endl;

	std::cout << "Serliazation\n";
	ptr = Serializer::serialize(&dat);
	std::cout << "Ptr pointer: " << ptr << " (es " << &dat << " pero en hexadecimal)" << std::endl;
	std::cout << "DeSerliazation\n";
	Data *dat1 = Serializer::deserialize(ptr);

	std::cout << "Data1 pointer: " << dat1 << std::endl;
	std::cout << "Data1 data: " << dat1->element_0 << std::endl;

	return (0);
}
