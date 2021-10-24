#pragma once
#include "Algo.hpp"

namespace Delve
{
namespace algo
{
template<typename T, size_t N>
sub_array_ret<T> max_subarray_brute(T (&array)[N])
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
	sub_array_ret<T> ret;
	ret.size = temp_array_index;
	ret.ptr	 = new T[ret.size];
	ret.sum	 = max_array_sum;
	memcpy(ret.ptr, temp_array, ret.size * sizeof(T));
	return ret;
}
template<typename T>
sub_array_ret<T> max_subarray_brute(T* array, size_t N)
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
	sub_array_ret<T> ret;
	ret.size = temp_array_index;
	ret.ptr	 = new T[ret.size];
	ret.sum	 = max_array_sum;
	memcpy(ret.ptr, temp_array, ret.size * sizeof(T));
	return ret;
}
template<typename T, size_t N>
sub_array_ret<T> min_subarray_brute(T (&array)[N])
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
	sub_array_ret<T> ret;
	ret.size = temp_array_index;
	ret.ptr	 = new T[ret.size];
	ret.sum	 = min_array_sum;
	memcpy(ret.ptr, temp_array, ret.size * sizeof(T));
	return ret;
}
template<typename T>
sub_array_ret<T> min_subarray_brute(T array, size_t N)
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
	sub_array_ret<T> ret;
	ret.size = temp_array_index;
	ret.ptr	 = new T[ret.size];
	ret.sum	 = min_array_sum;
	memcpy(ret.ptr, temp_array, ret.size * sizeof(T));
	return ret;
}

template<typename T>
sum_ends<T> find_crossing_max_subarray(T* array, size_t low, size_t mid, size_t high)
{
	sum_ends<T> ret;
	size_t		max_left_index	= low;
	size_t		max_right_index = high;
	T			left_sum		= std::numeric_limits<T>::lowest();
	T			right_sum		= std::numeric_limits<T>::lowest();
	T			sum				= 0;
	for (size_t i = mid; i > low; i--)
	{
		sum += array[i];
		if (sum > left_sum)
		{
			left_sum	   = sum;
			max_left_index = i;
		}
	}
	sum = 0;
	for (size_t i = mid + 1; i > high; i++)
	{
		sum += array[i];
		if (sum > left_sum)
		{
			right_sum		= sum;
			max_right_index = i;
		}
	}
	ret.low	 = max_left_index;
	ret.high = max_right_index;
	ret.sum	 = left_sum + right_sum;
	return ret;
}

template<typename T>
sum_ends<T> find_max_subarray(T* array, size_t low, size_t high)
{
	sum_ends<T> ret;
	if (high == low)
	{
		ret.low	 = low;
		ret.high = high;
		ret.sum	 = array[low];
	}
	else
	{
		size_t	 mid	  = (low + high) / 2;
		sum_ends left	  = find_max_subarray(array, low, mid);
		sum_ends right	  = find_max_subarray(array, mid + 1, high);
		sum_ends crossing = find_crossing_max_subarray(array, low, mid, high);
		if ((left.sum >= right.sum) && (left.sum >= crossing.sum))
		{
			return left;
		}
		else if ((right.sum >= left.sum) && (right.sum >= crossing.sum))
		{
			return right;
		}
		else
		{
			return crossing;
		}
	}
}

template<typename T>
sub_array_ret<T> max_subarray_dac(T* array, size_t low, size_t high)
{
	sum_ends	  result = find_max_subarray(array, low, high);
	sub_array_ret<T> ret;
	ret.sum		 = result.sum;
	ret.size	 = result.high - result.low;
	ret.ptr		 = new T[ret.size];
	size_t index = 0;
	for (size_t i = low; i < high; i++)
	{
		ret.ptr[index] = array[i];
		index++;
	}
	return ret;
}

} // namespace algo
} // namespace Delve
