/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:00:35 by mhenin            #+#    #+#             */
/*   Updated: 2025/04/01 18:00:23 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal
{
	protected:
		std::string type;

	public:
		virtual void	makeSound(void) const;
		std::string		getType(void) const;
		Animal			&operator=(const Animal &animal);
		
		
		Animal(void);
		Animal(const Animal &to_copy);
		virtual ~Animal(void);
};