/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:35:33 by mhenin            #+#    #+#             */
/*   Updated: 2025/04/02 16:40:41 by mhenin           ###   ########.fr       */
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

	// Animal *test = new Animal[100];
	
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	delete j;
	delete i;

	return 0;
}