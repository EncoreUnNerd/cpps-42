#include "ClapTrap.hpp"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:01:27 by mhenin            #+#    #+#             */
/*   Updated: 2025/03/31 17:01:29 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


ClapTrap::ClapTrap(std::string name): _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap " << name << " has been assembled!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " has been destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (_energy_points > 0)
	{
		_energy_points--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing ";
		std::cout << _attack_damage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " can't attack he has no energy points left!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	_hit_points -= amount;
	if (_hit_points > 0)
		std::cout << "ClapTrap " << _name << " as taken " << amount << " damage!" << std::endl;
	else
		std::cout << "ClapTrap " << _name << " as taken " << amount << " damage and hes dead!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy_points > 0)
	{
		_energy_points--;
		_hit_points += amount;
		std::cout << "ClapTrap " << _name << " as repaired " << amount << " hit points!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " can't repaire he has no energy points left!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap)
{
	std::cout << "Copy assignment operator called" << std::endl;
	*this = claptrap;
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap &to_copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}