/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:08:57 by mhenin            #+#    #+#             */
/*   Updated: 2025/04/07 15:12:34 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	
	std::cout << "=== Tests supplémentaires ===" << std::endl;
	
	Fixed d;
	std::cout << "d initial: " << d.getRawBits() << std::endl;
	d.setRawBits(42);
	std::cout << "d après setRawBits(42): " << d.getRawBits() << std::endl;
	
	Fixed e, f, g;
	std::cout << "e, f, g initiaux: " << e.getRawBits() << ", " 
			<< f.getRawBits() << ", " << g.getRawBits() << std::endl;
	g = f = e = d;
	std::cout << "Après g = f = e = d: " << std::endl;
	std::cout << "d: " << d.getRawBits() << ", e: " << e.getRawBits() 
			<< ", f: " << f.getRawBits() << ", g: " << g.getRawBits() << std::endl;
	
	Fixed h;
	h.setRawBits(100);
	Fixed i(h);
	std::cout << "h: " << h.getRawBits() << ", i (copie de h): " << i.getRawBits() << std::endl;
	h.setRawBits(200);
	std::cout << "Après modification de h: " << std::endl;
	std::cout << "h: " << h.getRawBits() << ", i: " << i.getRawBits() << std::endl;
	
	return 0;
}