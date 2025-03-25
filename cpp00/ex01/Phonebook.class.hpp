/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:04:09 by mhenin            #+#    #+#             */
/*   Updated: 2025/03/25 14:56:09 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include <iostream>
#include "Contact.class.hpp" 

// ANSI color codes
#define BLUE "\033[34m"
#define GRAY "\033[90m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

class Phonebook
{
	private:
		int		_index;
		Contact	_book[8];
	public:
		void	AddElement(void);
		void	SearchElement(void);
		Phonebook(void);
};

#endif