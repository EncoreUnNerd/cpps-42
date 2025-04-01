/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:42:54 by mhenin            #+#    #+#             */
/*   Updated: 2025/03/31 15:46:26 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &to_copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}

Fixed::Fixed(): _number(0)
{
	std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed(const int to_convert)
{
	std::cout << "Int constructor called" << std::endl;
	_number = to_convert << 8;
}

Fixed::Fixed(const float to_convert): _number(roundf(to_convert * 256))
{
	std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
	return ((float)_number / 256);
}

int Fixed::toInt(void) const
{
	return (_number >> 8);
}

int Fixed::getRawBits(void) const
{
	return (_number);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_number = raw;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->_number = fixed.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}

