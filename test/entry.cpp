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

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
