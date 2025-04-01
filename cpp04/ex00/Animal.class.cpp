/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:25:51 by mhenin            #+#    #+#             */
/*   Updated: 2025/04/01 18:01:21 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.class.hpp"

void Animal::makeSound() const
{
	std::cout << "An animal sound" << std::endl;
}

std::string Animal::getType(void) const
{
	return type;
}

Animal::Animal()
{
	type = "Animal";
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &animal)
{
	std::cout << "Copy assignment operator called" << std::endl;
	*this = animal;
	return (*this);
}

Animal::Animal(const Animal &to_copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}
