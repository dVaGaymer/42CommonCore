#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toFloat() << " as float" << std::endl;
 
	std::cout << "------------------------\n";
	Fixed	f1(12.10f);
	Fixed	f2(12.10f);

	if (f1 < f2)
		std::cout << "F1 is smaller" << std::endl;
	if (f1 > f2)
		std::cout << "F1 is greater" << std::endl;
	if (f1 == f2)
		std::cout << "Are the same" << std::endl;

	std::cout << "------------------------\n";
	Fixed a1;
	Fixed const b1( Fixed( 5.05f ) * Fixed( 2.0f ) );

	std::cout << a1 << std::endl;
	std::cout << ++a1 << std::endl;
	std::cout << a1 << std::endl;
	std::cout << a1++ << std::endl;
	std::cout << a1 << std::endl;
	std::cout << b1 << std::endl;
	std::cout << f1 + f2 << std::endl;
	std::cout << Fixed::max( a1, b1 ) << std::endl;

	std::cout << "-----------SUBJECT-------------\n";
	Fixed a_s;
	Fixed const b_s( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a_s << std::endl;
	std::cout << ++a_s << std::endl;
	std::cout << a_s << std::endl;
	std::cout << a_s++ << std::endl;
	std::cout << a_s << std::endl;
	std::cout << b_s << std::endl;
	std::cout << Fixed::max( a_s, b_s ) << std::endl;
	return 0;
}
