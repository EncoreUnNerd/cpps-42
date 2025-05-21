#pragma once

#include "Bureaucrat.hpp"
#include <ostream>
#include <string>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_sign;
		const int			_require_sign;
		const int			_require_exec;

	public:
		const std::string	&getName() const;
		const bool			&getSign() const;
		const int			&getRExec() const;
		const int			&getRSign() const;
		void				beSigned(const Bureaucrat &bureaucrat);
		virtual void		execute(Bureaucrat const & executor) const = 0;

		AForm 				&operator=(const AForm &to_copy);

		AForm();
		AForm(std::string name, int required_sign, int required_exec);
		AForm(const AForm &to_copy);
		~AForm();

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const AForm &form);
