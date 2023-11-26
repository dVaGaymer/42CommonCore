#pragma once
#ifndef __FIXED_HPP__
#define __FIXED_HPP__

# include <iostream>

class Fixed
{
	private:
		int	_value;
		static const int	_FBITS = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &o);
		Fixed & operator=(const Fixed &o);

		int		getRawBits() const;
		void	setRawBits(int const raw);
};
#endif

