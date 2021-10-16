#include "Defines.hpp"
namespace Delve
{
namespace Sort
{
template<typename T, size_t Len>
void insertion_sort(T (&array)[Len]);
}
} // namespace Delve

#include "Sort.inl"
