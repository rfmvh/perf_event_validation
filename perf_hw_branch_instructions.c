/* FIXME
 */

#include "testcode.h"
#include "testlib.h"
#include "display_error.h"
#include "perflib.h"

#include <stdlib.h>
#include <stdio.h>

#define EVENT PERF_COUNT_HW_BRANCH_INSTRUCTIONS

static int quiet = 0;

int main(int argc, char *argv[])
{
	int i, num_runs = 100;
	int ins_result;
	long long high = 0, low = 0, average = 0, expected = 1500000;
	long long count, total = 0;
	int pass = 1;
	double error;

	int fd;

	if (!quiet)
		printf("Testing PERF_COUNT_HW_BRANCH_INSTRUCTIONS event.\n");

	fd = perflib_event_setup(EVENT, PERFLIB_THIS_PROCESS, PERFLIB_ALL_CPUS);
	if (fd == -1) {
		fprintf(stderr, "Error opening event %llx\n", EVENT);
		exit(EXIT_FAILURE);
	}

	if (!quiet)
		printf("Testing a loop with %lld branches (%d times):\n", expected, num_runs);

	for(i = 0; i < num_runs; i++)
	{
		/* start counting */
		perflib_event_restart(fd);

		/* do the load */
		ins_result = branches_testcode();

		/* stop and read value */
		perflib_event_stop(fd);
		count = perflib_event_read(fd);

		if(count > high)
			high = count;
		if((count < low) || (low == 0))
			low = count;
		total += count;
	}

	perflib_event_deinit(fd);

	average = total / num_runs;
	error = display_error(average, high, low, expected, quiet);

	if((error > 1.0) || (error < -1.0))
	{
		if(!quiet)
			printf("Branch instruction count off by more than 1%%\n");
		test_fail(__FILE__, __LINE__, "Error too high", 1);
	}

	if(!quiet)
		printf("\n");

	test_pass(__FILE__);
	return 0;
}
