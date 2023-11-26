#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
	if (bsp(Point(-1.0f, 0.0f), Point(1.0, 0.0), Point(2.0, 2.0), Point(1.1, 0.0)))
		std::cout << "IS INSIDE" << std::endl;
	else
		std::cout << "IS NOT" << std::endl;


	if (bsp(Point(2.14f, 3.59f), Point(-2.14, 3.06), Point(0.01, 0.02), Point(-3.26, -0.53)))
		std::cout << "IS INSIDE" << std::endl;
	else
		std::cout << "IS NOT" << std::endl;


	if (bsp(Point(2.14f, 3.59f), Point(-2.14, 3.06), Point(0.01, 0.02), Point(-0.94, 2.64)))
		std::cout << "IS INSIDE" << std::endl;
	else
		std::cout << "IS NOT" << std::endl;

	if (bsp(Point(2.14f, 3.59f), Point(-2.14, 3.06), Point(0.01, 0.02), Point(1.01, 2.02)))
		std::cout << "IS INSIDE" << std::endl;
	else
		std::cout << "IS NOT" << std::endl;
	return 0;
}
