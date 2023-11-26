#pragma once
#ifndef __SPAN_HPP__
#define __SPAN_HPP__

#include <vector>
#include <iostream>
#include <stdlib.h>

class Span
{
	private:
		unsigned int		_max_size;
		std::vector<int>	_vector;
		Span();

		class FullSpanException : public std::exception
		{
			public:
				const char * what() const throw ()
				{ return ("Span is full"); }
		};

		class EmptySpanException : public std::exception
		{
			public:
				const char * what() const throw ()
				{ return ("Span is empty"); }
		};
	public:
		Span(unsigned int const & N);
		Span(Span const &o);
		~Span();
		Span & operator=(Span const &o);
		int	shortestSpan();
		int	longestSpan();
		void	addNumber(int const & n);
		void	addNumber(std::vector<int>::iterator from, std::vector<int>::iterator to);
		void	addMultiple(unsigned int const & n, int from, int to);
		void	logSpan(void);
		void	logSortedSpan(void);

		void	shortestSpan_log();
		void	longestSpan_log();
};
#endif
