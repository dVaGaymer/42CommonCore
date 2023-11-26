#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	:_name(""), _signed(false), _sign_grade(GRADE_LOWER), _exe_grade(GRADE_LOWER)
{
	if (this->_sign_grade < GRADE_HIGHER || this->_exe_grade < GRADE_HIGHER)
		throw AForm::GradeTooHighException();
	if (this->_sign_grade > GRADE_LOWER || this->_exe_grade > GRADE_LOWER)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &o)
	:_name(o._name), _signed(o._signed), _sign_grade(o._sign_grade), _exe_grade(o._exe_grade)
{}

AForm::AForm(std::string const & name, int const & sign_range, int const & exe_range)
	:_name(name), _signed(false), _sign_grade(sign_range), _exe_grade(exe_range)
{
	if (this->_sign_grade < GRADE_HIGHER || this->_exe_grade < GRADE_HIGHER)
		throw AForm::GradeTooHighException();
	if (this->_sign_grade > GRADE_LOWER || this->_exe_grade > GRADE_LOWER)
		throw AForm::GradeTooLowException();
}

AForm::~AForm() {}

AForm & AForm::operator=(AForm const &o)
{
	this->_signed = o._signed;
	return (*this);
}

std::string const &	AForm::getName() const
{ return (this->_name); }
bool const &		AForm::isSigned() const
{ return(this->_signed); }
int const &			AForm::getSignRange() const
{ return (this->_sign_grade); }
int const &			AForm::getExeRange() const
{ return (this->_exe_grade); }

void	AForm::beSigned(Bureaucrat const & b)
{
	if (b.getGrade() <= this->_sign_grade)
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}

void	AForm::execute(Bureaucrat const & executor)
{
	if (!this->_signed)
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->_exe_grade)
		throw AForm::GradeTooLowException();
}
