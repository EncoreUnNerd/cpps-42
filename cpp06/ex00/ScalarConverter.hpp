#pragma once

#include <string>

#define GREY   "\033[90m"
#define RED  "\033[31m"
#define BLUE   "\033[34m"
#define GREEN   "\033[32m"
#define RESET  "\033[0m"

class ScalarConverter
{
	private:
		ScalarConverter &operator=(ScalarConverter &to_copy);

		ScalarConverter();
		ScalarConverter(ScalarConverter &to_copy);
		~ScalarConverter();

	public:
		static void convert(std::string literal);
};

bool check_int(std::string literal);
bool check_float(std::string literal);
bool check_double(std::string literal);

void	int_path(std::string literal);
void	double_path(std::string literal);
void	float_path(std::string literal);
void	char_path(std::string literal);
