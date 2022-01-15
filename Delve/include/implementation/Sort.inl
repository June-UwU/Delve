#pragma once
#include <limits>
#include "Sort.hpp"
#include "..\Sort.hpp"

namespace Delve
{
namespace Sort
{
template<typename T, size_t N>
void insertion_sort(T (&ptr)[N]) noexcept
{
	for (int i = 0; i < N; i++)
	{
		T Key = ptr[i];
		for (int j = i; j < N; j++)
		{
			if (Key > ptr[j])
			{
				Key	   = ptr[j];
				ptr[j] = ptr[i];
				ptr[i] = Key;
			}
		}
	}
}
template<typename T>
void merge_sort(T* ptr, size_t size) noexcept
{
	T* temp = new T[size];
	intern_merge_sort<T>(ptr, 0, size - 1, temp);
	delete[] temp;
}
template<typename T>
void merge(T* ptr, size_t left, size_t mid, size_t right, T* temp)
{
	size_t l_index = left;
	size_t r_index = mid + 1;
	for (size_t i = left; i <= mid; i++)
	{
		temp[i] = ptr[i];
	}
	for (size_t i = mid + 1; i <= right; i++)
	{
		temp[i] = ptr[i];
	}
	size_t index = left;
	while (l_index <= mid && r_index <= right)
	{
		if (temp[l_index] < temp[r_index])
		{
			ptr[index++] = temp[l_index++];
		}
		else
		{
			ptr[index++] = temp[r_index++];
		}
	}
	while (l_index <= mid)
	{
		ptr[index++] = temp[l_index++];
	}
	while (r_index <= right)
	{
		ptr[index++] = temp[r_index++];
	}
}
template<typename T>
void intern_merge_sort(T* ptr, size_t left, size_t right, T* temp) noexcept
{
	if (left < right)
	{
		size_t middle = (right + left) / 2;
		intern_merge_sort<T>(ptr, left, middle, temp);
		intern_merge_sort<T>(ptr, middle + 1, right, temp);
		merge<T>(ptr, left, middle, right, temp);
	}
}

template<typename T>
void insertion_sort(T* ptr, size_t N) noexcept
{
	for (int i = 0; i < N; i++)
	{
		T Key = ptr[i];
		for (int j = i; j < N; j++)
		{
			if (Key > ptr[j])
			{
				Key	   = ptr[j];
				ptr[j] = ptr[i];
				ptr[i] = Key;
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
void max_heapify(T* ptr, size_t ptrsize, int index)
{
	size_t left_index  = left(index);
	size_t right_index = right(index);
	size_t largest{};
	if (left_index < ptrsize && ptr[left_index] > ptr[index])
	{
		largest = left_index;
	}
	else
	{
		largest = index;
	}

	if (right_index < ptrsize && ptr[right_index] > ptr[largest])
	{
		largest = right_index;
	}

	if (largest != index)
	{
		T temp		 = ptr[largest];
		ptr[largest] = ptr[index];
		ptr[index]	 = temp;
		max_heapify(ptr, ptrsize, largest);
	}
}

template<typename T>
void build_max_heap(T* ptr, size_t ptrsize) noexcept // N is the heap size
{
	for (int i = ptrsize / 2 - 1; i > -1; i--)
	{
		max_heapify(ptr, ptrsize, i);
	}
}
template<typename T>
void heap_sort(T* ptr, size_t N) noexcept
{
	build_max_heap(ptr, N);
	for (size_t i = N - 1; i > 0; i--)
	{
		T temp = ptr[i];
		ptr[i] = ptr[0];
		ptr[0] = temp;
		max_heapify(ptr, i, 0);
	}
}

template<typename T>
T* counting_sort_ret(
	T*	   ptr,
	size_t N,
	T	   max_range = std::numeric_limits<T>::max(),
	T	   min_range = std::numeric_limits<T>::min()) noexcept
{
	T*	   ret_ptr = new T[N];
	size_t pos	   = 0;
	for (T i = min_range; i < max_range + 1; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			if (ptr[j] == i)
			{
				ret_ptr[pos] = i;
				pos++;
			}
		}
	}
	return ret_ptr;
}

template<typename T>
int partition(T* ptr, int low, int high)
{
	auto pivot = ptr[high];
	int	 ret   = low - 1;
	for (int i = low; i < high; i++)
	{
		if (ptr[i] <= pivot)
		{
			ret++;
			T temp	 = ptr[i];
			ptr[i]	 = ptr[ret];
			ptr[ret] = temp;
		}
	}
	ret++;
	T temp	  = ptr[ret];
	ptr[ret]  = ptr[high];
	ptr[high] = temp;
	return ret;
}

template<typename T>
void quick_sort(T* ptr, int low, int high) noexcept
{
	if (low < high)
	{
		auto pi = partition(ptr, low, high);
		quick_sort(ptr, low, pi - 1);
		quick_sort(ptr, pi, high);
	}
}

} // namespace Sort
} // namespace Delve
