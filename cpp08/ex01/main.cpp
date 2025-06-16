#include "Span.hpp"
#include <iostream>
#include <climits>

int main()
{
	Span sp = Span(10005);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::vector<int> test;
	for (int i = 0; i < 10000; i++)
		test.push_back(i);

	sp.addNumberRange(test.begin(), test.end());

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return 0;
}
