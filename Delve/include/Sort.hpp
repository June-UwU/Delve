#include "Defines.hpp"
namespace Delve
{
namespace Sort
{
template<typename T, size_t N>
void insertion_sort(T (&array)[N]) noexcept;
template<typename T>
void merge_sort(T* array, int Left, int Right) noexcept;
} // namespace Sort
} // namespace Delve

#include "Sort.inl"
