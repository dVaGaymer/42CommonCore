#include "Fixed.hpp"

Fixed::Fixed():
	_value(0)
{
	std::cout << "Default constructor called\n"; 
}

Fixed::Fixed(const Fixed &o)
{
	std::cout << "Copy constructor called\n"; 
	*this = o;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n"; 
}

Fixed & Fixed::operator=(const Fixed &o)
{
	std::cout << "Assignation operator called\n"; 
	this->_value = o.getRawBits();
	return (*this);
}

int		Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called\n"; 
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
	std::cout << "setRawBits member function called\n"; 
}
