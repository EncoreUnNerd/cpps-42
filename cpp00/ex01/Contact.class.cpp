/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:03:59 by mhenin            #+#    #+#             */
/*   Updated: 2025/03/25 14:04:01 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Phonebook.class.hpp"
#include "Contact.class.hpp"

std::string Contact::GetFirstName(void)
{
	return (first_name);
}

std::string Contact::GetLastName(void)
{
	return (last_name);
}

std::string Contact::GetNickname(void)
{
	return (nickname);
}

std::string Contact::GetPhoneNumber(void)
{
	return (phone_number);
}

std::string Contact::GetDarkestSecret(void)
{
	return (darkest_secret);
}

void Contact::AskEntry(std::string message, std::string &field)
{
	while (field.empty())
	{
		std::cout << BLUE << message;
		std::getline(std::cin, field);
		std::cout << RESET;
		if (std::cin.eof())
			return;
		if (field.empty())
			std::cout << "Value can not be empty." << std::endl;
	}
}


void Contact::ShowValues(void)
{
	std::cout << this->first_name << std::endl;
	std::cout << this->last_name << std::endl;
	std::cout << this->nickname << std::endl;
	std::cout << this->phone_number << std::endl;
	std::cout << this->darkest_secret << std::endl;
}

void Contact::EnterValues(void)
{
	Contact::AskEntry("First Name :", this->first_name);
	Contact::AskEntry("Last Name :", this->last_name);
	Contact::AskEntry("Nickname :", this->nickname);
	Contact::AskEntry("Phone Number :", this->phone_number);
	Contact::AskEntry("Darkest Secret :", this->darkest_secret);
}
