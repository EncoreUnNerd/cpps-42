/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:32:52 by mhenin            #+#    #+#             */
/*   Updated: 2025/04/01 17:55:59 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ScavTrap.hpp"

class FragTrap: public ScavTrap
{
	public:
		void 		highFivesGuys(void);
		FragTrap	&operator=(const FragTrap &fragtrap);
		
		FragTrap(std::string name);
		FragTrap(const FragTrap &to_copy);
		~FragTrap(void);
};