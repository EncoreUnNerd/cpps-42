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
		std::cout << "float : " << static_cast<float>(value) << ".0f" << std::endl;
		std::cout << "double : " << static_cast<double>(value) << ".0" << std::endl;
	}
	else
	{
		std::cout << "float : " << static_cast<float>(value) << "f" << std::endl;
		std::cout << "double : " << static_cast<double>(value) << std::endl;
	}
}

void other_path(std::string literal)
{
	int value_int;
	float value_float;
	double value_double;

	(void)value_float;
	std::stringstream ss(literal);
	if (ss >> value_double)
	{
		value_int = static_cast<int>(value_double);
		std::cout << "int : " << value_int << std::endl;
	}
	// if (ss >> value_int)
	// 	std::cout << "int : " << value_int << std::endl;
	// else
	// 	std::cout << "int : impossible" << std::endl;
	// ss.clear();
	// ss.str(literal);
	// if (ss >> value_float)
	// 	std::cout << "float : " << value_float << std::endl;
	// else
	// 	std::cout << "float : impossible" << std::endl;
	// ss.clear();
	// ss.str(literal);
	// if (ss >> value_double)
	// 	std::cout << "double : " << value_double << std::endl;
	// else
	// 	std::cout << "double : impossible" << std::endl;
}
