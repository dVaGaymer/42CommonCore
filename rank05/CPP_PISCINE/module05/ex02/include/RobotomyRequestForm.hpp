#pragma once
#ifndef __ROBOTOMYREQUESTFORM_HPP__
#define __ROBOTOMYREQUESTFORM_HPP__

#include <iostream>
#include <stdlib.h>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &o);
		RobotomyRequestForm(std::string const & target);
		~RobotomyRequestForm();
		RobotomyRequestForm & operator=(RobotomyRequestForm const &o);

		virtual void	execute(Bureaucrat const & executor);
};
#endif

