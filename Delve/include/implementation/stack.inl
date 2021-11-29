#include "..\stack.hpp"

namespace Delve
{
namespace structure
{
template<typename T, size_t N>
inline Stack<T, N>::Stack(Stack& rhs) noexcept
{
	memcpy(array, rhs.data(), rhs.size() * sizeof(T));
}
template<typename T, size_t N>
inline Stack<T, N>::Stack(Stack&& rhs) noexcept
{
	memcpy(array, rhs.data(), rhs.size() * sizeof(T));
	rhs.data() = nullptr;
}

template<typename T, size_t N>
inline T Stack<T, N>::pop() noexcept
{
	if (Elements)
	{
		return array[Elements - 1];
		Elements--;
	}
	else
	{
		return array[Elements];
	}
}
template<typename T, size_t N>
inline T Stack<T, N>::peek() noexcept
{
	return array[Elements - 1];
}
template<typename T, size_t N>
inline void Stack<T, N>::push(T data) noexcept
{
	if (Elements < N)
	{
		array[Elements] = data;
		Elements++;
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
} // namespace structure
} // namespace Delve
