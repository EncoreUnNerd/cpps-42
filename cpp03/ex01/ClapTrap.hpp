/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:01:22 by mhenin            #+#    #+#             */
/*   Updated: 2025/04/01 15:03:09 by mhenin           ###   ########.fr       */
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

		int			getHitPoints(void) const;
		int			getEnergyPoints(void) const;
		int			getAttackDamage(void) const;
		std::string	getName(void) const;
		
	public:
		void		attack(const std::string& target);
		void 		takeDamage(unsigned int amount);
		void 		beRepaired(unsigned int amount);

		ClapTrap(std::string name);
		~ClapTrap(void);
};