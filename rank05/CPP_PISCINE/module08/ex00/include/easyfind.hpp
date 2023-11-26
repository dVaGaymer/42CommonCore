#pragma once
#ifndef __EASYFIND_HPP__
#define __EASYFIND_HPP__

#include <algorithm>

template< typename T >
int	easyfind(T cont, int n)
{
	typename T::iterator toFind = std::find(cont.begin(), cont.end(), n);
	if (toFind == cont.end())
		throw std::exception();
	return std::distance(cont.begin(), toFind);
}

#endif
