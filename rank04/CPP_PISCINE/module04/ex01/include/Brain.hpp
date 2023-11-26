#pragma once
#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

# define BRAIN_IDEAS 100

#include <string>
#include <iostream>

class Brain
{
	private:
		std::string	_ideas[BRAIN_IDEAS];
	public:
		Brain();
		Brain(std::string idea_type);
		Brain(Brain const &o);
		~Brain();
		Brain & operator=(Brain const &o);

		void printIdeas() const;
};
#endif

