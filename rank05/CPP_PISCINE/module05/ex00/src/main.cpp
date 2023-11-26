#include <iostream>
#include "Bureaucrat.hpp"

int	main(void)
{
	//Bureaucrats
	try
	{
		std::string	name = "Yon";
		int			grade = -10;
		std::cout << "Test 0: Bureaucrat\n"
		<< "Name:[" << name << "]\n"
		<< "Grade:[" << grade << "]\n";
		Bureaucrat	a(name, grade);
		a.upGrade();
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n\n";

	try
	{
		std::string	name = "Cristina";
		int			grade = 151;
		std::cout << "Test 1: Bureaucrat\n"
		<< "Name:[" << name << "]\n"
		<< "Grade:[" << grade << "]\n";
		Bureaucrat	a(name, grade);
		a.upGrade();
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n\n";

	try
	{
		std::string	name = "Berto";
		int			grade = 150;
		std::cout << "Test 2: Bureaucrat\n"
		<< "Name:[" << name << "]\n"
		<< "Grade:[" << grade << "]\n"
		<< "Upgrade\n"
		<< "Sign Form\n";

		Bureaucrat	a(name, grade);
		a.upGrade();

		std::cout << "New grade: [" << a.getGrade() << "]\n";
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n\n";

	try
	{
		std::string	name = "Saul";
		int			grade = 150;
		std::cout << "Test 2: Bureaucrat\n"
		<< "Name:[" << name << "]\n"
		<< "Grade:[" << grade << "]\n"
		<< "Downgrade\n";

		Bureaucrat	a(name, grade);
		a.downGrade();

		std::cout << "New grade: [" << a.getGrade() << "]\n";
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
