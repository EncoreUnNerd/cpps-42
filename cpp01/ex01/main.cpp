/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:24:39 by mhenin            #+#    #+#             */
/*   Updated: 2025/03/25 17:29:37 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	int n = 8;
	Zombie *horde = zombieHorde(n, "TOM");
	for (int i = 0; i < n; i++)
		horde[i].announce();
	delete[] horde;
}