#pragma once

#include <stack>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

class ReversePolish
{
	private:
		std::stack<int>	_stack;

		ReversePolish &operator=(const ReversePolish &to_copy);
		ReversePolish(const ReversePolish &to_copy);
	public:
		void	add(int n);
		void	process(char p);
		int		end();

		ReversePolish();
		~ReversePolish();
};
