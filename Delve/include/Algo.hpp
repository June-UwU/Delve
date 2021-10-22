#pragma once
#include "Defines.hpp"
namespace Delve
{
namespace algo
{
template<typename T, size_t N>
array_return<T> max_subarray_brute(T (&array)[N]);

template<typename T, size_t N>
array_return<T> min_subarray_brute(T (&array)[N]);

} // namespace algo
} // namespace Delve

#include "Algo.inl"
