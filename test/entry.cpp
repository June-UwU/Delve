#include "Delve.hpp"
#include <gtest/gtest.h>

TEST(search, linear_search)
{
	int array_1[]{ 0, 1, 2, 3, 4, 5 };
	int array_2[]{ 0, 1, 2 };
	ASSERT_EQ(2, Delve::Search::linear_search(array_1, 2));
	ASSERT_EQ(-1, Delve::Search::linear_search(array_1, 8));

	/*Interesting behaviour from templates*/
	// sort of expected but since there is two parameter for the template function it depends on both ,
	// the type can be deduced by parameter deductions but a rather interesting fact it that the language
	// deduces the sizeof the array passed for a clean implicit function generation..that's cool...
	ASSERT_EQ(-1, Delve::Search::linear_search(array_2, 8));
}

TEST(search, binary_search)
{
	int array_1[]{ 0, 1, 2, 3, 4, 5 };
	ASSERT_EQ(2, Delve::Search::binary_search(array_1, 2));
	ASSERT_EQ(-1, Delve::Search::binary_search(array_1, 8));
}

TEST(sort, linear_sort)
{
	int array_1[]{ 5, 4, 3, 2, 1, 0 };
	int array_2[]{ 5, 4, 3, 2, 1, 0 };
	int check_1[]{ 0, 1, 2, 3, 4, 5 };
	Delve::Sort::insertion_sort(array_1);
	Delve::Sort::insertion_sort(array_2, std::size(array_2));
	ASSERT_EQ(0, std::memcmp(array_2, check_1, sizeof(array_1)));
	ASSERT_EQ(0, std::memcmp(array_1, check_1, sizeof(array_1)));
}

TEST(sort, merge_sort)
{
	int array_1[]{ 2, 1, 0, -1, -2 ,4,3,-2,3,5,3,76,4,72,0,3,1,3,57,3};
	bool   relativity = true;
	size_t size = std::size(array_1);
	Delve::Sort::merge_sort(array_1, 0, size,size);
	for (int i = 0; i < size-1; i++)
	{
		if (array_1[i] > array_1[i+1])
		{
			relativity = false;
		}
	}
	ASSERT_TRUE(relativity);
}

TEST(subarray, max_subarray_brute)
{
	int	 array_1[]{ 5, 4, -3, 2, 1, 1 };
	int	 check_1[]{ 5, 4, 2, 1, 1 };
	auto ret = Delve::algo::max_subarray_brute(array_1);
	ASSERT_EQ(0, std::memcmp(ret.ptr, check_1, sizeof(int) * ret.size));
}

TEST(subarray, min_subarray_brute)
{
	int	 array_1[]{ 5, 4, -3, 2, 1, 1 };
	int	 check_1[]{ -3 };
	auto ret = Delve::algo::min_subarray_brute(array_1);
	ASSERT_EQ(0, std::memcmp(ret.ptr, check_1, sizeof(int) * ret.size));
}

// TEST(subarray, max_subarray_dac)
//{
//	int array_1[]{ 5, 4, -3, 2, 1, 1 };
//	auto ret = Delve::algo::max_subarray_dac(array_1, 0, std::size(array_1));
//	//for (size_t i = 0;i<ret.size;i++)
//	//{
//	//	std::cout << ret.ptr[i] << "\t";
//	//}
//	std::cout << ret.size;
//}

int main(int argc, char** argv)
{
	// TODO :write test for heap class and debug all functions and utils
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
