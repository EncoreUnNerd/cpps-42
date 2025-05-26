#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << RED << "Wrong number of argument (╯°□°)╯︵ ┻━┻" << RESET << std::endl;
		return (EXIT_FAILURE);
	}
	ScalarConverter::convert(argv[1]);
	return (EXIT_SUCCESS);
}
