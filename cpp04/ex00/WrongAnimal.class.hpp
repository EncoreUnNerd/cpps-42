/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:00:35 by mhenin            #+#    #+#             */
/*   Updated: 2025/04/08 14:55:23 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;

	public:
		void	makeSound(void) const;
		std::string		getType(void) const;
		WrongAnimal	&operator=(const WrongAnimal &wronganimal);


		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &to_copy);
		virtual ~WrongAnimal(void);
};
