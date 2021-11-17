#include "Defines.hpp"
#include "Search.hpp"

namespace Delve
{
namespace Search
{
template<typename T, size_t N>
T linear_search(const T (&array)[N], const T Key) noexcept
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

template<typename T, size_t N>
T binary_search(const T (&array)[N], const T Key) noexcept
{
	if (Key < array[N / 2])
	{
		for (int i = 0; i < N / 2; i++)
		{
			if (array[i] == Key)
			{
				return i;
			}
		}
	}
	else
	{
		for (int i = N / 2; i < N; i++)
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

} // namespace Delve
