/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:57:03 by mhenin            #+#    #+#             */
/*   Updated: 2025/05/19 14:57:04 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <ostream>

const int	&Bureaucrat::getGrade() const
{
	return (_grade);
}

const std::string	&Bureaucrat::getName() const
{
	return (_name);
}

void Bureaucrat::decrGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::incrGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

// --- CONSTRUCTORS ---
Bureaucrat::Bureaucrat(void): _name("Unknown Bureaucrat"), _grade(1) {}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade = grade;
}

// Ici je verifie le grade, si jamais on peut modif un Bureaucrat
Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat): _name(bureaucrat._name)
{
	if (bureaucrat._grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (bureaucrat._grade < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade = bureaucrat._grade;
}

// --- DESTRUCTOR ---
Bureaucrat::~Bureaucrat(void) {}


// --- OPERATORS ---
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	if (this == &bureaucrat)
	{
		if (bureaucrat._grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (bureaucrat._grade < 1)
			throw Bureaucrat::GradeTooHighException();
		_grade = bureaucrat._grade;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}

// --- EXCEPTIONS ---
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low.";
}
