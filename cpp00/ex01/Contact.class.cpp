/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:03:59 by mhenin            #+#    #+#             */
/*   Updated: 2025/03/25 14:58:38 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Phonebook.class.hpp"
#include "Contact.class.hpp"

std::string Contact::GetFirstName(void)
{
	return (_first_name);
}

std::string Contact::GetLastName(void)
{
	return (_last_name);
}

std::string Contact::GetNickname(void)
{
	return (_nickname);
}

std::string Contact::GetPhoneNumber(void)
{
	return (_phone_number);
}

std::string Contact::GetDarkestSecret(void)
{
	return (_darkest_secret);
}

void Contact::_AskEntry(std::string message, std::string &field)
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
	std::cout << this->_first_name << std::endl;
	std::cout << this->_last_name << std::endl;
	std::cout << this->_nickname << std::endl;
	std::cout << this->_phone_number << std::endl;
	std::cout << this->_darkest_secret << std::endl;
}

void Contact::EnterValues(void)
{
	Contact::_AskEntry("First Name :", this->_first_name);
	Contact::_AskEntry("Last Name :", this->_last_name);
	Contact::_AskEntry("Nickname :", this->_nickname);
	Contact::_AskEntry("Phone Number :", this->_phone_number);
	Contact::_AskEntry("Darkest Secret :", this->_darkest_secret);
}
