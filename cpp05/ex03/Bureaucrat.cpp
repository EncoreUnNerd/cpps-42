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
#include <exception>
#include <iostream>
#include <ostream>

const int &Bureaucrat::getGrade() const
{
	return (_grade);
}

const std::string	&Bureaucrat::getName() const
{
	return (_name);
}

void Bureaucrat::decrGrade(void)
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::incrGrade(void)
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << GREEN << _name << " signed " << form.getName() << "." << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << GREEN << _name << " couldn’t sign "<< form.getName() <<" because "<< e.what() << "." << RESET << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << GREEN << _name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << _name << " has failed to execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

// --- CONSTRUCTORS ---
Bureaucrat::Bureaucrat(): _name("Unknown Bureaucrat"), _grade(1) {}

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
Bureaucrat::~Bureaucrat() {}


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
