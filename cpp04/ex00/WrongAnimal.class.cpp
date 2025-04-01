/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:25:51 by mhenin            #+#    #+#             */
/*   Updated: 2025/04/01 18:03:40 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.class.hpp"

void WrongAnimal::makeSound() const
{
	std::cout << "A wrong animal sound" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return type;
}

WrongAnimal::WrongAnimal()
{
	type = "WrongAnimal";
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wronganimal)
{
	std::cout << "Copy assignment operator called" << std::endl;
	*this = wronganimal;
	return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal &to_copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}