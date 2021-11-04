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
	const size_t		size() const { return N; };
	T*			get() const { return m_Array; };
	T			operator[](size_t index) const { return m_Array[index]; };
	T			get_parent(size_t index) const;
	T			get_left_child(size_t index) const;
	T			get_right_child(size_t index) const;
	size_t		child_index_left(const size_t index) const;
	size_t		child_index_right(const size_t index) const;
	static void max_heapify(Heap& ref, size_t index);
	static void build_max_heap(Heap& ref) noexcept;
	static void heap_sort(Heap& ref) noexcept;

private:
	static void sort_max_heapify(Heap& ref, size_t index, size_t limit) noexcept;

private:
	T* m_Array;
};
} // namespace Structures
} // namespace Delve
#include "Heap.inl"
