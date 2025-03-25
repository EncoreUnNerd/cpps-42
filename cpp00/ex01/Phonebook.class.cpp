/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:04:05 by mhenin            #+#    #+#             */
/*   Updated: 2025/03/25 18:12:20 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"
#include <sstream>

void Phonebook::AddElement(void)
{
	_book[_index] = Contact();
	_book[_index].EnterValues();
	_index++;
	if (_index >= 8)
		_index = 0;
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
	unsigned int		i;
	unsigned int		aindex;

	std::cout << BLUE << "|     index|First Name| Last Name|  Nickname|" RESET << std::endl;
	for (i = 0; i < 8; i++)
	{
		if (_book[i].GetFirstName().size() == 0)
			break;
		std::cout << "|";
		ss.str("");
		ss << i;
		DisplayTmp(ss.str());
		DisplayTmp(_book[i].GetFirstName());
		DisplayTmp(_book[i].GetLastName());
		DisplayTmp(_book[i].GetNickname());
		std::cout << std::endl;
	}
	std::cout << GREEN << "ENTER CONTACT INDEX:";
	std::getline(std::cin, answer);
	std::cout << RESET;
	if (std::istringstream(answer) >> aindex)
	{
		if (aindex < i)
			_book[aindex].ShowValues();
		else
			std::cout << RED << "INVALID INDEX" << RESET << std::endl;
	}
	else
		std::cout << RED << "INVALID INDEX" << RESET << std::endl;
}

Phonebook::Phonebook(void): _index(0)
{
	return;
}
