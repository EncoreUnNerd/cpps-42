#include "Fixed.hpp"
#include <iostream>

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

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _number;
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
