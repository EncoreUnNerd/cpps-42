#pragma once

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		std::string	_target;

	public:
		const std::string	&getTarget();
		void				execute(Bureaucrat const & executor) const;

		PresidentialPardonForm	&operator=(const PresidentialPardonForm &to_copy);

		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &to_copy);
		PresidentialPardonForm(const std::string target);
		~PresidentialPardonForm();
};
