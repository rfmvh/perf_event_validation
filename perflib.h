#ifndef __PERFLIB_H__
#define __PERFLIB_H__

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <linux/perf_event.h>
#include <asm/unistd.h>

#define PERFLIB_ALL_CPUS -1

#define PERFLIB_THIS_PROCESS 0
#define PERFLIB_ALL_PROCESSES -1

/* setup an event, returns a fd */
int perflib_event_setup(unsigned int event, int pid, int cpu);

/* start measuring and reset the counter before */
void perflib_event_restart(int fd);

/* start measuring without reseting (should not be used without a business reason) */
void perflib_event_start(int fd);

/* reset counters without stopping */
void perflib_event_reset(int fd);

/* stop the counters */
void perflib_event_stop(int fd);

/* read value of a counter */
long long perflib_event_read(int fd);

/* close the fd*/
void perflib_event_deinit(int fd);

#define __PERFLIB_H__
#endif
