#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstddef>
#include <exception>
#include <iostream>
#include <string>

static AForm* createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}
static AForm* createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}
static AForm* createPresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
}

struct FormPair
{
	std::string name;
	AForm* (*creator)(const std::string&);
};

AForm *Intern::makeForm(std::string name, std::string target)
{
	static const FormPair forms[] = {
		{"shrubbery creation", createShrubbery},
		{"robotomy request", createRobotomy},
		{"presidential pardon", createPresidential}
	};

	// pour connaitre la taille d'une liste de struct : sizeof(forms)/sizeof(forms[0])
	try
	{
		for (size_t i = 0; i < 3; ++i) {
			if (name == forms[i].name) {
				std::cout << GREEN << "Intern creates " << name << RESET << std::endl;
				return forms[i].creator(target);
			}
		}
		std::cout << RED << "Intern cannot create " << name << " because it is unknown." << RESET << std::endl;
		return NULL;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << "Intern cannot create " << name << " because it crashed." << RESET << std::endl;
		return NULL;
	}
}

// -- Constructors -- //
Intern::Intern() {}

Intern::Intern(Intern &to_copy)
{
	(void)to_copy;
}

// --- Destructor --- //
Intern::~Intern() {}

// --- Operator --- //
Intern &Intern::operator=(Intern &to_copy)
{
	(void)to_copy;
	return (*this);
}
