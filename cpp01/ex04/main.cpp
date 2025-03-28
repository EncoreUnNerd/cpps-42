/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:19:56 by mhenin            #+#    #+#             */
/*   Updated: 2025/03/28 14:43:50 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

static int	replacement(std::ifstream &input_file, std::ofstream &output_file, char **av)
{
	size_t		pos = 0;
	size_t		spos = 0;
	std::string	line;
	std::string	to_replace;
	std::string	replacement;

	to_replace = std::string(av[2]);
	if (to_replace.empty())
	{
		std::cerr << "string to replace can not be empty" << std::endl;
		return (1);
	}
	replacement = std::string(av[3]);

	while (std::getline(input_file, line)) {
		while ((pos = line.find(to_replace, spos)) != std::string::npos)
		{
			std::string	tmp;
			tmp = line.substr(0, pos);
			tmp += replacement;
			tmp += line.substr(pos + to_replace.length());
			line = tmp;
			spos += pos + to_replace.length() + 1;
		}
		spos = 0;
		output_file << line << std::endl;
	}
	return (0);
}

int	main(int ac, char **av)
{
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

	//? Replacement and writing part
	replacement(input_file, output_file, av);
	input_file.close();
	output_file.close();
}