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
		Fixed & operator=(const Fixed &o);

		float	toFloat() const;
		int		toInt() const;
		int		getRawBits() const;
		void	setRawBits(int const raw);
};

std::ostream & operator<<(std::ostream &out, const Fixed &c);
#endif

