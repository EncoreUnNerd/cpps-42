#include <iostream>
#include <climits>
#include <vector>
#include "easyfind.hpp"


int main() {
    std::vector<int> test;
    test.push_back(1);
    test.push_back(4);
    test.push_back(5);
    test.push_back(6);

    std::vector<int>::iterator e = easyfind(test, 4);
    if (e != test.end())
   		std::cout << "Working found " << *e << std::endl;
    else
    	std::cout << "dont work :(" << std::endl;

    return 0;
}
