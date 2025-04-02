/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:17:46 by mhenin            #+#    #+#             */
/*   Updated: 2025/04/02 17:04:21 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << getName() << " send a positive high-five request" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragtrap)
{
	std::cout << "Copy assignment operator called" << std::endl;
	setHitPoints(fragtrap.getHitPoints());
	setEnergyPoints(fragtrap.getEnergyPoints());
	setAttackDamage(fragtrap.getAttackDamage());
	setName(fragtrap.getName());
	return (*this);
}

FragTrap::FragTrap(std::string name): ScavTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "FragTrap " << name << " has been assembled!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &to_copy): ScavTrap(to_copy.getName())
{
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << getName() << " has been disassembled!" << std::endl;
}
