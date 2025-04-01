/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:33:46 by mhenin            #+#    #+#             */
/*   Updated: 2025/04/01 18:02:22 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.class.hpp"

void Dog::makeSound() const
{
	std::cout << "WOUF WOUF 🐕🔥" << std::endl;
}

Dog::Dog(void): Animal()
{
	this->type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
	std::cout << "Copy assignment operator called" << std::endl;
	*this = dog;
	return (*this);
}

Dog::Dog(const Dog &to_copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}