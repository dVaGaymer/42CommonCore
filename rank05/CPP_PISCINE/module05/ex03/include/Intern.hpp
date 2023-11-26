#pragma once
#ifndef __INTERN_HPP__
#define __INTERN_HPP__

# define MAX_DIFFERENT_FORMS 4

#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

enum
{
	ROBOTOMY_REQUEST_FORM = 0,
	PRESIDENTIAL_PARDON_FORM,
	SHRUBBERY_CREATION_FORM
};


class Intern
{
	private:
		std::string	formTypes[MAX_DIFFERENT_FORMS];
		int	getFormType(std::string const & type);
	public:
		Intern();
		Intern(Intern const &o);
		~Intern();
		Intern & operator=(Intern const &o);

		AForm	*makeForm(std::string const & type, std::string const & target);

		/* NESTED CLASSES */
		class FormTypeNotFound : public std::exception
		{
			public:
				const char*	what() const throw() //says func. wont throw anything
				{ return ("Form not found"); }
		};
};
#endif
