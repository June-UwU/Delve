#pragma once
#include "Algo.hpp"
#include <algorithm>

namespace Delve
{
namespace algo
{
template<typename T>
T max_subarray_kadane(T* ptr, size_t size) noexcept
{
	T max_sum = std::numeric_limits<T>::min();
	T sum	  = 0;
	for (size_t i = 0; i < size; i++)
	{
		sum = std::max(ptr[i], sum + ptr[i]);
		if (max_sum < sum)
		{
			max_sum = sum;
		}
	}
	return max_sum;
}
} // namespace algo
} // namespace Delve
