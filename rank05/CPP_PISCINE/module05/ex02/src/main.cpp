#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Bureaucrat	Yon("Yon", 1);
	AForm *presidential_form = new ShrubberyCreationForm("Shrubbery");
	AForm *shrubbery_form = new PresidentialPardonForm("President");
	AForm *robotomy_form = new RobotomyRequestForm("Robot");

	Yon.signAForm(*presidential_form);
	Yon.signAForm(*shrubbery_form);
	Yon.signAForm(*robotomy_form);

	presidential_form->execute(Yon);
	shrubbery_form->execute(Yon);
	robotomy_form->execute(Yon);
	return (0);
}
