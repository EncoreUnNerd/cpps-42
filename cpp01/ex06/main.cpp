/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:52:27 by mhenin            #+#    #+#             */
/*   Updated: 2025/03/27 17:09:05 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl harl;

	if (ac != 2)
	{
		std::cerr << "Invalid number of arg" << std::endl;
		return (1);
	}
	std::string	value(av[1]);
	harl.complain(value);
}