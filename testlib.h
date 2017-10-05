#ifndef __TESTLIB_H__  

#include <stdlib.h>
#include <stdio.h>

void test_pass(const char *filename);
void test_fail(const char *filename, const line, const char *msg, int retval);

#define __TESTLIB_H__  
#endif
