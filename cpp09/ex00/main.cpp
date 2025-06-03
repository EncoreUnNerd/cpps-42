#include "BitcoinExchange.hpp"
#include <exception>
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>

int main(int ac, char **av)
{
	std::map<std::string, float> 	database;
	std::stringstream				ss;
	std::string						date;
	std::string						value;
	float							value_float;

	if (ac != 2)
	{
		std::cout << RED << "Wrong number of argument" << RESET << std::endl;
		return 1;
	}

	try {
		database = get_database();
	} catch (std::exception &e) {
		std::cout << RED << "Failed to parse data : " << e.what() << std::endl;
	}

	std::ifstream dataFile(av[1]);
	if (!dataFile.is_open())
	{
		std::cout << RED << "Failed to open : " << av[1] << RESET << std::endl;
		return 1;
	}
	std::string	line;
	std::getline(dataFile, line);
	while (std::getline(dataFile, line))
	{
		date = line.substr(0, line.find("|"));
		if (!isValidDateFormat(date))
		{
			std::cout << RED << "Error: Bad input => "<< date << RESET << std::endl;
			continue;
		}
		value = line.substr(line.find("|")+1, line.length());
		ss.clear();
		ss.str(value);
		ss >> value_float;
		if (ss.fail() || !ss.eof())
	    	std::cout << RED << "Error: Bad input => " << value << RESET << std::endl;
		else if (value_float < 0)
			std::cout << RED << "Error: not a positive number." << RESET << std::endl;
		else if (value_float > 1000)
			std::cout << RED << "Error: too large a number." << RESET << std::endl;
		else
		{
			std::map<std::string, float>::iterator result = findDateOrClosestOlder(database, date);
			std::cout << date << " => " << value << " = " << value_float * result->second << std::endl;
		}
	}

	return 0;
}
