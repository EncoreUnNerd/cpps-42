#pragma once

#include "AForm.hpp"
#include <string>

class	RobotomyRequestForm: public AForm
{
	private:
		std::string	_target;

	public:
		const std::string	&getTarget();
		void				execute(Bureaucrat const & executor) const;

		RobotomyRequestForm	&operator=(const RobotomyRequestForm &to_copy);

		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &to_copy);
		RobotomyRequestForm(const std::string target);
		~RobotomyRequestForm();
};
