/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:35:30 by mhenin            #+#    #+#             */
/*   Updated: 2025/03/25 17:56:30 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "Addres string    : " << &string << std::endl;
	std::cout << "Addres stringPTR : " << &stringPTR << std::endl;
	std::cout << "Addres stringREF : " << &stringREF << std::endl;

	std::cout << "Value string    : " << string << std::endl;
	std::cout << "Value stringPTR : " << stringPTR << std::endl;
	std::cout << "Value stringREF : " << stringREF << std::endl;
}