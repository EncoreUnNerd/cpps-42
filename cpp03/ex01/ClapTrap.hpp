/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:01:22 by mhenin            #+#    #+#             */
/*   Updated: 2025/04/02 16:59:20 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ClapTrap
{
	private:
		std::string	_name;
		int			_hit_points;
		int			_energy_points;
		int			_attack_damage;

	protected:
		void		setHitPoints(int value);
		void		setEnergyPoints(int value);
		void		setAttackDamage(int value);
		void		setName(std::string name);

		int			getHitPoints(void) const;
		int			getEnergyPoints(void) const;
		int			getAttackDamage(void) const;
		std::string	getName(void) const;
		
	public:
		void		attack(const std::string& target);
		void 		takeDamage(unsigned int amount);
		void 		beRepaired(unsigned int amount);
		ClapTrap	&operator=(const ClapTrap &claptrap);

		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &to_copy);
		~ClapTrap(void);
};