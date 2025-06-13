#pragma once

#include <exception>

template<typename T>
class Array
{
	private:
		T				*_array;
		unsigned int	_size;
	public:
		unsigned int	size();
		Array			&operator=(const Array &to_copy);
		T				&operator[](unsigned int index);
		const T			&operator[](unsigned int index) const;

		Array();
		Array(unsigned int n);
		Array(const Array &to_copy);
		~Array();

		class OutOufBoundException : public std::exception {
			public:
				const char* what() const throw();
		};
};

// --- Function --- //
template<typename T>
unsigned int	Array<T>::size()
{
	return (_size);
}

// --- Operators --- //
template<typename T>
Array<T>	&Array<T>::operator=(const Array<T> &to_copy)
{
	if (this != &to_copy)
	{
		delete[] _array;
		_size = to_copy._size;
		_array = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            _array[i] = to_copy._array[i];
	}
	return (*this);
}

template<typename T>
T	&Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOufBoundException();
	return _array[index];
}

template<typename T>
const T	&Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw OutOufBoundException();
	return _array[index];
}

// --- Constructors --- //
template<typename T>
Array<T>::Array(): _array(new T[0]), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int index): _array(new T[index]), _size(index) {}

template<typename T>
Array<T>::Array(const Array<T> &to_copy)
{
	_size = to_copy._size;
	_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = to_copy._array[i];
}

// --- Destructor --- //
template<typename T>
Array<T>::~Array()
{
	delete[] _array;
};

// --- Exception --- //
template<typename T>
const char* Array<T>::OutOufBoundException::what() const throw()
{
    return "Index out of bounds";
}
