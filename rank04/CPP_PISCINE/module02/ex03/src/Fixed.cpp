#include "Fixed.hpp"

Fixed::Fixed():
	_value(0)
{
}

Fixed::Fixed(int const value)
{
	this->_value = value << Fixed::_FBITS;
}

Fixed::Fixed(float const value)
{
	this->_value = roundf(value * (1 << Fixed::_FBITS));
}

Fixed::Fixed(const Fixed &o)
{
	this->_value = o.getRawBits();
}

Fixed::~Fixed()
{
}

int		Fixed::getRawBits() const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float	Fixed::toFloat() const
{
	return ((float)this->_value / (float)(1 << Fixed::_FBITS));
}

int		Fixed::toInt() const
{
	return (this->_value >> Fixed::_FBITS);
}

Fixed& Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 <= f2)
		return (f1);
	return (f2);
}

const Fixed& Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1 <= f2)
		return (f1);
	return (f2);
}

Fixed& Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 >= f2)
		return (f1);
	return (f2);
}

const Fixed& Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1 >= f2)
		return (f1);
	return (f2);
}
