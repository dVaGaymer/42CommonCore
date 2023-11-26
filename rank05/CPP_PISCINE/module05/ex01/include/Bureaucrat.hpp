#pragma once
#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <iostream>

class Form;

#define GRADE_LOWER 150
#define GRADE_HIGHER 1

class Bureaucrat
{
	private:
		std::string const	_name;
		int	_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string const & name);
		Bureaucrat(std::string const & name, int const & grade);
		Bureaucrat(Bureaucrat const &o);
		~Bureaucrat();
		Bureaucrat & operator=(Bureaucrat const &o);

		std::string	const &	getName() const;
		int const &	getGrade() const;

		void	upGrade();
		void	upGrade(int const & grade);
		void	downGrade();
		void	downGrade(int const & grade);

		void	signForm(Form & form);

		/* NESTED CLASSES */
		class GradeTooHighException : public std::exception
		{
			public:
				const char*	what() const throw() //says func. wont throw anything
				{ return ("Bureacrat grade too high exception"); }
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char*	what() const throw ()
				{ return ("Bureaucrat grade too low exception"); }
		};
};

std::ostream & operator<<(std::ostream &os, Bureaucrat const &o);

#endif

