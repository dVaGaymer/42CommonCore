#include "Fixed.hpp"

Fixed & Fixed::operator=(const Fixed &o)
{
	this->_value = o.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed &o) const
{
	return (this->getRawBits() > o.getRawBits());
}
bool Fixed::operator>=(const Fixed &o) const
{
	return (this->getRawBits() >= o.getRawBits());
}
bool Fixed::operator<(const Fixed &o) const
{
	return (this->getRawBits() < o.getRawBits());
}
bool Fixed::operator<=(const Fixed &o) const
{
	return (this->getRawBits() <= o.getRawBits());
}
bool Fixed::operator==(const Fixed &o) const
{
	return (this->getRawBits() == o.getRawBits());
}
bool Fixed::operator!=(const Fixed &o) const
{
	return (this->getRawBits() != o.getRawBits());
}
Fixed Fixed::operator+(const Fixed &o)
{
	Fixed	tmp;
	tmp.setRawBits(this->_value + o.getRawBits());
	return (tmp);
}
Fixed Fixed::operator-(const Fixed &o)
{
	Fixed	tmp;
	tmp.setRawBits(this->_value - o.getRawBits());
	return (tmp);
}

Fixed Fixed::operator*(const Fixed &o)
{
	Fixed	tmp;
	tmp.setRawBits((this->_value * o.getRawBits()) >> Fixed::_FBITS);
	return (tmp);
}

Fixed Fixed::operator/(const Fixed &o)
{
	return ((this->_value / o.getRawBits()));
}

Fixed & Fixed::operator++(void)
{
	this->_value += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	tmp = *this;
	this->_value += 1;
	return (tmp);
}

Fixed & Fixed::operator--(void)
{
	this->_value -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{

	Fixed	tmp = *this;
	this->_value -= 1;
	return (tmp);
}

std::ostream & operator<<(std::ostream &out, const Fixed &f)
{
	out << f.toFloat();
	return (out);
}
