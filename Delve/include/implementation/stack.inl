#include "..\stack.hpp"

namespace Delve
{
namespace Structure
{
template<typename T, size_t N>
inline T Stack<T, N>::pop() noexcept
{
	if (Elements)
	{
		Elements--;
		return array[Elements];
	}
	else
	{
		return array[Elements];
	}
}
template<typename T, size_t N>
inline T Stack<T, N>::peek() noexcept
{
	return array[Elements];
}
template<typename T, size_t N>
inline void Stack<T, N>::push(T data) noexcept
{
	if (Elements < N)
	{
		Element++;
		array[Elements] = data;
	}
}
template<typename T, size_t N>
inline T Stack<T, N>::front() noexcept
{
	return array[0];
}
template<typename T, size_t N>
inline T* Stack<T, N>::data() noexcept
{
	return array;
}
} // namespace Structure
} // namespace Delve
