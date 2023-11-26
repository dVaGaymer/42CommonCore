#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Intern	thing;
	Bureaucrat	Yon("Yon", 1);
	AForm *presidential_form = thing.makeForm("presidential pardon", "President");
	AForm *shrubbery_form = thing.makeForm("robotomy request", "Robot");
	AForm *robotomy_form = thing.makeForm("shrubbery creation", "Shrubbery");

	try
	{
		AForm *fail = thing.makeForm("random form", "Shrubbery");
		(void)fail;
	}
	catch (std::exception & e)
	{ std::cout << "ERROR: " << e.what() << std::endl; }

	Yon.signAForm(*presidential_form);
	Yon.signAForm(*shrubbery_form);
	Yon.signAForm(*robotomy_form);

	presidential_form->execute(Yon);
	shrubbery_form->execute(Yon);
	robotomy_form->execute(Yon);

	delete presidential_form;
	delete shrubbery_form;
	delete robotomy_form;
	return (0);
}
