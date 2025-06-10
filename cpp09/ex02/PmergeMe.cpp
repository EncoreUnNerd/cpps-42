#include "PmergeMe.hpp"

void print_v(std::vector<int> vec)
{
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << " " << vec[i];
	std::cout << RESET << std::endl;
}

void print_d(std::deque<int> deq)
{
	for (size_t i = 0; i < deq.size(); ++i)
		std::cout << " " << deq[i];
	std::cout << RESET << std::endl;
}

std::vector<int> generateJacobsthalSequence(int n)
{
    std::vector<int> jacobsthal;
    jacobsthal.push_back(1);
    jacobsthal.push_back(1);

    while (jacobsthal.back() < n)
    {
        int next = jacobsthal[jacobsthal.size()-1] + 2 * jacobsthal[jacobsthal.size()-2];
        jacobsthal.push_back(next);
    }
    return jacobsthal;
}

std::vector<int> generateInsertionOrder(int n)
{
    std::vector<int> order;
    if (n == 0) return order;

    order.push_back(0);

    std::vector<int> jacobsthal = generateJacobsthalSequence(n);
    int prev = 1;

    for (size_t i = 2; i < jacobsthal.size() && jacobsthal[i] <= n; ++i)
    {
        int current = jacobsthal[i];

        for (int j = std::min(current, n-1); j >= prev; --j)
        {
            order.push_back(j);
        }
        prev = current + 1;
    }

    for (int i = prev; i < n; ++i)
        order.push_back(i);

    return order;
}
