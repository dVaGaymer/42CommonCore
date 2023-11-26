#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	//Forms
	try
	{
		Bureaucrat	b("Gus", 1);
		Form		f("form1", 8, 2);
		b.signForm(f);
	}
	catch (std::exception & e)
	{ std::cerr << e.what() << std::endl; }

	try
	{
		Bureaucrat	b("Walt", 1);
		Form		f("form2", 0, 2);
		b.signForm(f);
	}
	catch (std::exception & e)
	{ std::cerr << e.what() << std::endl; }

	try
	{
		Bureaucrat	b("Saul", 1);
		Form		f("form2", 1, 0);
		b.signForm(f);
	}
	catch (std::exception & e)
	{ std::cerr << e.what() << std::endl; }

	try
	{
		Bureaucrat	b("Saul", 1);
		Form		f("form2", 1, 151);
		b.signForm(f);
	}
	catch (std::exception & e)
	{ std::cerr << e.what() << std::endl; }

	try
	{
		Bureaucrat	b("Saul", 1);
		Form		f("form2", 151, 150);
		b.signForm(f);
	}
	catch (std::exception & e)
	{ std::cerr << e.what() << std::endl; }

	try
	{
		Bureaucrat	b("Saul", 2);
		Form		f("form2", 1, 1);
		b.signForm(f);
	}
	catch (std::exception & e)
	{ std::cerr << e.what() << std::endl; }
	return (0);
}
