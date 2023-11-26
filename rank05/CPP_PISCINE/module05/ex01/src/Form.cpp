#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	:_name(""), _signed(false), _sign_range(GRADE_LOWER), _exe_range(GRADE_LOWER)
{
	if (this->_sign_range < GRADE_HIGHER || this->_exe_range < GRADE_HIGHER)
		throw Form::GradeTooHighException();
	if (this->_sign_range > GRADE_LOWER || this->_exe_range > GRADE_LOWER)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &o)
	:_name(o._name), _signed(o._signed), _sign_range(o._sign_range), _exe_range(o._exe_range)
{}

Form::Form(std::string const & name, int const & sign_range, int const & exe_range)
	:_name(name), _signed(false), _sign_range(sign_range), _exe_range(exe_range)
{
	if (this->_sign_range < GRADE_HIGHER || this->_exe_range < GRADE_HIGHER)
		throw Form::GradeTooHighException();
	if (this->_sign_range > GRADE_LOWER || this->_exe_range > GRADE_LOWER)
		throw Form::GradeTooLowException();
}

Form::~Form() {}

Form & Form::operator=(Form const &o)
{
	this->_signed = o._signed;
	return (*this);
}

std::string const &	Form::getName() const
{ return (this->_name); }
bool const &		Form::isSigned() const
{ return(this->_signed); }
int const &			Form::getSignRange() const
{ return (this->_sign_range); }
int const &			Form::getExeRange() const
{ return (this->_exe_range); }

void	Form::beSigned(Bureaucrat const & b)
{
	if (b.getGrade() <= this->_sign_range)
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}
