#include "..\Dynamic_set.hpp"

namespace Delve
{
namespace structure
{
template<typename T>
inline Dynamic_set<T>::Dynamic_set(T data) noexcept
{
	first				 = static_cast<elements*>(malloc(sizeof(elements)));
	first->satelite_data = data;
}
template<typename T>
inline Dynamic_set<T>::Dynamic_set(Dynamic_set& rhs) noexcept
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

template<typename T>
inline Dynamic_set<T>::Dynamic_set(Dynamic_set&& rhs) noexcept
{
	first		= rhs.front();
	rhs.front() = nullptr;
}

template<typename T>
inline void Dynamic_set<T>::insert(T data) noexcept
{
	if (first == nullptr)
	{
		first				 = static_cast<elements*>(malloc(sizeof(elements)));
		first->satelite_data = data;
		first->next			 = nullptr;
		return;
	}
	elements* temp = first;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next			= static_cast<elements*>(malloc(sizeof(elements)));
	temp				= temp->next;
	temp->satelite_data = data;
	temp->next			= nullptr;
}

template<typename T>
inline void Dynamic_set<T>::remove(elements* del) noexcept
{
	delete del;
}

template<typename T>
inline T Dynamic_set<T>::get_satelite_data() noexcept
{
	return first->satelite_data;
}

template<typename T>
inline void Dynamic_set<T>::pop_front()
{
	auto temp = first;
	first	  = first->next;
	delete temp;
}

} // namespace structure
} // namespace Delve
