
namespace Delve
{
namespace Sort
{
template<typename T, size_t Len>
void insertion_sort(T (&array)[Len])
{
	for (int i = 0; i < Len; i++)
	{
		T Key = array[i];
		for (int j = i; j < Len; j++)
		{
			if (Key > array[j])
			{
				Key		 = array[j];
				array[j] = array[i];
				array[i] = Key;
			}
		}
	}
};

} // namespace Sort
} // namespace Delve
