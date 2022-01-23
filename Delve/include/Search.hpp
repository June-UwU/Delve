#pragma once
#include "Defines.hpp"

namespace Delve
{
namespace Search
{
template<typename T, size_t N>
int linear_search(const T (&array)[N], const T Key) noexcept;
template<typename T>
int binary_search(const T* array, const T Key, size_t N) noexcept;
} // namespace Search

} // namespace Delve

#include "implementation/Search.inl"
