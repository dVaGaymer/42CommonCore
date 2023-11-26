#pragma once
#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <vector>
#include <list>
#include <iostream>
#include <ctime>

class PmergeMe
{
	private:
		std::vector<int>	_vector;
		std::list<int>		_list;
		PmergeMe(PmergeMe const &o);
		PmergeMe & operator=(PmergeMe const &o);

		void	fillContainers(const char ** numbers);
	public:
		PmergeMe(const char ** numbers, unsigned int group_size);
		void	logVector(bool full_log);
		void	logList(bool full_log);
		~PmergeMe(){}
};
#endif

