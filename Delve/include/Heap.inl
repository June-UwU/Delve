#pragma once
#include <algorithm>
#include <cassert>
#include <type_traits>
#include <limits>
#include "Heap.hpp"
namespace Delve
{
namespace Structures
{
// this might me error prone
template<typename T, size_t N>
inline Heap<T, N>::Heap(const T* ptr) noexcept
{
	m_Array = new T[N];
	memcpy(m_Array, ptr, N * sizeof(T));
}

// this might be error prone
template<typename T, size_t N>
inline Heap<T, N>::Heap(std::initializer_list<T> list) noexcept
{
	memcpy(m_Array, list.get(), N * sizeof(T));
}
template<typename T, size_t N>
inline T Heap<T, N>::get_parent(size_t index) const
{
	if (index == 0)
	{
		return std::numeric_limits<T>::max();
	}
	else if (index % 2 == 0)
	{
		return m_Array[(index - 1) / 2];
	}
	return m_Array[index / 2];
}
template<typename T, size_t N>
inline T Heap<T, N>::get_left_child(size_t index) const
{
	if (N > ((2 * index) + 1))
	{
		return m_Array[(2 * index) + 1];
	}
	else // defining a predictable behaviour for the cases where a child is not present
	{
		return std::numeric_limits<T>::max();
	}
}
template<typename T, size_t N>
inline T Heap<T, N>::get_right_child(size_t index) const
{
	if (N > (2 * (index + 1)))
	{
		return m_Array[(2 * (index + 1))];
	}
	else // defining a predictable behaviour for the cases where a child is not present
	{
		return std::numeric_limits<T>::max();
	}
}

template<typename T, size_t N>
inline size_t Heap<T, N>::child_index_left(const size_t index) const
{
	if (index < N)
	{
		return ((2 * index) + 1);
	}
	else
	{
		return std::numeric_limits<T>::max();
	}
}
template<typename T, size_t N>
inline size_t Heap<T, N>::child_index_right(const size_t index) const
{
	if (index < N)
	{
		return ((index + 1) * 2);
	}
	else
	{
		std::numeric_limits<size_t>::max();
	}
}
template<typename T, size_t N>
inline void Heap<T, N>::max_heapify(Heap& ref, size_t index)
{
	size_t left_index  = ref.child_index_left(index);
	size_t right_index = ref.child_index_right(index);
	size_t largest{ index };
	if (left_index < N && ref.m_Array[left_index] > ref.m_Array[index])
	{
		largest = left_index;
	}
	else if (right_index < N && ref.m_Array[right_index] > ref.m_Array[index])
	{
		largest = right_index;
	}
	if (ref.m_Array[largest] > ref.m_Array[right_index])
	{
		T temp			 = ref.m_Array[largest];
		ref.m_Array[largest] = ref.m_Array[index];
		ref.m_Array[index]	 = ref.m_Array[largest];
		max_heapify(ref, largest);
	}
}
template<typename T, size_t N>
inline void Heap<T, N>::build_max_heap(Heap& ref) noexcept
{
	for (size_t i = ref.size() / 2; i >= 0; i--)
	{
		max_heapify(ref, i);
	}
}
template<typename T, size_t N>
inline void Heap<T, N>::heap_sort(Heap& ref) noexcept
{
	size_t nodes = N;
	build_max_heap(ref);
	size_t lenght = ref.size();
	for (size_t i = lenght - 1; i >= 0; i--)
	{
		T temp		   = ref.m_Array[i];
		ref.m_Array[0] = ref.m_Array[i];
		ref.m_Array[i] = 0;
		nodes -= 1;
		sort_max_heapify(ref, 0, nodes);
	}
}
template<typename T, size_t N>
inline void Heap<T, N>::sort_max_heapify(Heap& ref, size_t index, size_t limit) noexcept
{
	size_t left_index  = limit < ref.child_index_left(index) ? index : ref.child_index_left(index);
	size_t right_index = limit < ref.child_index_right(index) ? index : ref.child_index_right(index);
	size_t largest{ index };
	if (left_index < N && ref.m_Array[left_index] > ref.m_Array[index])
	{
		largest = left_index;
	}
	else if (right_index < N && ref.m_Array[right_index] > ref.m_Array[index])
	{
		largest = right_index;
	}
	if (ref.m_Array[largest] > ref.m_Array[right_index])
	{
		T temp				 = ref.m_Array[largest];
		ref.m_Array[largest] = ref.m_Array[index];
		ref.m_Array[index]	 = ref.m_Array[largest];
		sort_max_heapify(ref, largest, limit);
	}
}
template<typename T, size_t N>
inline Heap<T, N>::Heap()
{
	m_Array = new T[N];
}

template<typename T, size_t N>
inline Heap<T, N>::Heap(const Heap& rhs) noexcept
{
	m_Array = rhs.m_Array;
}

template<typename T, size_t N>
inline Heap<T, N>::Heap(const Heap&& rhs) noexcept
{
	this->m_Array = rhs.m_Array;
	rhs.m_Array	  = nullptr;
}

template<typename T, size_t N>
inline Heap<T, N>& Heap<T, N>::operator=(const Heap& rhs)
{
	m_Array = new T[N];
	std::copy(rhs.m_Array, rhs.m_Array + N, m_Array);
	return *this;
}

// TDOD : how do i do a move constructor here
template<typename T, size_t N>
inline Heap<T, N>& Heap<T, N>::operator=(const Heap&& rhs)
{
	m_Array		= rhs.m_Array;
	rhs.m_Array = nullptr;
}
} // namespace Structures
} // namespace Delve
