#pragma once
#include "Defines.hpp"

namespace Delve
{
namespace Search
{
template<typename T, size_t N>
T linear_search(const T (&array)[N], const T Key) noexcept;
template<typename T, size_t N>
T binary_search(const T (&array)[N], const T Key) noexcept;
} // namespace Search

} // namespace Delve

#include "Search.inl"
