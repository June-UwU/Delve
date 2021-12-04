#pragma once

namespace Delve
{
namespace structure
{
template<typename T>
class Dynamic_set
{
public:
	struct elements
	{
		elements* next = nullptr;
		T		  satelite_data;
	};

	Dynamic_set() = default;
	Dynamic_set(T data) noexcept;
	Dynamic_set(Dynamic_set& rhs) noexcept;
	Dynamic_set(Dynamic_set&& rhs) noexcept;
	Dynamic_set operator=(Dynamic_set& rhs) noexcept
	{
		first				  = static_cast<elements*>(malloc(sizeof(elements)));
		first->statelite_data = rhs.get_satelite_data();
		elements* ptr		  = nullptr;
		if (first->next)
		{
			ptr = rhs.front()->next;
		}
		elements* next = static_cast<elements*>(malloc(sizeof(elements)));
		first->next	   = next;
		while (ptr)
		{
			next->data	   = ptr->data;
			ptr			   = ptr->next;
			elements* temp = static_cast<elements*>(malloc(sizeof(elements)));
			next->next	   = temp;
		}
		free(next->next);
	}
	Dynamic_set operator=(Dynamic_set&& rhs) noexcept
	{
		first		= rhs.front();
		rhs.front() = nullptr;
	}
	elements* search(T key) noexcept
	{
		elements* temp = first;
		if (first->satelite_data == key)
		{
			return temp;
		}
		while (temp->next)
		{
			temp = temp->next;
			if (temp->satelite_data == key)
			{
				return temp;
			}
		}
		return nullptr;
	}
	void	  insert(T data) noexcept;
	void	  remove(elements* del) noexcept;
	elements* maximum() noexcept
	{
		if (first == nullptr)
		{
			return nullptr;
		}
		elements* max  = first;
		elements* temp = first;
		while (temp != nullptr)
		{
			if (max->satelite_data < temp->satelite_data)
			{
				max = temp;
			}
			temp = temp->next;
		}
		return max;
	}
	elements* minimum() noexcept
	{
		if (first == nullptr)
		{
			return nullptr;
		}
		elements* min  = first;
		elements* temp = first;
		while (temp != nullptr)
		{
			if (min->satelite_data > temp->satelite_data)
			{
				min = temp;
			}
			temp = temp->next;
		}
		return min;
	}
	T		  get_satelite_data() noexcept;
	elements* front() noexcept { return first; };
	void	  pop_front();

private:
	elements* first = nullptr;
};

} // namespace structure
} // namespace Delve
#include "implementation/Dynamic_set.inl"
