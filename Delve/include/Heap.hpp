#pragma once
#include <initializer_list>
namespace Delve
{
namespace Structures
{
template<typename T, size_t N>
class Heap
{
public:
	Heap();
	Heap(const Heap& rhs) noexcept;
	Heap(const Heap&& rhs) noexcept;
	Heap& operator=(const Heap& rhs);
	Heap& operator=(const Heap&& rhs);
	Heap(const T* ptr) noexcept;
	Heap(std::initializer_list<T> list) noexcept;
	size_t size() const { return N; };
	T*	   get() const { return m_Array; };
	T	   operator[](size_t index) const { return m_Array[index]; };
	T	   get_parent(size_t index) const;
	T	   get_left_child(size_t index) const;
	T	   get_right_child(size_t index) const;

private:
	T* m_Array;
};
} // namespace Structures
} // namespace Delve
#include "Heap.inl"
