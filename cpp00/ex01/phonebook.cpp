/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:04:14 by mhenin            #+#    #+#             */
/*   Updated: 2025/03/27 15:26:45 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"

int	main(void)
{
	std::string	answer;
	Phonebook	Phonebook;

	while (true)
	{
		std::cout << GREEN << "ENTER A COMMAND (ADD/SEARCH/EXIT):";
		std::getline(std::cin, answer);
		std::cout << RESET;
		if (std::cin.eof())
			return (1);
		if (answer == "EXIT")
			return (0);
		else if (answer == "ADD")
			Phonebook.AddElement();
		else if (answer == "SEARCH")
			Phonebook.SearchElement();
	}
}