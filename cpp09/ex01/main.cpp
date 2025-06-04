#include "RPN.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << RED << "Error: Wrong number of argument" << RESET << std::endl;
		return 1;
	}

	ReversePolish	reverse;
	bool			wv = 0;
	char			l;
	std::string		calcul(av[1]);

	for (size_t i = 0; i < calcul.length(); ++i)
	{
		l = calcul[i];
		if (l == ' ')
		{
			wv = 0;
			continue;
		}
		if (wv == 1)
		{
			std::cerr << RED << "Error: every operands and operator should be spaced." << std::endl;
			return 1;
		}
		if (l >= '0' && l <= '9')
			reverse.add(strtol(&l, NULL, 10));
		else
		{
			try
			{
				reverse.process(l);
			}
			catch (std::exception &e)
			{
				std::cerr << RED << e.what() << RESET << std::endl;
				return 1;
			}
		}
	}
	try
	{
		std::cout << GREEN << reverse.end() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
		return 1;
	}
	return (0);
}
