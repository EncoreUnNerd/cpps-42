/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:20:19 by mhenin            #+#    #+#             */
/*   Updated: 2025/04/01 15:11:26 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap	claptrap("robloc_man");

	for (int i = 0; i < 11; i++)
		claptrap.attack("random");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);
	claptrap.takeDamage(10);
	
	std::cout << std::endl;

	ScavTrap	scavtrap("Scav robloc_man");
	for (int i = 0; i < 11; i++)
		scavtrap.attack("random");
	scavtrap.takeDamage(20);
	scavtrap.beRepaired(10);
	scavtrap.guardGate();
	scavtrap.takeDamage(1000);
}