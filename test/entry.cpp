#include <iostream>
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
	Delve::Sort::merge_sort<int>(array_1, size);
	for (int i = 0; i < size - 1; i++)
	{
		if (array_1[i] > array_1[(i + 1)])
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

TEST(sort, heap_sort)
{
	int	   array_1[]{ 2, 1, 0, -1, -2, 4, 3, -2, 3, 5, 3, 76, 4, 72, 0, 3, 1, 3, 57, 3 };
	bool   relativity = true;
	size_t size		  = std::size(array_1);
	Delve::Sort::heap_sort(array_1, size);
	for (int i = 0; i < size - 1; i++)
	{
		if (array_1[i] > array_1[i + 1])
		{
			relativity = false;
		}
	}
	ASSERT_TRUE(relativity);
}

TEST(sort, counting_sort)
{
	int	   array_1[]{ 2, 1, 0, -1, -2, 4, 3, -2, 3, 5, 3, 76, 4, 72, 0, 3, 1, 3, 57, 3 };
	bool   relativity = true;
	size_t size		  = std::size(array_1);
	auto   ret		  = Delve::Sort::counting_sort_ret(array_1, size);
	for (int i = 0; i < size - 1; i++)
	{
		if (ret[i] > ret[i + 1])
		{
			relativity = false;
		}
	}
	ASSERT_TRUE(relativity);
}

TEST(structures, array_stack)
{
	Delve::structure::Stack<int, 5> stack_1;
	stack_1.push(1);
	stack_1.push(2);
	Delve::structure::Stack<int, 5> stack_2(stack_1);
	ASSERT_TRUE(!memcmp(stack_1.data(), stack_2.data(), stack_1.size() * sizeof(int)));
	ASSERT_TRUE(stack_1.data()[0] == stack_1.front());
	auto peekvar = stack_1.peek();
	auto popvar	 = stack_1.pop();
	ASSERT_TRUE(peekvar == popvar);
}

TEST(sort, quick_sort)
{
	int	   array_1[]{ 2, 1, 0, -1, -2, 4, 3, -2, 3, 5, 3, 76, 4, 72, 0, 3, 1, 3, 57, 3 };
	bool   relativity = true;
	size_t size		  = std::size(array_1);
	Delve::Sort::quick_sort(array_1, 0, size - 1);
	for (int i = 0; i < size - 1; i++)
	{
		if (array_1[i] > array_1[i + 1])
		{
			relativity = false;
		}
	}
	ASSERT_TRUE(relativity);
}

TEST(structures, dynamic_set)
{
	int								   check_array[]{ 1, 2, 3, 4, 5 };
	size_t							   arraysize = std::size(check_array);
	Delve::structure::Dynamic_set<int> set;
	ASSERT_TRUE(set.front() == nullptr);
	for (size_t i = 0; i < arraysize; i++)
	{
		set.insert(check_array[i]);
	}
	bool relativity = true;
	for (size_t i = 0; i < arraysize; i++)
	{
		std::cout << set.get_satelite_data() << '\n';
		if (set.get_satelite_data() != check_array[i])
		{
			relativity = false;
			break;
		}
		set.pop_front();
	}
	ASSERT_TRUE(relativity);
}

int main(int argc, char** argv)
{
	// TODO :write test for heap class and debug all functions and utils
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
