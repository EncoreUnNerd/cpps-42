#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <stdexcept>

std::string ltrim(const std::string& str)
{
    std::string::size_type start = 0;
    while (start < str.length() && std::isspace(str[start]))
        ++start;

    return str.substr(start);
}

std::string rtrim(const std::string& str)
{
    std::string::size_type end = str.length();
    while (end > 0 && std::isspace(str[end - 1]))
        --end;

    return str.substr(0, end);
}

std::string trim(const std::string& str)
{
    return ltrim(rtrim(str));
}

std::map<std::string, float>::iterator findDateOrClosestOlder(std::map<std::string, float>& dateMap, const std::string& targetDate)
{

    std::map<std::string, float>::iterator it = dateMap.find(targetDate);
    if (it != dateMap.end()) {
        return it;
    }

    it = dateMap.lower_bound(targetDate);

    if (it == dateMap.begin()) {
        throw std::runtime_error("Aucune date plus ancienne trouvee");
    }

    --it;
    return it;
}

static bool isLeapYear(int year)
{
    return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

bool isValidDateFormat(std::string &date) {
    std::string::size_type i;
    int year, month, day;
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::stringstream ss;

    date = trim(date);
    if (date.length() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    for (i = 0; i < date.length(); ++i)
    {
        if (i != 4 && i != 7)
        {
            if (date[i] < '0' || date[i] > '9')
                return false;
        }
    }

    ss.str(date.substr(0, 4));
    ss >> year;
    ss.clear();

    ss.str(date.substr(5, 2));
    ss >> month;
    ss.clear();

    ss.str(date.substr(8, 2));
    ss >> day;

    if (month < 1 || month > 12)
        return false;

    if (day < 1) {
        return false;
    }

    if (month == 2 && isLeapYear(year))
        daysInMonth[1] = 29;

    if (day > daysInMonth[month - 1])
        return false;

    return true;
}

std::map<std::string, float> get_database()
{
	std::map<std::string, float>	database;
	std::string						date;
	std::string						value;
	float							value_float;
	std::string 					line;
	std::stringstream				ss;

	std::ifstream dataFile("data.csv");
	if (!dataFile.is_open())
		throw std::runtime_error("Failed to open data.csv");

	std::getline(dataFile, line);
	while (std::getline(dataFile, line))
	{
		date = line.substr(0, line.find(","));
		if (!isValidDateFormat(date))
		{
			std::cout << RED << "Not a valid date : "<< date <<" in data.csv" << RESET << std::endl;
			continue;
		}
		value = line.substr(line.find(",")+1, line.length());
		ss.clear();
		ss.str(value);
		ss >> value_float;
		if (ss.fail() || !ss.eof())
	    	std::cout << RED << "Not a float :" << value  << RESET << std::endl;
		else
			database[date] = value_float;
	}
	dataFile.close();

	return database;
}
