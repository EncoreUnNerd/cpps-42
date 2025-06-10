#pragma once

#include <algorithm>
#include <deque>
#include <vector>
#include <iostream>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

void				print_v(std::vector<int> vec);
void				print_d(std::deque<int> vec);
std::vector<int>	generateInsertionOrder(int n);

template<typename Container>
Container	sort(Container to_sort, int &operations)
{
	Container loosers;
	Container winners;
	Container winners_copy;
	Container loosers_copy;
	int a;
	int b;

	if (to_sort.size() == 1)
		return to_sort;

	for (size_t i = 1; i < to_sort.size(); i += 2)
	{
		a = to_sort[i-1];
		b = to_sort[i];

		operations++;
		if (a > b)
		{
			loosers.push_back(b);
			winners.push_back(a);
		}
		else
		{
			loosers.push_back(a);
			winners.push_back(b);
		}
	}
	if (to_sort.size() % 2 != 0)
	{
		winners.push_back(to_sort[to_sort.size()-1]);
		loosers.push_back(-1);
	}

	winners_copy = winners;
	loosers_copy = loosers;

	winners = sort(winners, operations);

	for (size_t i = 0; i < winners.size(); ++i)
	{
		typename Container::iterator it;
    	it = std::find(winners.begin(), winners.end(), winners_copy[i]);
     	long where = std::distance(winners.begin(), it);
      	loosers_copy[where] = loosers[i];
	}

	loosers = loosers_copy;

	std::vector<int> order = generateInsertionOrder(loosers.size());
	for (size_t idx = 0; idx < order.size(); ++idx)
	{
		int i = order[idx];
		int max = winners.size();
		int min = 0;
		if (loosers[i] != -1)
		{
			while (min < max)
			{
		    	int where = (min + max) / 2;
				operations++;
				if (winners[where] < loosers[i])
			    	min = where + 1;
				else
		    		max = where;
			}
			winners.insert(winners.begin() + min, loosers[i]);
		}
	}
	return winners;
}
