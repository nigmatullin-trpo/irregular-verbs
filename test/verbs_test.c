#include "verbs.c"
#include "ctest.h"

const int amount = 100;

CTEST(mark_suite, below_zero_test)
{
	const int result = write_mark(amount, -1);
	const int expected = 0;
	ASSERT_EQUAL(expected, result);
}

CTEST(mark_suite, zero_test)
{
	const int result = write_mark(amount, 0);
	const int expected = 0;
	ASSERT_EQUAL(expected, result);
}

CTEST(mark_suite, mark_two_left_test)
{
	const int result = write_mark(amount, 1);
	const int expected = 2;
	ASSERT_EQUAL(expected, result);
}

CTEST(mark_suite, mark_two_right_test)
{
	const int result = write_mark(amount, 35);
	const int expected = 2;
	ASSERT_EQUAL(expected, result);
}

CTEST(mark_suite, mark_three_left_test)
{
	const int result = write_mark(amount, 36);
	const int expected = 3;
	ASSERT_EQUAL(expected, result);
}

CTEST(mark_suite, mark_three_right_test)
{
	const int result = write_mark(amount, 60);
	const int expected = 3;
	ASSERT_EQUAL(expected, result);
}

CTEST(mark_suite, mark_four_left_test)
{
	const int result = write_mark(amount, 61);
	const int expected = 4;
	ASSERT_EQUAL(expected, result);
}

CTEST(mark_suite, mark_four_right_test)
{
	const int result = write_mark(amount, 85);
	const int expected = 4;
	ASSERT_EQUAL(expected, result);
}

CTEST(mark_suite, mark_five_left_test)
{
	const int result = write_mark(amount, 86);
	const int expected = 5;
	ASSERT_EQUAL(expected, result);
}

CTEST(mark_suite, mark_five_right_test)
{
	const int result = write_mark(amount, 100);
	const int expected = 5;
	ASSERT_EQUAL(expected, result);
}

CTEST(mark_suite, over_100_test)
{
	const int result = write_mark(amount, 101);
	const int expected = 0;
	ASSERT_EQUAL(expected, result);
}