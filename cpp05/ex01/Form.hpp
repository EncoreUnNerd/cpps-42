#pragma once

#include "Bureaucrat.hpp"
#include <ostream>
#include <string>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_sign;
		const int			_require_sign;
		const int			_require_exec;

	public:
		std::string	getName(void) const;
		bool		getSign(void) const;
		int			getRExec(void) const;
		int			getRSign(void) const;
		void		beSigned(const Bureaucrat &bureaucrat);
		Form &operator=(const Form &to_copy);

		Form(void);
		Form(std::string name, int required_sign, int required_exec);
		Form(const Form &to_copy);
		~Form(void);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Form &form);
