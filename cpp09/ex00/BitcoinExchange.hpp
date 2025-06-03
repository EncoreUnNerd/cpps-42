#pragma once

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

#include <map>
#include <string>

std::map<std::string, float>	get_database();
bool 							isValidDateFormat(std::string &date);
std::map<std::string, float>::iterator
findDateOrClosestOlder(std::map<std::string, float>& dateMap, const std::string& targetDate);
