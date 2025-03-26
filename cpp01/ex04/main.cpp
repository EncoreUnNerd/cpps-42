/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:19:56 by mhenin            #+#    #+#             */
/*   Updated: 2025/03/26 18:06:23 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

// main main roblox caca pipi main

int	main(int ac, char **av)
{
	std::string	line;
	size_t		pos = 0;
	std::string	to_replace;
	std::string	replacement;
	std::string output_filename;

	//? verif argument
	if (ac != 4)
	{
		std::cout << "Number of argument invalid" << std::endl;
		return (1);
	}

	//? open input file
	std::ifstream	input_file(av[1]);
	if (!input_file)
	{
		std::cerr << "Error opening the input file" << std::endl;
		return (1);
	}

	//? open or create output file
	output_filename = std::string(av[1]) + ".replace";
	std::ofstream output_file(output_filename.c_str());
	if (!output_file)
	{
		input_file.close();
		std::cerr << "Error opening or creating the output file" << std::endl;
		return (1);
	}

	to_replace = std::string(av[2]);
	replacement = std::string(av[3]);

	while (std::getline(input_file, line)) {
		while ((pos = line.find(to_replace)) != std::string::npos)
		{
			std::string	tmp;
			tmp = line.substr(0, pos);
			tmp += replacement;
			tmp += line.substr(pos + to_replace.length());
			line = tmp;
		}
		output_file << line << std::endl;
	}
	input_file.close();
	output_file.close();
}