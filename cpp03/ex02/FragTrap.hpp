/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:32:52 by mhenin            #+#    #+#             */
/*   Updated: 2025/04/07 16:01:32 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		void 		highFivesGuys(void);
		void		attack(const std::string &target);
		FragTrap	&operator=(const FragTrap &fragtrap);
		
		FragTrap(std::string name);
		FragTrap(const FragTrap &to_copy);
		~FragTrap(void);
};