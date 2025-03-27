/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:52:27 by mhenin            #+#    #+#             */
/*   Updated: 2025/03/27 16:55:32 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl harl;

	std::cout << BLUE << "Asking debug" << RESET << std::endl;
	harl.complain("DEBUG");
	std::cout << BLUE << "Asking info" << RESET << std::endl;
	harl.complain("INFO");
	std::cout << BLUE << "Asking warning" << RESET << std::endl;
	harl.complain("WARNING");
	std::cout << BLUE << "Asking error" << RESET << std::endl;
	harl.complain("ERROR");
	std::cout << BLUE << "End" << RESET << std::endl;
}