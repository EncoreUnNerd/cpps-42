/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:20:19 by mhenin            #+#    #+#             */
/*   Updated: 2025/03/31 17:23:43 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	claptrap("robloc_man");

	for (int i = 0; i < 11; i++)
		claptrap.attack("random");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);
	claptrap.takeDamage(10);
}