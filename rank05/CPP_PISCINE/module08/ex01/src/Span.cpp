#include "Span.hpp"

Span::Span() {}
Span::~Span() {}

Span::Span(unsigned int const & n)
	:_max_size(n) { }

Span::Span(Span const &o)
{
	this->_max_size = o._max_size;
	this->_vector = o._vector;
}

Span & Span::operator=(Span const &o)
{
	this->_max_size = o._max_size;
	this->_vector = o._vector;
	return *this;
}

void	Span::addNumber(int const & n)
{
	if (this->_max_size <= this->_vector.size())
		throw (Span::FullSpanException());
	this->_vector.push_back(n);
}

void	Span::addNumber(std::vector<int>::iterator from, std::vector<int>::iterator to)
{
	if (this->_vector.size() + std::distance(from, to) > this->_max_size)
		throw (Span::FullSpanException());
	this->_vector.insert(this->_vector.end(), from, to);
}

//Add random values
void	Span::addMultiple(unsigned int const & n, int from, int to)
{
	srand(time(NULL));
	for (unsigned int i = 0; i < n; i++)
		this->addNumber(rand() % (to + 1 - from) + from);
}

void Span::logSpan(void)
{
	std::vector<int>::iterator it_beg = this->_vector.begin();
	std::vector<int>::iterator it_end = this->_vector.end();
	
	for (; it_beg != it_end; it_beg++)
		std::cout << "[" << *it_beg << "]";
	std::cout << std::endl;
}

void Span::logSortedSpan(void)
{
	std::vector<int> sorted = this->_vector;
	std::partial_sort_copy(this->_vector.begin(), this->_vector.end(), sorted.begin(), sorted.end());
	std::vector<int>::iterator it_beg = sorted.begin();
	std::vector<int>::iterator it_end = sorted.end();
	
	for (; it_beg != it_end; it_beg++)
		std::cout << "[" << *it_beg << "]";
	std::cout << std::endl;
}

int	Span::longestSpan()
{
	if (0 == this->_vector.size())
		throw (Span::EmptySpanException());

	std::vector<int>::iterator it = this->_vector.begin();
	std::vector<int>::iterator end = this->_vector.end();

	return (*(std::max_element(it, end)) - *(std::min_element(it, end)));
}

int	Span::shortestSpan()
{
	std::vector<int> sorted = this->_vector;
	if (0 == this->_vector.size())
		throw (Span::EmptySpanException());

	std::vector<int>::iterator it, tmp, upper;
	std::vector<int>::iterator end;
	std::partial_sort_copy(this->_vector.begin(), this->_vector.end(), sorted.begin(), sorted.end());
	it = sorted.begin();
	end = sorted.end();

	std::vector<int>::iterator span[2] = {std::min_element(it, end), std::max_element(it, end)};
	tmp = it;
	
	for (; tmp != end; tmp++)
	{
		if (*tmp == *(tmp + 1))
			return 0;
		upper = std::upper_bound(it, end, *tmp);
		if ((*upper - *tmp) < (*span[1] - *span[0]) && upper != end)
		{
			span[0] = tmp;
			span[1] = upper;
		}
	}
	return (*span[1] - *span[0]);
}

/* TEST FUNCIONS */
void	Span::shortestSpan_log()
{
	std::vector<int> sorted = this->_vector;
	if (0 == this->_vector.size())
		throw (Span::EmptySpanException());

	std::vector<int>::iterator it, tmp, upper;
	std::vector<int>::iterator end;
	std::partial_sort_copy(this->_vector.begin(), this->_vector.end(), sorted.begin(), sorted.end());
	it = sorted.begin();
	end = sorted.end();

	std::vector<int>::iterator span[2] = {std::min_element(it, end), std::max_element(it, end)};
	tmp = it;
	
	for (; tmp != end; tmp++)
	{
		if (*tmp == *(tmp + 1))
		{
			std::cout << "Shortest Span: 0 -> [" << *tmp << ", " << *tmp << "]\n";
			return ;
		}
		upper = std::upper_bound(it, end, *tmp);
		if ((*upper - *tmp) < (*span[1] - *span[0]) && upper != end)
		{
			span[0] = tmp;
			span[1] = upper;
		}
	}
	std::cout << "Shortest Span: " << *span[1] - *span[0]
		<< " -> [" << *span[0] << ", " << *span[1] << "]\n";
}
void	Span::longestSpan_log()
{
	if (0 == this->_vector.size())
		throw (Span::EmptySpanException());

	std::vector<int>::iterator it = this->_vector.begin();
	std::vector<int>::iterator end = this->_vector.end();

	std::cout << "Longest Span: " << *(std::max_element(it, end)) - *(std::min_element(it, end))
		<< " -> [" << *(std::min_element(it, end)) << ", " << *(std::max_element(it, end)) << "]\n";
}
