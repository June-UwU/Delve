#include "Defines.hpp"
#include "Search.hpp"

namespace Delve
{
namespace Search
{
template<typename T, size_t Len>
int linear_search(const T (&array)[Len], const T Key)
{
	for (size_t i = 0; i < Len; i++)
	{
		if (array[i] == Key)
		{
			return i;
		}
	}
	return -1;
};

template<typename T, size_t Len>
int binary_search(const T (&array)[Len], const T Key)
{
	if (Key < array[Len / 2])
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
};

} // namespace Search
namespace Sort
{
template<typename T, size_t Len>
void insertion_sort(T (&array)[Len])
{
	for (int i = 0; i < Len; i++)
	{
		T Key = array[i];
		for (int j = i; j < Len; j++)
		{
			if (Key > array[j])
			{
				Key		 = array[j];
				array[j] = array[i];
				array[i] = Key;
			}
		}
	}
};

} // namespace Sort
} // namespace Delve
