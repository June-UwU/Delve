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
inline Heap<T, N>::Heap(const Heap& rhs) noexcept
{
	for (size_t i = 0; i < N; i++)
	{
		if (i == rhs.size())
		{
			break;
		}
		m_Array[i] = rhs.m_Array[i];
	}
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
	for (size_t i = 0; i < N; i++)
	{
		if (i == rhs.size())
		{
			break;
		}
		m_Array[i] = rhs.m_Array[i];
	}
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
