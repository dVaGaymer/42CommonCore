#include  <vector>
#include  <iostream>
#include  <list>

#include "easyfind.hpp"

int main( void )
{
	//vector<int> test
	try
	{
		std::vector< int >	cont;
		cont.push_back(6); cont.push_back(7); cont.push_back(4);
		cont.push_back(0); cont.push_back(2); cont.push_back(4);
		cont.push_back(10); cont.push_back(120); cont.push_back(432);
		int	n = easyfind< std::vector< int > >(cont, 6);
		std::cout << "Found at index: " << n << std::endl;
	} catch (std::exception & e)
	{
		std::cout << "Not found\n";
	}

	//vector<int> test
	try
	{
		std::vector< int >	cont;
		cont.push_back(6); cont.push_back(7); cont.push_back(4);
		cont.push_back(0); cont.push_back(2); cont.push_back(4);
		cont.push_back(10); cont.push_back(120); cont.push_back(432);
		int	n = easyfind< std::vector< int > >(cont, 100);
		std::cout << "Found at index: " << n << std::endl;
	} catch (std::exception & e)
	{
		std::cout << "Not found\n";
	}

	//list<int> test
	try
	{
		std::list< int >	cont;
		cont.push_back(6); cont.push_back(7); cont.push_back(4);
		cont.push_back(0); cont.push_back(2); cont.push_back(4);
		cont.push_back(10); cont.push_back(120); cont.push_back(432);
		int	n = easyfind< std::list< int > >(cont, 120);
		std::cout << "Found at index: " << n << std::endl;
	} catch (std::exception & e)
	{
		std::cout << "Not found\n";
	}

	//list<int> test
	try
	{
		std::list< int >	cont;
		cont.push_back(6); cont.push_back(7); cont.push_back(4);
		cont.push_back(0); cont.push_back(2); cont.push_back(4);
		cont.push_back(10); cont.push_back(120); cont.push_back(432);
		int	n = easyfind< std::list< int > >(cont, 4242);
		std::cout << "Found at index: " << n << std::endl;
	} catch (std::exception & e)
	{
		std::cout << "Not found\n";
	}
	return 0;
}
