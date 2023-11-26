#pragma once
#ifndef __FIXED_HPP__
#define __FIXED_HPP__

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int	_value;
		static const int	_FBITS = 8;
	public:
		Fixed();
		Fixed(int const value);
		Fixed(float const value);
		~Fixed();
		Fixed(const Fixed &o);

		bool operator>(const Fixed &o) const;
		bool operator>=(const Fixed &o) const;
		bool operator<(const Fixed &o) const;
		bool operator<=(const Fixed &o) const;
		bool operator==(const Fixed &o) const;
		bool operator!=(const Fixed &o) const;

		Fixed & operator=(const Fixed &o);
		Fixed operator+(const Fixed &o);
		Fixed const operator+(const Fixed &o) const;
		Fixed operator-(const Fixed &o);
		Fixed const operator-(const Fixed &o) const;
		Fixed operator*(const Fixed &o);
		Fixed operator*(const Fixed &o) const;
		Fixed operator/(const Fixed &o);

		Fixed & operator++(void);
		Fixed operator++(int);
		Fixed & operator--(void);
		Fixed operator--(int);

		float	toFloat() const;
		int		toInt() const;
		int		getRawBits() const;
		void	setRawBits(int const raw);

		static Fixed& min(Fixed &f1, Fixed &f2);
		static const Fixed& min(const Fixed &f1, const Fixed &f2);
		static Fixed& max(Fixed &f1, Fixed &f2);
		static const Fixed& max(const Fixed &f1, const Fixed &f2);
};

std::ostream & operator<<(std::ostream &out, const Fixed &c);

#endif

