/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:01:22 by mhenin            #+#    #+#             */
/*   Updated: 2025/04/07 15:46:36 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ClapTrap
{
	protected:
		std::string	_name;
		int			_hit_points;
		int			_energy_points;
		int			_attack_damage;
		
	public:
		void		attack(const std::string& target);
		void 		takeDamage(unsigned int amount);
		void 		beRepaired(unsigned int amount);
		ClapTrap	&operator=(const ClapTrap &claptrap);

		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &to_copy);
		~ClapTrap(void);
};