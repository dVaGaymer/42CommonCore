#pragma once
#ifndef __PRESIDENTIALPARDONFORM_HPP__
#define __PRESIDENTIALPARDONFORM_HPP__

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &o);
		PresidentialPardonForm(std::string const & target);
		~PresidentialPardonForm();
		PresidentialPardonForm & operator=(PresidentialPardonForm const &o);

		virtual void	execute(Bureaucrat const & executor);
};
#endif

