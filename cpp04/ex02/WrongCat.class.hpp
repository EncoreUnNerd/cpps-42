/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:25:35 by mhenin            #+#    #+#             */
/*   Updated: 2025/04/01 18:04:36 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.class.hpp"

class WrongCat: public WrongAnimal
{
	public:
		void	makeSound() const;
		WrongCat	&operator=(const WrongCat &wrongcat);
		
		WrongCat(void);
		WrongCat(const WrongCat &to_copy);
		~WrongCat(void);
};