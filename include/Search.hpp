#pragma once
#include "Defines.hpp"

namespace Delve
{
namespace Search
{
template<typename T, size_t Len>
DELVE int linear_search(const T (*array)[Len], const T Key)
{
	for (size_t i = 0; i < Len; i++)
	{
		if (array[i] == Key)
		{
			return i;
		}
	}
	return -1;
}

template<typename T>
DELVE int linear_search(const T(*array), const T Key)
{
	for (size_t i = 0; i < sizeof(array); i++)
	{
		if (array[i] == Key)
		{
			return i;
		}
	}
	return -1;
}

template<typename T, size_t Len>
DELVE int binary_search(const T (*array)[Len], const T Key)
{
	if (Key > array[Len / 2])
	{
		for (int i = 0; i < Len / 2; i++)
		{
			if (array[i] == Key)
			{
				return i;
			}
		}
	}
	else
	{
		for (int i = Len / 2; i < Len; i++)
		{
			if (array[i] == Key)
			{
				return i;
			}
		}
	}
	return -1;
}

template<typename T>
DELVE int binary_search(const T(*array), const T Key)
{
	if (Key > array[sizeof(array) / 2])
	{
		for (int i = 0; i < sizeof(array) / 2; i++)
		{
			if (array[i] == Key)
			{
				return i;
			}
		}
	}
	else
	{
		for (int i = sizeof(array) / 2; i < sizeof(array); i++)
		{
			if (array[i] == Key)
			{
				return i;
			}
		}
	}
	return -1;
}
} // namespace Search
} // namespace Delve
