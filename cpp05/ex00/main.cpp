/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:09:22 by mhenin            #+#    #+#             */
/*   Updated: 2025/05/19 18:09:25 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

void tester(Bureaucrat bureaucrat)
{
	std::cout << GREEN << "starting test for " << bureaucrat.getName() << ". Who as a grade of " << bureaucrat.getGrade() << RESET << std::endl;

	try
	{
		while (true)
		{
			bureaucrat.incrGrade();
			std::cout << GREY << bureaucrat << RESET << std::endl;
		}
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	try
	{
		while (true)
		{
			bureaucrat.decrGrade();
			std::cout << GREY << bureaucrat << RESET << std::endl;
		}
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	Bureaucrat test1 = bureaucrat;
	std::cout << BLUE << "test1 is named : " << test1.getName() << " like our bureaucrat : " << bureaucrat.getName() << RESET << std::endl;
	std::cout << BLUE << "test1 is graded : " << test1.getGrade() << " like our bureaucrat : " << bureaucrat.getGrade() << RESET << std::endl;

	Bureaucrat test2(bureaucrat);
	std::cout << BLUE << "test2 is named : " << test2.getName() << " like our bureaucrat : " << bureaucrat.getName() << RESET << std::endl;
	std::cout << BLUE << "test2 is graded : " << test2.getGrade() << " like our bureaucrat : " << bureaucrat.getGrade() << RESET << std::endl;
}

int main()
{
	Bureaucrat anonyme;
	tester(anonyme);

	Bureaucrat jul("julien", 12);
	tester(jul);
}
