#include "PmergeMe.hpp"

/* std::vector<int> */

void	insertion_vector(std::vector<int>::iterator beg, std::vector<int>::iterator end)
{
	int	tmp;
	std::vector<int>::iterator	left, right, real_beg = beg;
	beg++;
	for (; beg != end; beg++)
	{
		for (left = beg - 1, right = beg;
			left >= real_beg && *left  > *right; left--, right--)
		{
			tmp = *right;
			*right = *left;
			*left = tmp;
		}
	}
}

void	merge_vector(std::vector<int>::iterator beg, std::vector<int>::iterator mid,
			std::vector<int>::iterator end)
{
	std::vector<int>	left(beg, mid + 1), right(mid + 1, end);
	std::vector<int>::iterator lbeg, rbeg;

	for (lbeg = left.begin(), rbeg = right.begin();
		lbeg != left.end() && rbeg != right.end(); beg++)
	{
		if (*lbeg <= *rbeg)
			*beg = *lbeg++;
		else
			*beg = *rbeg++;
	}
	for (; lbeg != left.end(); lbeg++, beg++)
		*beg = *lbeg;
	for (; rbeg != right.end(); rbeg++, beg++)
		*beg = *rbeg;
}

void	mergeinsert_vector(std::vector<int>::iterator beg, std::vector<int>::iterator end,
	unsigned int group_size)
{
	std::vector<int>::iterator mid;
	mid = beg;
	std::advance(mid, (std::distance(beg, end) - 1) / 2);
	if (std::distance(beg, end - 1) >=  group_size) //The size of the subgroups
	{
		mergeinsert_vector(beg, mid + 1, group_size);
		mergeinsert_vector(mid + 1, end, group_size);
		merge_vector(beg, mid, end);
	}
	else
		insertion_vector(beg, end);
}

/* std::list<int> */

void	insertion_list(std::list<int>::iterator beg, std::list<int>::iterator end)
{
	int	tmp;
	std::list<int>::iterator	left, right, real_beg = beg;
	beg++;
	for (; beg != end; beg++)
	{
		for (left = ++beg, right = --beg;
			left != real_beg && *left  > *right; left--, right--)
		{
			tmp = *right;
			*right = *left;
			*left = tmp;
		}
	}
}

void	merge_list(std::list<int>::iterator beg, std::list<int>::iterator mid,
			std::list<int>::iterator end)
{
	std::list<int>	left(beg, ++mid), right(mid, end);
	std::list<int>::iterator lbeg, rbeg;

	mid--;
	for (lbeg = left.begin(), rbeg = right.begin();
		lbeg != left.end() && rbeg != right.end(); beg++)
	{
		if (*lbeg <= *rbeg)
			*beg = *lbeg++;
		else
			*beg = *rbeg++;
	}
	for (; lbeg != left.end(); lbeg++, beg++)
		*beg = *lbeg;
	for (; rbeg != right.end(); rbeg++, beg++)
		*beg = *rbeg;
}

void	mergeinsert_list(std::list<int>::iterator beg, std::list<int>::iterator end,
	unsigned int group_size)
{
	std::list<int>::iterator mid;
	mid = beg;
	std::advance(mid, (std::distance(beg, end) - 1) / 2);
	end--;
	if (std::distance(beg, end) >=  group_size) //The size of the subgroups
	{
		end++;
		mergeinsert_list(beg, ++mid, group_size);
		mergeinsert_list(mid, end, group_size);
		merge_list(beg, --mid, end);
	}
	else
	{
		end++;
		insertion_list(beg, end);
	}
}

/* *********************************************************** */

static int	stoi(std::string str)
{
	int		neg = (str[0] == '-') ? -1 : 1;
	float	n = 0;

	std::string::iterator itb = str.begin() + (neg == -1);
	std::string::iterator ite = str.end();
	while (*itb == ' ' && itb != ite) itb++;
	for (; (*itb >= '0' && *itb <= '9') && itb != ite; itb++)
			n = (n * 10) + (*itb - 48);
	while (*itb == ' ' && itb != ite) itb++;
	if (itb == ite) return (neg * n);
		throw std::runtime_error("Error: bad syntax.");
}

void	PmergeMe::logVector(bool full_log)
{
	std::vector<int>::iterator	itb = this->_vector.begin();
	std::vector<int>::iterator	ite = this->_vector.end();
	int i, max = (full_log) ? this->_vector.size() : 10;
	for (i = 0; itb != ite && i < max; itb++, i++)
	{
		std::cout << *itb;
		if (itb + 1 != ite && i + 1 < max)
			std::cout << ((full_log) ? "\n" : " ");
	}
	if (i >= max && !full_log)
		std::cout << " [...]";
	std::cout << std::endl;
}

void	PmergeMe::logList(bool full_log)
{
	std::list<int>::iterator	itb = this->_list.begin();
	std::list<int>::iterator	ite = this->_list.end();
	int i, max = (full_log) ? this->_vector.size() : 10;
	for (i = 0; itb != ite && i < max; itb++, i++)
	{
		std::cout << *itb;
		if (++itb != ite && i + 1 < max)
			std::cout << ((full_log) ? "\n" : " ");
		--itb;
	}
	if (i >= max && !full_log)
		std::cout << " [...]";
	std::cout << std::endl;
}

void	PmergeMe::fillContainers(const char ** numbers)
{
	for (unsigned int i = 0; *(numbers + i); i++)
	{
		this->_vector.push_back(::stoi(*(numbers + i)));
		this->_list.push_back(::stoi(*(numbers + i)));
	}
}

PmergeMe::PmergeMe(const char ** numbers, unsigned int group_size)
{
	clock_t	start; double	totalTime;
	this->fillContainers(numbers);
	std::cout << "Before:\t"; this->logVector(false);

	start = clock();
	mergeinsert_vector(this->_vector.begin(), this->_vector.end(), group_size);
	totalTime = static_cast<double>(clock() - start)/CLOCKS_PER_SEC;
	std::cout << "After:\t"; this->logVector(false);

	std::cout << "Time to proccess a range of " << this->_vector.size() << " elements ";
	std::cout << "with std::vector<int>:\t" << totalTime << " s" << std::endl;

	start = clock();
	mergeinsert_list(this->_list.begin(), this->_list.end(), group_size);
	totalTime = static_cast<double>(clock() - start)/CLOCKS_PER_SEC;
	std::cout << "Time to proccess a range of " << this->_list.size() << " elements ";
	std::cout << "with std::list<int>:\t\t" << totalTime << " s" << std::endl;
}
