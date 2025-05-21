#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

const std::string &PresidentialPardonForm::getTarget()
{
	return (_target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getRExec())
		throw AForm::GradeTooLowException();
	std::cout << GREEN << _target << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}

// --- Constructors ---

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("Unknown Target") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &to_copy): AForm("PresidentialPardonForm", 25, 5), _target(to_copy._target) {}

// --- Destructor ---

PresidentialPardonForm::~PresidentialPardonForm() {}

// --- Operator ---

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &to_copy)
{
	_target = to_copy._target;
	return (*this);
}
