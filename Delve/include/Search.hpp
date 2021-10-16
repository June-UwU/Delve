#pragma once
#include "Defines.hpp"

namespace Delve
{
namespace Search
{
template<typename T, size_t Len>
int linear_search(const T (&array)[Len], const T Key);
template<typename T, size_t Len>
int binary_search(const T (&array)[Len], const T Key);
} // namespace Search

} // namespace Delve

#include "Search.inl"
