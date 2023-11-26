#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	:AForm("", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &o)
	:AForm(o) {}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target)
	:AForm(target, 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const &o) //No veo que tengo sentido el operador de copia en este caso
{ (void)o; return (*this); }

void	PresidentialPardonForm::execute(Bureaucrat const & executor)
{
	AForm::execute(executor);
	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox.\n";
}
