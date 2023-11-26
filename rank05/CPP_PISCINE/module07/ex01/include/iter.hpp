#pragma once
#ifndef __ITER_HPP__
#define __ITER_HPP__

template<typename T>
void	iter(T * array, unsigned int n, void (func)(T))
{
	for (unsigned int i = 0; i < n; i++)
		func(array[i]);
}

#endif
