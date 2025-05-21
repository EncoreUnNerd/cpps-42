#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

const std::string &RobotomyRequestForm::getTarget()
{
	return (_target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getRExec())
		throw AForm::GradeTooLowException();
	if (rand() % 2 == 0)
		std::cout << GREEN << _target << " has been robotomized successfully." << RESET << std::endl;
	else
		std::cout << RED << _target << " robotomizing as failed." << RESET << std::endl;
}

// --- Constructors ---

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("Unknown Target") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &to_copy): AForm("RobotomyRequestForm", 72, 45), _target(to_copy._target) {}

// --- Destructor ---

RobotomyRequestForm::~RobotomyRequestForm() {}

// --- Operator ---

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &to_copy)
{
	_target = to_copy._target;
	return (*this);
}
