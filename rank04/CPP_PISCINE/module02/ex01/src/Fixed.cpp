#include "Fixed.hpp"

Fixed::Fixed():
	_value(0)
{
	std::cout << "Default constructor called\n"; 
}

Fixed::Fixed(int const value)
{
	std::cout << "Int constructor called\n"; 
	this->_value = value << Fixed::_FBITS;
}

Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called\n"; 
	this->_value = roundf(value * (1 << Fixed::_FBITS));
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
	this->_value = o._value;
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

float	Fixed::toFloat() const
{
	return ((float)this->_value / (float)(1 << Fixed::_FBITS));
}

int		Fixed::toInt() const
{
	return (this->_value >> Fixed::_FBITS);
}

std::ostream & operator<<(std::ostream &out, const Fixed &f)
{
	out << f.toFloat();
	return (out);
}
