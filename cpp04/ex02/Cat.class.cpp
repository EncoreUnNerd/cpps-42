/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:33:37 by mhenin            #+#    #+#             */
/*   Updated: 2025/04/02 17:50:35 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.class.hpp"

void Cat::makeSound() const
{
	std::cout << "MEOW MEOW 🐈🔥" << std::endl;
}

Cat::Cat(void): Animal()
{
	_brain = new Brain();
	this->type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->type = cat.type;
	delete this->_brain;
	this->_brain = new Brain();
	*_brain = *(cat._brain);
	return (*this);
}

Cat::Cat(const Cat &to_copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}