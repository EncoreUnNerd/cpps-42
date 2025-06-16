/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:07:39 by mhenin            #+#    #+#             */
/*   Updated: 2025/04/07 15:09:22 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << std::endl << "=== Tests supplémentaires ===" << std::endl;
	
	Fixed zero;
	Fixed small(0.00390625f);
	Fixed neg(-123.456f);
	Fixed large(8388607.0f);
	
	std::cout << "zero: " << zero << ", toInt(): " << zero.toInt() << std::endl;
	std::cout << "small (1/256): " << small << ", toInt(): " << small.toInt() << std::endl;
	std::cout << "negative: " << neg << ", toInt(): " << neg.toInt() << std::endl;
	std::cout << "large: " << large << ", toInt(): " << large.toInt() << std::endl;
	
	Fixed f1(1.0f);
	Fixed f2(1.25f);
	Fixed f3(1.33f);
	Fixed f4(1.5f);
	Fixed f5(1.75f);
	Fixed f6(1.9999f);
	
	std::cout << std::endl << "Test de précision:" << std::endl;
	std::cout << "1.0f = " << f1 << std::endl;
	std::cout << "1.25f = " << f2 << std::endl;
	std::cout << "1.33f = " << f3 << std::endl;
	std::cout << "1.5f = " << f4 << std::endl;
	std::cout << "1.75f = " << f5 << std::endl;
	std::cout << "1.9999f = " << f6 << std::endl;
	
	Fixed x, y, z;
	x = y = z = Fixed(42);
	std::cout << std::endl << "Assignation en chaîne:" << std::endl;
	std::cout << "x = y = z = Fixed(42)" << std::endl;
	std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;

	return 0;
}