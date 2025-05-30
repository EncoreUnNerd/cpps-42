#pragma once

#include <algorithm>

template<typename T>
typename T::iterator easyfind(T &v, int value)
{
	return std::find(v.begin(), v.end(), value);
}
