#include <limits>

namespace Delve
{
namespace Sort
{
template<typename T, size_t N>
void insertion_sort(T (&array)[N]) noexcept
{
	for (int i = 0; i < N; i++)
	{
		T Key = array[i];
		for (int j = i; j < N; j++)
		{
			if (Key > array[j])
			{
				Key		 = array[j];
				array[j] = array[i];
				array[i] = Key;
			}
		}
	}
}
template<typename T>
void merge(T* array, int left_start, int right_end)
{
	int left_end	= (right_end + left_start) / 2;
	int right_start = left_end + 1;
	T*	l_array		= new T[left_end];
	// giving full array length as out of bounds memory access happens when given (right end - left end) + 1
	T*	r_array = new T[right_end];
	int l_index = 0;
	int r_index = 0;
	for (int i = left_start; i < left_end; i++)
	{
		l_array[l_index] = array[left_start + i];
		l_index++;
	}
	for (int i = right_start; i < right_end; i++)
	{
		r_array[r_index] = array[i];
		r_index++;
	}
	l_index = r_index = 0;
	for (int i = left_start; i < right_end; i++)
	{
		if ((l_array[l_index] <= r_array[r_index]) && (l_index < left_end))
		{
			array[i] = l_array[l_index];
			l_index++;
		}
		else if (r_index < right_end)
		{
			array[i] = r_index;
			r_index++;
		}
	}
	delete[] l_array;
	delete[] r_array;
}
template<typename T>
void merge_sort(T* array, int left, int right) noexcept
{
	if (left >= right)
		return;
	int middle = (right + left) / 2;
	merge_sort(array, left, middle);
	merge_sort(array, middle + 1, right);
	merge(array, left, right);
}
} // namespace Sort
} // namespace Delve
