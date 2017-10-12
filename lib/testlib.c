#include "testlib.h"

void test_pass(const char *filename)
{
	printf("PASSED: %s\n", filename);
	exit(0);
}

void test_fail(const char *filename, const int line, const char *msg, int retval)
{
	printf("FAILED: %s:%d\n%s\n", filename, line, msg);
	exit(1);
}



