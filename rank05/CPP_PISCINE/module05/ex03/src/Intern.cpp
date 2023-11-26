#include "Intern.hpp"

Intern::Intern()
{
	this->formTypes[ROBOTOMY_REQUEST_FORM] = "robotomy request";
	this->formTypes[PRESIDENTIAL_PARDON_FORM] = "presidential pardon";
	this->formTypes[SHRUBBERY_CREATION_FORM] = "shrubbery creation";
}

Intern::Intern(Intern const &o)
{
	this->formTypes[ROBOTOMY_REQUEST_FORM] = o.formTypes[ROBOTOMY_REQUEST_FORM];
	this->formTypes[PRESIDENTIAL_PARDON_FORM] = o.formTypes[PRESIDENTIAL_PARDON_FORM];
	this->formTypes[SHRUBBERY_CREATION_FORM] = o.formTypes[SHRUBBERY_CREATION_FORM];
}

Intern::~Intern()
{}

Intern & Intern::operator=(Intern const &o)
{
	this->formTypes[ROBOTOMY_REQUEST_FORM] = o.formTypes[ROBOTOMY_REQUEST_FORM];
	this->formTypes[PRESIDENTIAL_PARDON_FORM] = o.formTypes[PRESIDENTIAL_PARDON_FORM];
	this->formTypes[SHRUBBERY_CREATION_FORM] = o.formTypes[SHRUBBERY_CREATION_FORM];
	return (*this);
}

int	Intern::getFormType(std::string const & type)
{
	for (int i = 0; i < MAX_DIFFERENT_FORMS; i++)
		if (!type.compare(this->formTypes[i]))
			return i;
	return (-1);
}

AForm	*Intern::makeForm(std::string const & type, std::string const & target)
{
	int	opt = getFormType(type);
	switch (opt)
	{
		case ROBOTOMY_REQUEST_FORM:
			return (new PresidentialPardonForm(target));
		case PRESIDENTIAL_PARDON_FORM:
			return (new RobotomyRequestForm(target));
		case SHRUBBERY_CREATION_FORM:
			return (new ShrubberyCreationForm(target));
	};
	throw Intern::FormTypeNotFound();
}
