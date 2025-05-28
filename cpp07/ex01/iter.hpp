#pragma once

#include <cstddef>

template<typename T, typename F>
void	iter(T *array, size_t lenght, F function)
{
	for (size_t i = 0; i < lenght; ++i)
		function(array[i]);
}
