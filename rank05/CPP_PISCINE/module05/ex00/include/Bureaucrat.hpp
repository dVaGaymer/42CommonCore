#pragma once
#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <iostream>

#define GRADE_LOWER 150
#define GRADE_HIGHER 1

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string const & name);
		Bureaucrat(std::string const & name, int const & grade);
		Bureaucrat(Bureaucrat const &o);
		~Bureaucrat();
		Bureaucrat & operator=(Bureaucrat const &o);

		std::string	const &		getName() const;
		int const &				getGrade() const;

		void					upGrade();
		void					upGrade(int const & grade);
		void					downGrade();
		void					downGrade(int const & grade);

		/* NESTED CLASSES */
		class GradeTooHighException : public std::exception
		{
			public:
				const char*	what() const throw ()
				{ return ("Grade too high."); }
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char*	what() const throw ()
				{ return ("Grade too low."); }
		};
};

std::ostream & operator<<(std::ostream &os, Bureaucrat const &o);

#endif

