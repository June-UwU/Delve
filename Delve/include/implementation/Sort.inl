#pragma once
#include <limits>
#include "Sort.hpp"
#include "..\Sort.hpp"

namespace Delve
{
namespace Sort
{
template<typename T, size_t N>
void insertion_sort(T (&array)[N]) noexcept
{
	for (int i = 0; i < N; i++)
	{
		T Key = array[i];
		for (int j = i; j < N; j++)
		{
			if (Key > array[j])
			{
				Key		 = array[j];
				array[j] = array[i];
				array[i] = Key;
			}
		}
	}
}
template<typename T>
void merge(T* array, size_t left, size_t mid, size_t right, size_t size)
{
	size_t l_size  = mid - left + 1;
	size_t r_size  = right - mid;
	T*	   l_array = new T[l_size];
	T*	   r_array = new T[r_size];
	for (size_t i = 0; i < l_size; i++)
	{
		l_array[i] = array[left + i];
	}
	for (size_t i = 0; i < r_size; i++)
	{
		if ((mid + 1 + i) == size)
		{
			// last edge case handling...size will be zero here
			r_size--;
		}
		else
		{
			r_array[i] = array[mid + i + 1];
		}
	}
	size_t l_index = 0;
	size_t r_index = 0;
	size_t a_index = left;
	while ((l_index < l_size) && (r_index < r_size))
	{
		if (l_array[l_index] <= r_array[r_index])
		{
			array[a_index] = l_array[l_index];
			l_index++;
		}
		else
		{
			array[a_index] = r_array[r_index];
			r_index++;
		}
		a_index++;
	}
	while (l_index < l_size)
	{
		array[a_index] = l_array[l_index];
		l_index++;
		a_index++;
	}
	while (r_index < r_size)
	{
		array[a_index] = r_array[r_index];
		r_index++;
		a_index++;
	}
}
template<typename T>
void merge_sort(T* array, size_t left, size_t right, size_t size) noexcept
{
	if (left >= right)
	{
		return;
	}
	else
	{
		size_t middle = (right + left) / 2;
		merge_sort(array, left, middle, size);
		merge_sort(array, middle + 1, right, size);
		merge(array, left, middle, right, size);
	}
}

template<typename T>
void insertion_sort(T* array, size_t N) noexcept
{
	for (int i = 0; i < N; i++)
	{
		T Key = array[i];
		for (int j = i; j < N; j++)
		{
			if (Key > array[j])
			{
				Key		 = array[j];
				array[j] = array[i];
				array[i] = Key;
			}
		}
	}
}

/*implement the left() ,right(),heap sort*/

size_t right(const size_t index) noexcept
{
	return ((2 * index) + 2);
}

size_t left(const size_t index) noexcept
{
	return ((2 * index) + 1);
}

template<typename T>
void max_heapify(T* array, size_t arraysize, int index)
{
	size_t left_index  = left(index);
	size_t right_index = right(index);
	size_t largest{};
	if (left_index < arraysize && array[left_index] > array[index])
	{
		largest = left_index;
	}
	else
	{
		largest = index;
	}

	if (right_index < arraysize && array[right_index] > array[largest])
	{
		largest = right_index;
	}

	if (largest != index)
	{
		T temp		   = array[largest];
		array[largest] = array[index];
		array[index]   = temp;
		max_heapify(array, arraysize, largest);
	}
}

template<typename T>
void build_max_heap(T* array, size_t arraysize) noexcept // N is the heap size
{
	for (int i = arraysize / 2 - 1; i > -1; i--)
	{
		max_heapify(array, arraysize, i);
	}
}
template<typename T>
void heap_sort(T* array, size_t N) noexcept
{
	build_max_heap(array, N);
	for (size_t i = N - 1; i > 0; i--)
	{
		T temp	 = array[i];
		array[i] = array[0];
		array[0] = temp;
		max_heapify(array, i, 0);
	}
}

template<typename T>
T* counting_sort_ret(
	T*	   array,
	size_t N,
	T	   max_range = std::numeric_limits<T>::max(),
	T	   min_range = std::numeric_limits<T>::min()) noexcept
{
	T*	   ret_array = new T[N];
	size_t pos		 = 0;
	for (T i = min_range; i < max_range + 1; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			if (array[j] == i)
			{
				ret_array[pos] = i;
				pos++;
			}
		}
	}
	return ret_array;
}

template<typename T>
int partition(T* array, int low, int high)
{
	auto pivot = array[high];
	int	 ret   = low - 1;
	for (int i = low; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			ret++;
			T temp	   = array[i];
			array[i]   = array[ret];
			array[ret] = temp;
		}
	}
	ret++;
	T temp		= array[ret];
	array[ret]	= array[high];
	array[high] = temp;
	return ret;
}

template<typename T>
void quick_sort(T* array, int low, int high) noexcept
{
	if (low < high )
	{
		auto pi = partition(array, low, high);
		quick_sort(array, low, pi - 1);
		quick_sort(array, pi , high);
	}
}

} // namespace Sort
} // namespace Delve
