#include "Span.hpp"
#include <algorithm>
#include <climits>

// --- Functions --- //
void	Span::addNumber(int number)
{
	if (_vector.size() >= _size)
		throw TooManyElement();
	_vector.push_back(number);
}

int	Span::longestSpan()
{
	if (_vector.size() < 2)
		throw NotEnoughElement();
	std::sort(_vector.begin(), _vector.end());
	return _vector.back() - _vector.front();
}

int	Span::shortestSpan()
{
	if (_vector.size() < 2)
		throw NotEnoughElement();
	std::sort(_vector.begin(), _vector.end());
	int min_diff = INT_MAX;
	for (size_t i = 1; i < _vector.size(); ++i)
	{
		if (_vector[i] - _vector[i-1] < min_diff)
			min_diff = _vector[i] - _vector[i-1];
	}
    return min_diff;
}

// --- Operator --- //
Span &Span::operator=(const Span &to_copy)
{
	if (this != &to_copy)
	{
		_size = to_copy._size;
		_vector.clear();
		_vector = to_copy._vector;
	}
	return *this;
}

// --- Constructors --- //
Span::Span(): _size(5) {}

Span::Span(unsigned int size): _size(size) {}

Span::Span(const Span &to_copy)
{
	_size = to_copy._size;
	_vector = to_copy._vector;
}

// --- Destructor --- //
Span::~Span() {}

// --- Exceptions --- //
const char *Span::TooManyElement::what() const throw()
{
	return "Span has reached its maximum capacity";
}

const char *Span::NotEnoughElement::what() const throw()
{
	return "Span has less than 2 arguments";
}
