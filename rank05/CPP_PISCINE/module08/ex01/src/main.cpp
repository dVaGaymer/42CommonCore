#include  <iostream>
#include "Span.hpp"
#include <random>

int main()
{
	Span sp = Span(11);
	std::vector<int>	v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(100);
	v.push_back(4);
	v.push_back(5);

	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
	} catch (...) { std::cout << "Error while normal adding\n"; }
	try
	{
		sp.addNumber(v.begin(), v.end());
	} catch (...) { std::cout << "Error while iterator adding\n"; }
	try
	{
		sp.addMultiple(300, 45, 50);
	} catch (...) { std::cout << "Error while multiple adding\n"; }
	sp.logSpan();
	// sp.logSortedSpan();
	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	sp.shortestSpan_log();
	sp.longestSpan_log();

	/* MORE TESTS */
	std::cout << "\nSpan 0 (subject)\n";
	Span sp1 = Span(5);
	sp1.addNumber(6);
	sp1.addNumber(3);
	sp1.addNumber(17);
	sp1.addNumber(9);
	sp1.addNumber(11);
	sp1.logSpan();
	// sp1.logSortedSpan();
	std::cout << "Shortest Span: " << sp1.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp1.longestSpan() << std::endl;
	sp1.shortestSpan_log();
	sp1.longestSpan_log();

	std::cout << "\nSpan 1\n";
	Span sp2 = Span(20);
	sp2.addMultiple(20, 0, 1000);
	// sp2.logSpan();
	sp2.logSortedSpan();
	std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;
	sp2.shortestSpan_log();
	sp2.longestSpan_log();

	std::cout << "\nSpan 2\n";
	Span sp3 = Span(11);
	sp3.addNumber(6);
	sp3.addNumber(3);
	sp3.addNumber(17);
	sp3.addNumber(9);
	sp3.addNumber(11);
	sp3.addNumber(3);
	sp3.logSpan();
	// sp3.logSortedSpan();
	std::cout << "Shortest Span: " << sp3.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp3.longestSpan() << std::endl;
	sp3.shortestSpan_log();
	sp3.longestSpan_log();

	std::cout << "\nSpan 3\n";
	Span sp4 = Span(11);
	sp4.addNumber(0);
	sp4.addNumber(172);
	sp4.addNumber(11);
	sp4.addNumber(-911);
	sp4.logSpan();
	// sp4.logSortedSpan();
	std::cout << "Shortest Span: " << sp4.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp4.longestSpan() << std::endl;
	sp4.shortestSpan_log();
	sp4.longestSpan_log();

	std::cout << "\nSpan 4\n";
	Span sp5 = Span(10000);
	sp5.addMultiple(5000, 0, 10000000);
	sp5.addMultiple(5000, 0, 10000000);
	sp5.logSpan();
	// sp5.logSortedSpan();
	std::cout << "Shortest Span: " << sp5.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp5.longestSpan() << std::endl;
	sp5.shortestSpan_log();
	sp5.longestSpan_log();
	return 0;
}
