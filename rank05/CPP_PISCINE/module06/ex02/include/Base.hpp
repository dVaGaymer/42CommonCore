#pragma once
#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <cstdlib>
#include <ctime>
#include <iostream>

class Base
{
	public:
		virtual ~Base();
	public:
		static Base * generate(void);
		static void identify(Base * p);
		static void identify(Base & p);
};
#endif

