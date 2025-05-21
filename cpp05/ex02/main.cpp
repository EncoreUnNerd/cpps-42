/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:09:22 by mhenin            #+#    #+#             */
/*   Updated: 2025/05/21 18:16:12 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

void tester(Bureaucrat bureaucrat)
{
	std::cout << GREEN << "=== DÉBUT DES TESTS POUR " << bureaucrat.getName() << " (Grade " << bureaucrat.getGrade() << ") ===" << RESET << std::endl;

	// Test d'augmentation du grade
	std::cout << GREEN << "\n--- TEST AUGMENTATION DE GRADE ---" << RESET << std::endl;
	try
	{
		while (true)
		{
			bureaucrat.incrGrade();
			std::cout << GREY << bureaucrat << RESET << std::endl;
		}
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	// Test de diminution du grade
	std::cout << GREEN << "\n--- TEST DIMINUTION DE GRADE ---" << RESET << std::endl;
	try
	{
		while (true)
		{
			bureaucrat.decrGrade();
			std::cout << GREY << bureaucrat << RESET << std::endl;
		}
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	// Test des constructeurs et affectations
	std::cout << GREEN << "\n--- TEST DES CONSTRUCTEURS ET AFFECTATIONS ---" << RESET << std::endl;
	Bureaucrat test1 = bureaucrat;
	std::cout << BLUE << "test1 est nommé : " << test1.getName() << " comme notre bureaucrat : " << bureaucrat.getName() << RESET << std::endl;
	std::cout << BLUE << "test1 a un grade : " << test1.getGrade() << " comme notre bureaucrat : " << bureaucrat.getGrade() << RESET << std::endl;

	Bureaucrat test2(bureaucrat);
	std::cout << BLUE << "test2 est nommé : " << test2.getName() << " comme notre bureaucrat : " << bureaucrat.getName() << RESET << std::endl;
	std::cout << BLUE << "test2 a un grade : " << test2.getGrade() << " comme notre bureaucrat : " << bureaucrat.getGrade() << RESET << std::endl;

	// Création d'un bureaucrat avec un grade élevé pour les tests
	Bureaucrat boss("Boss", 1);
	std::cout << BLUE << "Bureaucrat boss créé avec grade : " << boss.getGrade() << RESET << std::endl;

	// Initialisation du générateur de nombres aléatoires pour RobotomyRequestForm
	std::srand(std::time(nullptr));

	// --- TEST DES FORMULAIRES SPÉCIFIQUES ---
	std::cout << GREEN << "\n=== TEST DES FORMULAIRES SPÉCIFIQUES ===" << RESET << std::endl;

	// Test ShrubberyCreationForm
	std::cout << GREEN << "\n--- TEST SHRUBBERY CREATION FORM ---" << RESET << std::endl;
	ShrubberyCreationForm shrubForm("jardin");
	std::cout << BLUE << "Formulaire créé : " << shrubForm.getName() << " - Grade signature : " <<
		shrubForm.getRSign() << " - Grade exécution : " << shrubForm.getRExec() << RESET << std::endl;

	// Tentative de signature
	std::cout << BLUE << "Tentative de signature par " << bureaucrat.getName() << " :" << RESET << std::endl;
	bureaucrat.signForm(shrubForm);

	// Tentative d'exécution
	std::cout << BLUE << "Tentative d'exécution par " << bureaucrat.getName() << " :" << RESET << std::endl;
	bureaucrat.executeForm(shrubForm);

	// Tentative d'exécution par le boss
	std::cout << BLUE << "Tentative d'exécution par " << boss.getName() << " :" << RESET << std::endl;
	boss.executeForm(shrubForm);

	// Test RobotomyRequestForm
	std::cout << GREEN << "\n--- TEST ROBOTOMY REQUEST FORM ---" << RESET << std::endl;
	RobotomyRequestForm robotForm("Candidat");
	std::cout << BLUE << "Formulaire créé : " << robotForm.getName() << " - Grade signature : " <<
		robotForm.getRSign() << " - Grade exécution : " << robotForm.getRExec() << RESET << std::endl;

	// Signature et exécution avec le boss
	std::cout << BLUE << "Signature et exécution par " << boss.getName() << " :" << RESET << std::endl;
	boss.signForm(robotForm);
	boss.executeForm(robotForm);

	// Test PresidentialPardonForm
	std::cout << GREEN << "\n--- TEST PRESIDENTIAL PARDON FORM ---" << RESET << std::endl;
	PresidentialPardonForm pardonForm("Criminel");
	std::cout << BLUE << "Formulaire créé : " << pardonForm.getName() << " - Grade signature : " <<
		pardonForm.getRSign() << " - Grade exécution : " << pardonForm.getRExec() << RESET << std::endl;

	// Signature et exécution avec le boss
	std::cout << BLUE << "Signature et exécution par " << boss.getName() << " :" << RESET << std::endl;
	boss.signForm(pardonForm);
	boss.executeForm(pardonForm);

	// Test d'exécution sans signature préalable
	std::cout << GREEN << "\n--- TEST D'EXÉCUTION SANS SIGNATURE ---" << RESET << std::endl;
	PresidentialPardonForm nonSignedForm("Innocent");
	std::cout << BLUE << "Tentative d'exécution sans signature préalable :" << RESET << std::endl;
	boss.executeForm(nonSignedForm);
}

int main()
{
	std::cout << GREEN << "\n****************************************************" << RESET << std::endl;
	std::cout << GREEN << "* TEST AVEC UN BUREAUCRATE DE GRADE 1 (MAXIMUM)   *" << RESET << std::endl;
	std::cout << GREEN << "****************************************************\n" << RESET << std::endl;
	Bureaucrat anonyme;
	tester(anonyme);

	std::cout << GREEN << "\n****************************************************" << RESET << std::endl;
	std::cout << GREEN << "* TEST AVEC UN BUREAUCRATE DE GRADE MOYEN (75)     *" << RESET << std::endl;
	std::cout << GREEN << "****************************************************\n" << RESET << std::endl;
	Bureaucrat jul("julien", 75);
	tester(jul);

	std::cout << GREEN << "\n****************************************************" << RESET << std::endl;
	std::cout << GREEN << "* TEST AVEC UN BUREAUCRATE DE GRADE BAS (150)      *" << RESET << std::endl;
	std::cout << GREEN << "****************************************************\n" << RESET << std::endl;
	Bureaucrat novice("novice", 150);
	tester(novice);

	return 0;
}
