#include <cfloat>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

void	char_path(std::string literal)
{
	char c = literal[0];

	std::cout << "char : " << c << std::endl;
	std::cout << "int : " << static_cast<int>(c) << std::endl;
	std::cout << "float : " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double : " << static_cast<double>(c) << ".0" << std::endl;
}

void	float_path(std::string literal)
{
	char	c;
	float	value = strtof(literal.c_str(), NULL);

	c = static_cast<char>(value);
	if (value > 127 || value < 0)
		std::cout << "char : impossible" << std::endl;
	else if (c < 32 || c == 127)
		std::cout << "char : Non displayable" << std::endl;
	else
		std::cout << "char : '" << static_cast<char>(value) << "'" << std::endl;

	if (value > (float)INT_MAX || value < (float)INT_MIN)
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << static_cast<int>(value) << std::endl;

	std::stringstream ss;
	ss << value;
	if ((literal.find(".") == std::string::npos || (literal.find(".0") == literal.length() - 3)) && ss.str().find("e") == std::string::npos)
	{
		std::cout << "float : " << value << ".0f" << std::endl;
		std::cout << "double : " << static_cast<double>(value) << ".0" << std::endl;
	}
	else
	{
		std::cout << "float : " << value << "f" << std::endl;
		std::cout << "double : " << static_cast<double>(value) << std::endl;
	}
}

void	double_path(std::string literal)
{
	char	c;
	double	value = strtod(literal.c_str(), NULL);

	c = static_cast<char>(value);
	if (value > 127 || value < 0)
		std::cout << "char : impossible" << std::endl;
	else if (c < 32 || c == 127)
		std::cout << "char : Non displayable" << std::endl;
	else
		std::cout << "char : '" << static_cast<char>(value) << "'" << std::endl;

	if (value > INT_MAX || value < INT_MIN)
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << static_cast<int>(value) << std::endl;

	std::stringstream ss;
	ss << value;
	if ((literal.find(".") == std::string::npos || (literal.find(".0") == literal.length() - 2)) && ss.str().find("e") == std::string::npos)
	{
		if (value > FLT_MIN && value < FLT_MAX)
			std::cout << "float : " << static_cast<float>(value) << ".0f" << std::endl;
		else
			std::cout << "float : impossible" << std::endl;
		std::cout << "double : " << value << ".0" << std::endl;
	}
	else
	{
		if (value > FLT_MIN && value < FLT_MAX)
			std::cout << "float : " << static_cast<float>(value) << "f" << std::endl;
		else
			std::cout << "float : impossible" << std::endl;
		std::cout << "double : " << value << std::endl;
	}
}

void	int_path(std::string literal)
{
	char	c;
	long	value = strtol(literal.c_str(), NULL, 10);

	c = static_cast<char>(value);
	if (value > 127 || value < 0)
		std::cout << "char : impossible" << std::endl;
	else if (c < 32 || c == 127)
		std::cout << "char : Non displayable" << std::endl;
	else
		std::cout << "char : '" << static_cast<char>(value) << "'" << std::endl;

	std::cout << "int : " << value << std::endl;

	std::stringstream ss;
	ss << static_cast<float>(value);
	if ((literal.find(".") == std::string::npos || (literal.find(".0") == literal.length() - 2)) && ss.str().find("e") == std::string::npos)
	{
		std::cout << "float : " << static_cast<float>(value) << ".0f" << std::endl;
		std::cout << "double : " << static_cast<double>(value) << ".0" << std::endl;
	}
	else
	{
		std::cout << "float : " << static_cast<float>(value) << "f" << std::endl;
		std::cout << "double : " << static_cast<double>(value) << std::endl;
	}
}
