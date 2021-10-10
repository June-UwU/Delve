#pragma once
#include "Defines.hpp"

namespace Delve
{
namespace Search
{
template<typename T, size_t Len>
DELVE int linear_search(const T (*array)[Len], const T Key);
template<typename T>
DELVE int linear_search(const T(*array), const T Key);
template<typename T, size_t Len>
DELVE int binary_search(const T (*array)[Len], const T Key);

template<typename T>
DELVE int binary_search(const T(*array), const T Key);
} // namespace Search
} // namespace Delve

#include "Search.inl"
