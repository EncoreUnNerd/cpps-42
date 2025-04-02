/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:25:35 by mhenin            #+#    #+#             */
/*   Updated: 2025/04/02 16:31:13 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Brain.class.hpp"
#include "Animal.class.hpp"

class Dog: public Animal
{
	private:
		Brain *_brain;
	public:
		void	makeSound() const;
		Dog	&operator=(const Dog &dog);
		
		Dog(void);
		Dog(const Dog &to_copy);
		~Dog(void);
};