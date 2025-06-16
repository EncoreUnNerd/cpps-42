/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:20:19 by mhenin            #+#    #+#             */
/*   Updated: 2025/04/07 16:01:58 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
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

	std::cout << std::endl;

	FragTrap	fragtrap("Frag robloc_man");
	for (int i = 0; i < 11; i++)
		fragtrap.attack("random");
	fragtrap.takeDamage(20);
	fragtrap.beRepaired(10);
	fragtrap.highFivesGuys();
	fragtrap.takeDamage(1000);
}