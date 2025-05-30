#pragma once

#include <stack>

template<typename T>
class MutantStack: public std::stack<T>
{
	public:
		// --- Constructors --- //
		MutantStack(): std::stack<T>() {}
		MutantStack(const MutantStack &to_copy): std::stack<T>(to_copy) {}

		// --- Destrcutor --- //
		~MutantStack() {};

		// --- Operator --- //
		MutantStack &operator=(const MutantStack &to_copy)
		{
			if (this != &to_copy)
			{
				std::stack<T>::operator=(to_copy);
			}
			return *this;
		}

		// --- Iterators --- //
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		// --- Get iterators --- //
		iterator begin()
		{
			return this->c.begin();
		}

		iterator end()
		{
			return this->c.end();
		}

		const_iterator begin() const
		{
			return this->c.begin();
		}

		const_iterator end() const
		{
			return this->c.end();
		}

		reverse_iterator rbegin()
		{
			return this->c.rbegin();
		}

		reverse_iterator rend()
		{
			return this->c.rend();
		}

		const_reverse_iterator rbegin() const
		{
			return this->c.rbegin();
		}

		const_reverse_iterator rend() const
		{
			return this->c.rend();
		}
};
