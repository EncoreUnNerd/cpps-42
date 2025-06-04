#include "RPN.hpp"

// --- Functions --- //
void ReversePolish::add(int n)
{
	_stack.push(n);
}

void ReversePolish::process(char p)
{
	if (p == '+' || p == '-' || p == '*' || p == '/')
	{
		if (_stack.size() < 2)
            throw std::runtime_error("Error: insufficient operands.");

		int value2 = _stack.top(); _stack.pop();
		int value1 = _stack.top(); _stack.pop();

		if (p == '+')
			_stack.push(value1 + value2);
		else if (p == '-')
			_stack.push(value1 - value2);
		else if (p == '*')
			_stack.push(value1 * value2);
		else if (p == '/')
		{
			if (value2 == 0)
				throw std::runtime_error("Error: can't divide by 0.");
			_stack.push(value1 / value2);
		}
	}
	else
		throw std::runtime_error("Error: not a valid operator.");
}

int	ReversePolish::end()
{
	if (_stack.size() != 1)
        throw std::runtime_error("Error: Too many number in stack.");
    return (_stack.top());
}

// --- Constructor --- //
ReversePolish::ReversePolish() {}

// --- Destructor --- //
ReversePolish::~ReversePolish() {}
