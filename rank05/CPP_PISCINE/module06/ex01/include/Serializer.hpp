#pragma once
#ifndef __SERIALIZER_HPP__
#define __SERIALIZER_HPP__

#include <string>
#include <stdint.h>

typedef struct s_data
{
	std::string element_0;
}		Data;

class Serializer {
	public:
	Serializer();
	Serializer(Serializer const &o);
	~Serializer();
	Serializer &operator=(Serializer const &o);

	static uintptr_t serialize(Data *ptr);
	static Data* deserialize(uintptr_t raw);
};
#endif
