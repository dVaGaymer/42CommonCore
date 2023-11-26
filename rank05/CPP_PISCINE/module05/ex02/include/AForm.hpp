#pragma once
#ifndef __AAForm_HPP__
#define __AAForm_HPP__

#include <string>
#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_sign_grade;
		int const			_exe_grade;
	public:
		AForm();
		AForm(AForm const &o);
		AForm(std::string const & name, int const & sign_range, int const & exe_range);
		virtual ~AForm() = 0;
		AForm & operator=(AForm const &o);

		std::string const &	getName() const;
		bool const &		isSigned() const;
		int const &			getSignRange() const;
		int const &			getExeRange() const;

		void	beSigned(Bureaucrat const & b);

		virtual void	execute(Bureaucrat const & executor);

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
	class NotSignedException : public std::exception
	{
		public:
			const char*	what() const throw ()
			{ return ("Form is not signed exception"); }
	};
};

std::ostream const & operator<<(std::ostream const & os, AForm const & o);

#endif

