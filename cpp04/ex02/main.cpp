/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:35:33 by mhenin            #+#    #+#             */
/*   Updated: 2025/04/03 14:55:51 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.class.hpp"
#include "Cat.class.hpp"
#include "WrongCat.class.hpp"

int	main()
{
	// const Animal* meta = new Animal();
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// const WrongAnimal* k = new WrongCat();

	// std::cout << j->getType() << " " << std::endl;
	// std::cout << i->getType() << " " << std::endl;
	// std::cout << k->getType() << " " << std::endl;
	// i->makeSound(); //will output the cat sound!
	// j->makeSound();
	// k->makeSound();
	// meta->makeSound();

	// delete i;
	// delete j;
	// delete meta;
	// delete k;

	// std::cout << std::endl;
	// Animal a;

	Animal *test[100];
	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
			test[i] = new Dog();
		else
			test[i] = new Cat();
	}
	for (int i = 0; i < 100; i++) 
		test[i]->makeSound();
	for (int i = 0; i < 100; i++) 
		delete test[i];
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	
	// delete j;
	// delete i;

	return 0;
}