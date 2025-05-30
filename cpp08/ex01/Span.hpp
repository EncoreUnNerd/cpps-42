#pragma once

#include <exception>
#include <vector>

class Span
{
	private:
		unsigned int		_size;
		std::vector<int>	_vector;
	public:
		void	addNumber(int number);
		int		shortestSpan();
		int		longestSpan();
		Span	&operator=(const Span &to_copy);

		template<typename Iterator>
		void	addNumberRange(Iterator first, Iterator last)
		{
			size_t count = std::distance(first, last);
			if (_vector.size() + count > _size)
				throw TooManyElement();
			_vector.insert(_vector.end(), first, last);
		}

		Span();
		Span(unsigned int size);
		Span(const Span &to_copy);
		~Span();

		class TooManyElement : public std::exception {
			public:
				const char* what() const throw();
		};
		class NotEnoughElement : public std::exception {
			public:
				const char* what() const throw();
		};
};
