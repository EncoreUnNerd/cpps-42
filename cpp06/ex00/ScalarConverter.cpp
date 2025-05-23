#include "ScalarConverter.hpp"
#include <iostream>

void ScalarConverter::convert(std::string literal)
{
	if (literal[literal.length()-1] == 'f')
	{
		if (check_float(literal))
		{
			float_path(literal);
		}
	}
	// After use sstream to change it in that
	// after cast in every type
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
