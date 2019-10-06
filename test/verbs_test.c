#include "verbs.c"
#include "ctest.h"

const int amount = 100;

CTEST(mark_suite, below_zero_test)
{
	const int result = write_mark(amount, -1);
	const int expected = 0;
	ASSERT_EQUAL(expected, result);
}