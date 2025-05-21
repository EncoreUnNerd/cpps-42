#include "AForm.hpp"

const std::string &AForm::getName() const
{
	return (_name);
}

const bool	&AForm::getSign() const
{
	return (_sign);
}

const int	&AForm::getRSign() const
{
	return (_require_sign);
}

const int	&AForm::getRExec() const
{
	return (_require_exec);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _require_sign)
		throw GradeTooLowException();
	_sign = 1;
}

// --- Constructors --

AForm::AForm(): _name("UnknownForm"), _sign(0), _require_sign(100), _require_exec(101) {}

AForm::AForm(const AForm &to_copy): _name(to_copy._name), _sign(to_copy._sign), _require_sign(to_copy._require_sign), _require_exec(to_copy._require_exec) {}

AForm::AForm(std::string name, int required_sign, int required_exec): _name(name), _require_sign(required_sign), _require_exec(required_exec)
{
	if (required_sign > 150 || required_exec > 150)
		throw GradeTooLowException();
	else if (required_sign < 1 || required_exec < 1)
		throw GradeTooHighException();
}

// -- Destructor ---

AForm::~AForm() {}

// --- Operator ---

AForm &AForm::operator=(const AForm &to_copy)
{
	if (this != &to_copy)
		_sign = to_copy._sign;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "Form : " << form.getName() << ", signed : " << form.getSign() << ", grade to sign : " << form.getRSign() << ", grade to execute : " << form.getRExec();
	return (os);
}

// --- Exceptions ---

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high.";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low.";
}
