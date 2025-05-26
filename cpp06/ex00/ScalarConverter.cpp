#include "ScalarConverter.hpp"
#include <iostream>

void ScalarConverter::convert(std::string literal)
{
	if (literal.length() == 1 && !(literal[0] >= '0' && literal[0] <= '9'))
	{
		char_path(literal);
		return ;
	}
	else if (literal[literal.length() - 1] == 'f' && check_float(literal))
	{
		float_path(literal);
		return ;
	}
	else if (check_int(literal))
	{
		int_path(literal);
		return ;
	}
	else if (check_double(literal))
	{
		double_path(literal);
		return ;
	}
	else
	{
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double : impossible" << std::endl;
	}
}

// --- Operator ---

ScalarConverter &ScalarConverter::operator=(ScalarConverter &to_copy)
{
	(void)to_copy;
	return (*this);
}

// --- Constructors ---

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(ScalarConverter &to_copy)
{
	(void)to_copy;
}

ScalarConverter::~ScalarConverter() {};
