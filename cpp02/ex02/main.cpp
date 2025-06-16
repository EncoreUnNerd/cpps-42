/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:07:39 by mhenin            #+#    #+#             */
/*   Updated: 2025/04/07 14:57:48 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) 
{
	// Tests originaux
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "=== Tests originaux ===" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	
	// Tests supplémentaires
	std::cout << std::endl << "=== Tests des opérateurs arithmétiques ===" << std::endl;
	Fixed c(42.42f);
	Fixed d(10);
	
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "c + d = " << c + d << std::endl;
	std::cout << "c - d = " << c - d << std::endl;
	std::cout << "c * d = " << c * d << std::endl;
	std::cout << "c / d = " << c / d << std::endl;
	
	std::cout << std::endl << "=== Tests des opérateurs de comparaison ===" << std::endl;
	std::cout << "c > d: " << (c > d) << std::endl;
	std::cout << "c < d: " << (c < d) << std::endl;
	std::cout << "c >= d: " << (c >= d) << std::endl;
	std::cout << "c <= d: " << (c <= d) << std::endl;
	std::cout << "c == d: " << (c == d) << std::endl;
	std::cout << "c != d: " << (c != d) << std::endl;
	
	std::cout << std::endl << "=== Tests des opérateurs de décrémentation ===" << std::endl;
	Fixed e(5);
	std::cout << "e = " << e << std::endl;
	std::cout << "--e = " << --e << std::endl;
	std::cout << "e = " << e << std::endl;
	std::cout << "e-- = " << e-- << std::endl;
	std::cout << "e = " << e << std::endl;
	
	std::cout << std::endl << "=== Tests des fonctions min/max ===" << std::endl;
	Fixed f(3.14f);
	Fixed g(2.71f);
	std::cout << "f = " << f << ", g = " << g << std::endl;
	std::cout << "min(f, g) = " << Fixed::min(f, g) << std::endl;
	std::cout << "max(f, g) = " << Fixed::max(f, g) << std::endl;
	
	const Fixed h(123.456f);
	const Fixed i(123.456f);
	std::cout << "h = " << h << ", i = " << i << std::endl;
	std::cout << "min(h, i) = " << Fixed::min(h, i) << std::endl;
	std::cout << "max(h, i) = " << Fixed::max(h, i) << std::endl;
	
	return 0;
}