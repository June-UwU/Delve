#include "Defines.hpp"
#include "Search.hpp"

namespace Delve
{
namespace Search
{
template<typename T, size_t N>
int linear_search(const T (&array)[N], const T Key) noexcept
{
	for (size_t i = 0; i < N; i++)
	{
		if (array[i] == Key)
		{
			return i;
		}
	}
	return -1;
};

template<typename T>
int intern_binary_search(const T* array, const T Key, size_t left, size_t right) noexcept
{
	size_t middle = (left + right) / 2;
	if (Key == array[middle])
	{
		return middle;
	}
	if (middle == 0 || left == right)
	{
		return -1;
	}
	if (array[middle] > Key)
	{
		return intern_binary_search<T>(array, Key, left, middle);
	}
	else
	{
		return intern_binary_search<T>(array, Key, middle + 1, right);
	}
	return -1;
}

template<typename T>
int binary_search(const T* array, const T Key, size_t N) noexcept
{
	return intern_binary_search<T>(array, Key, 0, N - 1); // avoiding the less than comparison
};

} // namespace Search

} // namespace Delve
