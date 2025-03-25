/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:03:52 by mhenin            #+#    #+#             */
/*   Updated: 2025/03/25 14:56:32 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <iostream>

class Contact
{
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
		void 		_AskEntry(std::string message, std::string &field);
	public:
		std::string	GetFirstName(void);
		std::string	GetLastName(void);
		std::string	GetNickname(void);
		std::string	GetPhoneNumber(void);
		std::string	GetDarkestSecret(void);
		void		ShowValues(void);
		void		EnterValues(void);
};

#endif