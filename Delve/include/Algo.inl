#pragma once
#include <cstring>
#include "Algo.hpp"

namespace Delve
{
namespace algo
{
template<typename T, size_t N>
array_return<T> max_subarray_brute(T (&array)[N])
{
	T*	   temp_array		= new T[N];
	size_t temp_array_index = 0;
	T	   max_array_sum	= 0;
	for (size_t i = 0; i < N; i++)
	{
		if (max_array_sum < (max_array_sum + array[i]))
		{
			temp_array[temp_array_index] = array[i];
			max_array_sum += array[i];
			temp_array_index++;
		}
	}
	array_return<T> ret;
	ret.size = temp_array_index;
	ret.ptr	 = new T[ret.size];
	memcpy(ret.ptr, temp_array, ret.size * sizeof(T));
	return ret;
}
template<typename T, size_t N>
array_return<T> min_subarray_brute(T(&array)[N])
{
	T*	   temp_array		= new T[N];
	size_t temp_array_index = 0;
	T	   min_array_sum	= 0;
	for (size_t i = 0; i < N; i++)
	{
		if (min_array_sum > (min_array_sum + array[i]))
		{
			temp_array[temp_array_index] = array[i];
			min_array_sum += array[i];
			temp_array_index++;
		}
	}
	array_return<T> ret;
	ret.size = temp_array_index;
	ret.ptr	 = new T[ret.size];
	memcpy(ret.ptr, temp_array, ret.size * sizeof(T));
	return ret;
}
} // namespace algo
} // namespace Delve
