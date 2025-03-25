/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:04:05 by mhenin            #+#    #+#             */
/*   Updated: 2025/03/25 14:33:28 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"
#include <sstream>

void Phonebook::AddElement(void)
{
	book[index] = Contact();
	book[index].EnterValues();
	index++;
	if (index >= 8)
		index = 0;
}

static void DisplayTmp(std::string tmp)
{
	int	len;
	if (tmp.size() > 10)
	{
		tmp = tmp.substr(0, 9);
		std::cout << tmp << ".|";
	}
	else
	{
		len = 10 - tmp.size();
		while (len > 0)
		{
			std::cout << " ";
			len--;
		}
		std::cout << tmp;
		std::cout << "|";
	}
}

void Phonebook::SearchElement(void)
{
	std::stringstream	ss;
	std::string			answer;
	int					i;
	int					aindex;

	std::cout << BLUE << "|     index|First Name| Last Name|  Nickname|" RESET << std::endl;
	for (i = 0; i < 8; i++)
	{
		if (book[i].GetFirstName().size() == 0)
			break;
		std::cout << "|";
		ss.str("");
		ss << i;
		DisplayTmp(ss.str());
		DisplayTmp(book[i].GetFirstName());
		DisplayTmp(book[i].GetLastName());
		DisplayTmp(book[i].GetNickname());
		std::cout << std::endl;
	}
	std::cout << GREEN << "ENTER CONTACT INDEX:";
	std::getline(std::cin, answer);
	std::cout << RESET;
	if (std::istringstream(answer) >> aindex)
	{
		if (aindex < i)
			book[aindex].ShowValues();
		else
			std::cout << RED << "INVALID INDEX" << RESET << std::endl;
	}
	else
		std::cout << RED << "INVALID INDEX" << RESET << std::endl;
}

Phonebook::Phonebook(void): index(0)
{
	return;
}
