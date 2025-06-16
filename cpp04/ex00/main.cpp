/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:35:33 by mhenin            #+#    #+#             */
/*   Updated: 2025/04/09 16:06:36 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.class.hpp"
#include "Cat.class.hpp"
#include "WrongCat.class.hpp"

void runOriginalTests()
{
	std::cout << "\n=== Tests originaux ===" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* k = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	k->makeSound();
	meta->makeSound();

	delete i;
	delete j;
	delete meta;
	delete k;
}

void runAdditionalTests()
{
	std::cout << "\n=== Tests supplémentaires ===" << std::endl;
	
	// Test sur les constructeurs normaux et par copie
	std::cout << "\n--- Test des constructeurs ---" << std::endl;
	Animal animalBase;
	Animal animalCopy(animalBase);
	
	Dog dog1;
	Dog dog2(dog1);
	
	Cat cat1;
	Cat cat2(cat1);
	
	// Test des opérateurs d'affectation
	std::cout << "\n--- Test des opérateurs d'affectation ---" << std::endl;
	Animal animalAssigned;
	animalAssigned = animalBase;
	
	Dog dogAssigned;
	dogAssigned = dog1;
	
	Cat catAssigned;
	catAssigned = cat1;
	
	// Test des fonctions getType et makeSound sur les objets stack
	std::cout << "\n--- Test des objets stack ---" << std::endl;
	std::cout << "Animal Type: " << animalBase.getType() << std::endl;
	std::cout << "Dog Type: " << dog1.getType() << std::endl;
	std::cout << "Cat Type: " << cat1.getType() << std::endl;
	
	std::cout << "Animal Sound: ";
	animalBase.makeSound();
	std::cout << "Dog Sound: ";
	dog1.makeSound();
	std::cout << "Cat Sound: ";
	cat1.makeSound();
	
	// Test avec WrongAnimal et WrongCat
	std::cout << "\n--- Test des classes Wrong ---" << std::endl;
	WrongAnimal wrongAnimal;
	WrongCat wrongCat;
	
	std::cout << "WrongAnimal Type: " << wrongAnimal.getType() << std::endl;
	std::cout << "WrongCat Type: " << wrongCat.getType() << std::endl;
	
	std::cout << "WrongAnimal Sound: ";
	wrongAnimal.makeSound();
	std::cout << "WrongCat Sound: ";
	wrongCat.makeSound();
	
	// Test avec polymorphisme
	std::cout << "\n--- Test du polymorphisme ---" << std::endl;
	Animal* animals[4];
	animals[0] = new Animal();
	animals[1] = new Dog();
	animals[2] = new Cat();
	animals[3] = new Dog();
	
	for (int i = 0; i < 4; i++) {
		std::cout << "Animal " << i << " Type: " << animals[i]->getType() << std::endl;
		std::cout << "Animal " << i << " Sound: ";
		animals[i]->makeSound();
	}
	
	for (int i = 0; i < 4; i++) {
		delete animals[i];
	}
}

int	main()
{
	// Exécution des tests originaux
	runOriginalTests();
	
	// Exécution des tests supplémentaires
	runAdditionalTests();
	
	return 0;
}