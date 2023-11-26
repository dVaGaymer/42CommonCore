#include "Array.hpp"

template<typename T>
Array<T>::Array(void)
	:_array(new T), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int n)
	:_array(new T[n]), _size(n) {}

template<typename T>
Array<T>::Array(Array<T> const &o)
{
	this->_array = new T[o._size];
	this->_size = o._size;
	for (unsigned int i = 0; i < o._size; i++)
		(*this)[i] = o[i];
}

template<typename T>
Array<T>::~Array(void)
{
	delete[] this->_array;
}

template<typename T>
Array<T> & Array<T>::operator=(Array<T> const &o) const
{
	delete[] this->_array;
	this->_array = new T[o._size];
	this->_size = o._size;
	for (unsigned int i = 0; i < o._size; i++)
		*this[i] = o[i];
	return *this;
}

template<typename T>
T & Array<T>::operator[](unsigned int i) const
{
	if (i >= this->_size)
		throw (std::exception());
	return this->_array[i];
}

template<typename T>
unsigned int	Array<T>::size(void) const
{
	return this->_size;
}
