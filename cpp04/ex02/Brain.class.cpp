/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:53:32 by mhenin            #+#    #+#             */
/*   Updated: 2025/04/02 17:11:53 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.class.hpp"

Brain &Brain::operator=(const Brain &brain)
{
	std::cout << "Copy assignment operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
	return (*this);
}

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &to_copy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = to_copy;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}
