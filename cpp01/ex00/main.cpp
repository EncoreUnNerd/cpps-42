/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:24:39 by mhenin            #+#    #+#             */
/*   Updated: 2025/03/25 16:54:36 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	std::cout << GRAY << "Random chump (Louis) :" << RESET << std::endl;
	randomChump("Louis");
	std::cout << GRAY << "Back into the code" << RESET << std::endl;
	std::cout << GRAY << "New zombie (Tom) :" << RESET << std::endl;
	Zombie *tom = newZombie("Tom");
	std::cout << GRAY << "Back into the code" << RESET << std::endl;
	std::cout << GRAY << "Zombie (Tom) announce :" << RESET << std::endl;
	tom->announce();
	std::cout << GRAY << "Destroying" << RESET << std::endl;
	delete tom;
	std::cout << GRAY << "Ended" << RESET << std::endl;
}