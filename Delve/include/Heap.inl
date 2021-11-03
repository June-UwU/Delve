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
