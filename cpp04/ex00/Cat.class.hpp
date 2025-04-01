/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:25:35 by mhenin            #+#    #+#             */
/*   Updated: 2025/04/01 18:01:54 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.class.hpp"

class Cat: public Animal
{
	public:
		void	makeSound() const;
		Cat	&operator=(const Cat &cat);

		Cat(void);
		Cat(const Cat &to_copy);
		~Cat(void);
};