#pragma once
#ifndef __WHATEVER_HPP__
#define __WHATEVER_HPP__

template<typename T>
void	swap(T &x, T &y)
{
	T	tmp;
	tmp = x;
	x = y;
	y = tmp;
}

template<typename T>
T	min(T x, T y)
{
	return (y <= x ? y : x);
}

template<typename T>
T	max(T x, T y)
{
	return (y >= x ? y : x);
}

#endif
