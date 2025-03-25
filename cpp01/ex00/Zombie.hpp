/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:27:33 by mhenin            #+#    #+#             */
/*   Updated: 2025/03/25 16:53:39 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

// ANSI color codes
#define BLUE "\033[34m"
#define GRAY "\033[90m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

class Zombie
{
	private:
		std::string	name;
	public:
		void	announce(void);
		Zombie(std::string name);
		~Zombie(void);
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif