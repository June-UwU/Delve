#include "Defines.hpp"
#include <limits.h>

// TODO:make a pointer size versions for all required ones
namespace Delve
{
namespace Sort
{
template<typename T, size_t N>
void insertion_sort(T (&ptr)[N]) noexcept;
template<typename T>
void merge_sort(T* ptr, size_t size) noexcept;
template<typename T>
void insertion_sort(T* ptr, size_t N) noexcept;
template<typename T>
void heap_sort(T* ptr, size_t N) noexcept;
template<typename T>
T* counting_sort_ret(T* ptr, size_t N, T max_range, T min_range) noexcept;
template<typename T>
void quick_sort(T* ptr, int low, int N) noexcept;
} // namespace Sort
} // namespace Delve

#include "implementation/Sort.inl"
