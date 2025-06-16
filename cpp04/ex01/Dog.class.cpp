/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:33:46 by mhenin            #+#    #+#             */
/*   Updated: 2025/04/08 15:15:17 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.class.hpp"

void Dog::makeSound() const
{
	std::cout << "WOUF WOUF 🐕🔥" << std::endl;
}

Dog::Dog(void): Animal()
{
	_brain = new Brain();
	this->type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->type = dog.type;
	if (this->_brain)
		delete this->_brain;
	if (dog._brain)
		this->_brain = new Brain(*(dog._brain));
	else
		this->_brain = NULL;
	return (*this);
}

Dog::Dog(const Dog &to_copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_brain = NULL;
	*this = to_copy;
}