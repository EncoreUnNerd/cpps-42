/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:38:40 by mhenin            #+#    #+#             */
/*   Updated: 2025/03/26 14:49:03 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
	private:
		std::string	type;
	public:
		std::string const	&getType(void);
		void		setType(std::string new_type);
}; 

#endif