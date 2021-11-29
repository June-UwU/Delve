#pragma once

namespace Delve
{
namespace structure
{
template<typename T, size_t N>
class Stack
{
	using type = T;
public:
	Stack() = default;
	Stack(Stack& rhs) noexcept;
	Stack(Stack&& rhs) noexcept;
	Stack operator=(Stack& rhs) noexcept { memcpy(array, rhs.data(), rhs.size() * sizeof(Stack::type)); }
	Stack operator=(Stack&& rhs) noexcept
	{
		memcpy(array, rhs.data(), rhs.size() * sizeof(Stack::type));
		rhs.data() = nullptr;
	}
	T	   pop() noexcept;
	T	   peek() noexcept;
	void   push(T data) noexcept;
	T	   front() noexcept;
	T*	   data() noexcept;
	size_t size() { return N; }

private:
	T	   array[N];
	size_t Elements = 0;
};

} // namespace structure
} // namespace Delve

#include "implementation/stack.inl"
