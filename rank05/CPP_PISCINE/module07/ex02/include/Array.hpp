#pragma once
#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

template<typename T>
class Array
{
	private:
		T *				_array;
		unsigned int	_size;
	public:
		Array(void);
		Array(unsigned int n);
		Array(Array const &o);
		~Array(void);
		Array & operator=(Array const &o) const;
		T & operator[](unsigned int i) const;
		unsigned int	size(void) const;
};
#endif

