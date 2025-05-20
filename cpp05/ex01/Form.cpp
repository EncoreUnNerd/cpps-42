#include "Form.hpp"

std::string Form::getName(void) const
{
	return (_name);
}

bool	Form::getSign(void) const
{
	return (_sign);
}

int	Form::getRSign(void) const
{
	return (_require_sign);
}

int Form::getRExec(void) const
{
	return (_require_exec);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _require_sign)
		throw GradeTooLowException();
	_sign = 1;
}

// --- Constructors --

Form::Form(void): _name("UnknownForm"), _sign(0), _require_sign(100), _require_exec(101) {}

Form::Form(const Form &to_copy): _name(to_copy._name), _sign(to_copy._sign), _require_sign(to_copy._require_sign), _require_exec(to_copy._require_exec) {}

Form::Form(std::string name, int required_sign, int required_exec): _name(name), _require_sign(required_sign), _require_exec(required_exec)
{
	if (required_sign > 150 || required_exec > 150)
		throw GradeTooLowException();
	else if (required_sign < 1 || required_exec < 1)
		throw GradeTooHighException();
}

// -- Destructor ---

Form::~Form(void) {}

// --- Operator ---

Form &Form::operator=(const Form &to_copy)
{
	if (this != &to_copy)
		_sign = to_copy._sign;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form : " << form.getName() << ", signed : " << form.getSign() << ", grade to sign : " << form.getRSign() << ", grade to execute : " << form.getRExec();
	return (os);
}

// --- Exceptions ---

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade is too high.";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is too low.";
}
