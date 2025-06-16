/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:35:33 by mhenin            #+#    #+#             */
/*   Updated: 2025/04/09 16:17:05 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.class.hpp"
#include "Cat.class.hpp"

int	main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete i;
	delete j;
	delete meta;

	// std::cout << std::endl;

	// Animal *test[100];
	// for (int i = 0; i < 100; i++)
	// {
	// 	if (i % 2 == 0)
	// 		test[i] = new Dog();
	// 	else
	// 		test[i] = new Cat();
	// }
	// for (int i = 0; i < 100; i++) {
	// 	delete test[i];
	// }

	// Cat basic;
	// {
	// 	Cat tmp = basic;

	// 	// Dog tmp;
	// 	// tmp = basic;
	// }
	// basic.makeSound();

	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	
	// delete j;
	// delete i;

	return 0;
}