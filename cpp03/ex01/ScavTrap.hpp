/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:32:52 by mhenin            #+#    #+#             */
/*   Updated: 2025/04/07 15:54:18 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		void 		guardGate(void);
		void 		attack(const std::string &target);
		ScavTrap	&operator=(const ScavTrap &scavtrap);
		
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &to_copy);
		~ScavTrap(void);
};