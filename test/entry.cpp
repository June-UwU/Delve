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
	int	   array_1[]{ 2, 1, 0, -1, -2, 4, 3, -2, 3, 5, 3, 76, 4, 72, 0, 3, 1, 3, 57, 3 };
	bool   relativity = true;
	size_t size		  = std::size(array_1);
	Delve::Sort::insertion_sort(array_1, size);
	for (int i = 0; i < size - 1; i++)
	{
		if (array_1[i] > array_1[i + 1])
		{
			relativity = false;
		}
	}
	ASSERT_TRUE(relativity);
}

TEST(sort, merge_sort)
{
	int	   array_1[]{ 2, 1, 0, -1, -2, 4, 3, -2, 3, 5, 3, 76, 4, 72, 0, 3, 1, 3, 57, 3 };
	bool   relativity = true;
	size_t size		  = std::size(array_1);
	Delve::Sort::merge_sort(array_1, 0, size, size);
	for (int i = 0; i < size - 1; i++)
	{
		if (array_1[i] > array_1[i + 1])
		{
			relativity = false;
		}
	}
	ASSERT_TRUE(relativity);
}

TEST(algorithm, kadane_max_sub_array)
{
	int	 array_1[]{ -1, -2, -3, -4, -5, 6, 7 };
	auto ret = Delve::algo::max_subarray_kadane(array_1, std::size(array_1));
	ASSERT_TRUE(ret == 13);
}

TEST(structures, Heap)
{
	int						array_1[]{ -1, -2, -3, -4, -5, 6, 7 };
	Delve::Structures::Heap Heap_1 = Delve::Structures::Heap<int, std::size(array_1)>(array_1);
	Delve::Structures::Heap Heap_2(Heap_1);
	Delve::Structures::Heap Heap_3 = Heap_1;

	// how do I check for move assignment and how do I test if it worked as expected
	/*ASSERTIONS AND CHECKING */
	ASSERT_TRUE(memcmp(array_1, Heap_1.get(), Heap_1.size() * sizeof(int)) == 0); // pointer / array constructor test
	ASSERT_TRUE(memcmp(array_1, Heap_2.get(), Heap_2.size() * sizeof(int)) == 0); // copy constructor
	ASSERT_TRUE(memcmp(array_1, Heap_2.get(), Heap_3.size() * sizeof(int)) == 0); // copy assignment
	ASSERT_TRUE(Heap_1.get_left_child(0) == array_1[1]);						  // checking proper left child
	ASSERT_TRUE(Heap_1.get_right_child(0) == array_1[2]);						  // checking proper right child
	ASSERT_TRUE(Heap_1.get_parent(1) == array_1[0]);							  // checking proper parent
	ASSERT_TRUE(Heap_1.get_parent(2) == array_1[0]);							  // checking proper parent
	ASSERT_TRUE(Heap_1.get_parent(3) == array_1[1]);							  // checking proper parent
	ASSERT_TRUE(Heap_1.get_parent(4) == array_1[1]);							  // checking proper parent
	ASSERT_TRUE(Heap_1.get_parent(0) == std::numeric_limits<int>::max());		  // checking specified behaviour
	// check for invalid child needs to be done
}


int main(int argc, char** argv)
{
	// TODO :write test for heap class and debug all functions and utils
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
