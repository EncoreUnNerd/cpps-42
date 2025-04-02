/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:33:37 by mhenin            #+#    #+#             */
/*   Updated: 2025/04/02 17:13:34 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.class.hpp"

void WrongCat::makeSound() const
{
	std::cout << "wrong MEOW MEOW 🐈🔥" << std::endl;
}

WrongCat::WrongCat(void): WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongcat)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->type = wrongcat.type;
	return (*this);
}

WrongCat::WrongCat(const WrongCat &to_copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}