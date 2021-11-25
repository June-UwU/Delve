#include "Defines.hpp"
#include <limits.h>

// TODO:make a pointer size versions for all required ones
namespace Delve
{
namespace Sort
{
template<typename T, size_t N>
void insertion_sort(T (&array)[N]) noexcept;
template<typename T>
void merge_sort(T* array, size_t Left, size_t Right, size_t size) noexcept;
template<typename T>
void insertion_sort(T* array, size_t N) noexcept;
template<typename T>
void heap_sort(T* array, size_t N) noexcept;
template<typename T>
T* counting_sort_ret(T* array, size_t N, T max_range, T min_range) noexcept;
} // namespace Sort
} // namespace Delve

#include "implementation/Sort.inl"
