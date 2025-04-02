/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:32:52 by mhenin            #+#    #+#             */
/*   Updated: 2025/04/02 16:57:26 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		void 		guardGate(void);
		ScavTrap	&operator=(const ScavTrap &scavtrap);
		
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &to_copy);
		~ScavTrap(void);
};