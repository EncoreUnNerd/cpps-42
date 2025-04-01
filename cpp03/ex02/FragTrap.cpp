/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:17:46 by mhenin            #+#    #+#             */
/*   Updated: 2025/04/01 15:23:07 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << getName() << " send a positive high-five request" << std::endl;
}

FragTrap::FragTrap(std::string name): ScavTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "FragTrap " << name << " has been assembled!" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << getName() << " has been disassembled!" << std::endl;
}
