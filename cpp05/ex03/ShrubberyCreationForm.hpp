#pragma once

#include "AForm.hpp"
#include <string>

class	ShrubberyCreationForm: public AForm
{
	private:
		std::string	_target;

	public:
		const std::string	&getTarget();
		void				execute(Bureaucrat const & executor) const;

		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &to_copy);

		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &to_copy);
		ShrubberyCreationForm(const std::string target);
		~ShrubberyCreationForm();
};
