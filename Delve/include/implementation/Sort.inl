#pragma once
#include <limits>
#include "Sort.hpp"

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
	return 0;
}

size_t left(const size_t index) noexcept
{
	return 0;
}

template<typename T>
void max_heapify(T* array, size_t heap_size, size_t index)
{
	size_t left_index	 = left(index);
	size_t right_index	 = right(index);
	size_t largest_index = index;
	if (left_index <= heap_size && array[left_index] > array[index])
	{
		largest_index = left_index;
	}
	if (right_index <= heap_size && array[right_index] > array[index])
	{
		largest_index = right_index;
	}
	if (largest_index == index)
	{
		T temp				 = array[index];
		array[index]		 = array[largest_index];
		array[largest_index] = temp;
		max_heapify(array, heap_size, largest_index);
	}
}

template<typename T>
void build_max_heap(T* array, size_t N) noexcept // N is the heap size
{
	size_t heap_size = N;
	for (size_t i = N / 2; i >= 0; i++)
	{
		max_heapify(array, N, i);
	}
}
template<typename T>
void heap_sort(T* array, size_t heapsize, size_t N) noexcept
{
}

} // namespace Sort
} // namespace Delve
