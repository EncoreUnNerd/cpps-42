/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:17:46 by mhenin            #+#    #+#             */
/*   Updated: 2025/04/07 16:02:15 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " send a positive high-five request" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragtrap)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_attack_damage = fragtrap._attack_damage;
	this->_energy_points = fragtrap._energy_points;
	this->_hit_points = fragtrap._hit_points;
	this->_name = fragtrap._name;
	return (*this);
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	std::cout << "FragTrap " << name << " has been assembled!" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (_energy_points > 0)
	{
		_energy_points--;
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing ";
		std::cout << _attack_damage << " points of damage!" << std::endl;
	}
	else
		std::cout << "FragTrap " << _name << " can't attack he has no energy points left!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &to_copy): ClapTrap(to_copy._name)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << _name << " has been disassembled!" << std::endl;
}
