#include <vector>
#include <deque>
#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    std::vector<int> init_v;
    std::deque<int> init_d;
    int i = 1;
    char *ptr = NULL;
    long tmp = 0;

    if (ac < 2)
    {
    	std::cout << RED << "Not enough argument !" << RESET << std::endl;
        return 1;
    }
    while (av[i])
    {
        tmp = strtol(av[i], &ptr, 10);
        if (ptr == NULL)
        {
        	std::cout << RED << "Invalid !" << RESET << std::endl;
            return 0;
        }
        if (*ptr != '\0')
        {
        	std::cout << RED << "Invalid (pobably not a full number) !" << RESET << std::endl;
            return 1;
        }
        if (tmp < 0)
        {
        	std::cout << RED << "Invalid (negative) !" << RESET << std::endl;
            return 1;
        }
        if (tmp > INT_MAX || tmp < INT_MIN)
        {
        	std::cout << RED << "Invalid (too big or too small) !" << RESET << std::endl;
            return 1;
        }
        if (std::find(init_v.begin(), init_v.end(), tmp) != init_v.end())
        {
        	std::cout << RED << "Invalid (already in vector) !" << RESET << std::endl;
            return 1;
        }
        else
        {
            init_v.push_back(tmp);
            init_d.push_back(tmp);
        }
        i++;
    }

    std::cout << BLUE << "Before: ";
    for (size_t i = 0; i < init_v.size(); ++i)
        std::cout << " " << init_v[i];
    std::cout << RESET << std::endl;

    // Mesure temps pour std::vector
    clock_t start_v = clock();
    int operations_v = 0;
    std::vector<int> sorted_v = sort(init_v, operations_v);
    clock_t end_v = clock();
    double time_v = static_cast<double>(end_v - start_v) / CLOCKS_PER_SEC * 1000000; // en microseconds

    // Mesure temps pour std::deque
    clock_t start_d = clock();
    int operations_d = 0;
    std::deque<int> sorted_d = sort(init_d, operations_d);
    clock_t end_d = clock();
    double time_d = static_cast<double>(end_d - start_d) / CLOCKS_PER_SEC * 1000000; // en microseconds

    std::cout << GREEN << "After:  ";
    for (size_t i = 0; i < sorted_v.size(); ++i)
        std::cout << " " << sorted_v[i];
    std::cout << RESET << std::endl;

    // Affichage des temps
    std::cout << YELLOW << "Time to process a range of " << init_v.size()
              << " elements with std::vector : " << std::fixed << std::setprecision(3)
              << time_v << " us" << " with " << operations_v << " operations" << RESET << std::endl;

    std::cout << CYAN << "Time to process a range of " << init_d.size()
              << " elements with std::deque  : " << std::fixed << std::setprecision(3)
              << time_d << " us" << " with " << operations_d << " operations" << RESET << std::endl;

    return (0);
}
