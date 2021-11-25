#pragma once
#include <cstring>
#include <limits>
#include "Defines.hpp"
namespace Delve
{
namespace algo
{
template<typename T>
T max_subarray_kadane(T* array, size_t size) noexcept;

} // namespace algo
} // namespace Delve

#include "implementation/Algo.inl"
