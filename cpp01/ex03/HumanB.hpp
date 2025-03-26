/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:38:40 by mhenin            #+#    #+#             */
/*   Updated: 2025/03/26 14:58:08 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
	private:
		Weapon		weapon;
		std::string	name;
	public:
		void	attack(void);
		void	setWeapon(Weapon new_weapon);
}; 

#endif