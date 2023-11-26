#include "../include/PmergeMe.hpp"

#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>


typedef std::vector<int>::iterator iter;

void	mergesort(iter & beg, iter & mid, iter & end);

void	mergesort(iter & beg, iter & mid, iter & end)
{
	unsigned int mid1 = (mid - beg)/2;
	unsigned int mid2 = (end - mid)/2;
	if (beg >= end) return ;
	mergesort(beg, beg + 4, mid);
	mergesort(mid, mid + mid2, end);
}

int main(int argc, const char **argv)
{
	/*-----------------------------------------------------*/
	if (argc == 1)
		return (-1);
	std::cout << "Group Size: 5\n";
	PmergeMe pm(argv + 1, 5);
	return (0);
}
