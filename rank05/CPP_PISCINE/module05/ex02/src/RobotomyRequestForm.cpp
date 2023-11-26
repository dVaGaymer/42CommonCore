#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	:AForm("", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &o)
	:AForm(o) {}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
	:AForm(target, 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const &o)
{ (void)o; return (*this); }

void	RobotomyRequestForm::execute(Bureaucrat const & executor)
{
	AForm::execute(executor);
	srand (time(NULL));
	int	n = rand() % 1001 + 1;
	if (n%2)
		std::cout << this->getName() << " has been robotomized.\n";
	else
		std::cout << "Robotomy failed on " << this->getName() << ".\n";
}
