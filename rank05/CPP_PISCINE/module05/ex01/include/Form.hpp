#pragma once
#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_sign_range;
		int const			_exe_range;
	public:
		Form();
		Form(Form const &o);
		Form(std::string const & name, int const & sign_range, int const & exe_range);
		~Form();
		Form & operator=(Form const &o);

		std::string const &	getName() const;
		bool const &		isSigned() const;
		int const &			getSignRange() const;
		int const &			getExeRange() const;

		void	beSigned(Bureaucrat const & b);

	/* NESTED CLASSES */
	class GradeTooHighException : public std::exception
	{
		public:
			const char*	what() const throw ()
			{ return ("Form grade too high exception"); }
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char*	what() const throw ()
			{ return ("Form grade too low excpetion"); }
	};
};

std::ostream const & operator<<(std::ostream const & os, Form const & o);

#endif

