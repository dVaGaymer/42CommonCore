#pragma once
#ifndef __SHRUBBERYCREATIONFORM_HPP__
#define __SHRUBBERYCREATIONFORM_HPP__

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &o);
		ShrubberyCreationForm(std::string const & target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const &o);

		virtual void	execute(Bureaucrat const & executor);
};
#endif
