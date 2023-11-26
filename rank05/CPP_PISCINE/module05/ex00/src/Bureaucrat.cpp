#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	:_name(""), _grade(GRADE_LOWER) {}

Bureaucrat::Bureaucrat(std::string const & name)
	:_name(name), _grade(GRADE_LOWER) {}

Bureaucrat::Bureaucrat(std::string const & name, int const & grade)
	:_name(name), _grade(grade)
{
	if (grade > GRADE_LOWER)
		throw Bureaucrat::GradeTooLowException();
	if (grade < GRADE_HIGHER)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &o)
	:_name(""), _grade(o._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const &o)
{
	this->_grade = o._grade;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName();
	os << ", " << "bureaucrat grade ";
	os << b.getGrade();
    return os;
}

std::string const &		Bureaucrat::getName() const { return (this->_name); }

int const &	Bureaucrat::getGrade() const { return (this->_grade); }

void				Bureaucrat::upGrade()
{
	if (this->_grade - 1 < GRADE_HIGHER)
		throw Bureaucrat::GradeTooHighException();
	this->_grade -= 1;
}

void				Bureaucrat::upGrade(int const & grade)
{
	if (this->_grade - grade < GRADE_HIGHER)
		throw Bureaucrat::GradeTooHighException();
	this->_grade -= grade;
}

void				Bureaucrat::downGrade()
{
	if (this->_grade + 1 > GRADE_LOWER)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += 1;
}

void				Bureaucrat::downGrade(int const & grade)
{
	if (this->_grade + grade > GRADE_LOWER)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += grade;
}
