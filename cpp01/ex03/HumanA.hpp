/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:38:40 by mhenin            #+#    #+#             */
/*   Updated: 2025/03/26 15:02:58 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
	private:
		Weapon		&weapon;
		std::string	name;

	public:
		HumanA(std::string name,Weapon &base_weapon);
		
		void	attack(void);
}; 

#endif