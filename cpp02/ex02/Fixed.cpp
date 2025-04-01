/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:42:54 by mhenin            #+#    #+#             */
/*   Updated: 2025/03/31 16:53:25 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &to_copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}

Fixed::Fixed(): _number(0)
{
	// std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed(const int to_convert)
{
	// std::cout << "Int constructor called" << std::endl;
	_number = to_convert << 8;
}

Fixed::Fixed(const float to_convert): _number(roundf(to_convert * 256))
{
	// std::cout << "Float constructor called" << std::endl;
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
	// std::cout << "setRawBits member function called" << std::endl;
	_number = raw;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->_number = fixed.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}

bool	Fixed::operator!=(const Fixed &fixed)
{
	return (this->getRawBits() != fixed.getRawBits());
}

bool	Fixed::operator<=(const Fixed &fixed)
{
	return (this->getRawBits() <= fixed.getRawBits());
}

bool	Fixed::operator>=(const Fixed &fixed)
{
	return (this->getRawBits() >= fixed.getRawBits());
}

bool	Fixed::operator==(const Fixed &fixed)
{
	return (this->getRawBits() == fixed.getRawBits());
}

bool	Fixed::operator<(const Fixed &fixed)
{
	return (this->getRawBits() < fixed.getRawBits());
}


bool	Fixed::operator>(const Fixed &fixed)
{
	return (this->getRawBits() > fixed.getRawBits());
}

Fixed Fixed::operator*(const Fixed &fixed)
{
	return (this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed)
{
	return (this->toFloat() / fixed.toFloat());
}


Fixed Fixed::operator+(const Fixed &fixed)
{
	return (this->getRawBits() + fixed.getRawBits());
}

Fixed Fixed::operator-(const Fixed &fixed)
{
	return (this->getRawBits() - fixed.getRawBits());
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++(*this);
	return temp;
}

Fixed &Fixed::operator++()
{
	this->_number++;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--(*this);
	return temp;
}

Fixed &Fixed::operator--()
{
	this->_number--;
	return *this;
}

Fixed Fixed::min(Fixed &compare1, Fixed &compare2)
{
	if (compare1 > compare2)
		return (compare2);
	else
		return (compare1);
}

Fixed Fixed::min(const Fixed &compare1, const Fixed &compare2)
{
	if (compare1.getRawBits() > compare2.getRawBits())
		return (compare2);
	else
		return (compare1);
}

Fixed Fixed::max(Fixed &compare1, Fixed &compare2)
{
	if (compare1 < compare2)
		return (compare2);
	else
		return (compare1);
}

Fixed Fixed::max(const Fixed &compare1, const Fixed &compare2)
{
	if (compare1.getRawBits() < compare2.getRawBits())
		return (compare2);
	else
		return (compare1);
}
