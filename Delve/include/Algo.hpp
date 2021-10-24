#pragma once
#include <cstring>
#include <limits>
#include "Defines.hpp"
namespace Delve
{
namespace algo
{
template<typename T, size_t N>
sub_array_ret<T> max_subarray_brute(T (&array)[N]);

template<typename T>
sub_array_ret<T> max_subarray_brute(T* array, size_t N);

template<typename T, size_t N>
sub_array_ret<T> min_subarray_brute(T (&array)[N]);

template<typename T>
sub_array_ret<T> min_subarray_brute(T array, size_t N);

template<typename T>
sub_array_ret<T> max_subarray_dac(T* array, size_t low, size_t high);

} // namespace algo
} // namespace Delve

#include "Algo.inl"
