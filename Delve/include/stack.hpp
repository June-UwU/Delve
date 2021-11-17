#include "Defines.hpp"

namespace Delve
{
namespace Structure
{
template<typename T, size_t N>
class Stack
{
public:
	Stack() = default;
	T	 pop() noexcept;
	T	 peek() noexcept;
	void push(T data) noexcept;
	T	 front() noexcept;
	T*	 data() noexcept;

private:
	T	   array[N];
	size_t Elements = 0;
};

} // namespace Structure
} // namespace Delve

#include "implementation/stack.inl"
