/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:56:47 by mhenin            #+#    #+#             */
/*   Updated: 2025/05/19 14:56:48 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"
#include <string>
#include <exception>

class Form;

#define GREY   "\033[90m"
#define RED  "\033[31m"
#define BLUE   "\033[34m"
#define GREEN   "\033[32m"
#define RESET  "\033[0m"

class Bureaucrat
{
	private:
		const std::string	_name;
		int 				_grade;

	public:
		const int			&getGrade() const;
		const std::string	&getName() const;
		void				incrGrade();
		void				decrGrade();
		void				signForm(Form &form);
		Bureaucrat			&operator=(const Bureaucrat &bureaucrat);

		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &bureaucrat);
		~Bureaucrat();

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);
