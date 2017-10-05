#include "perflib.h"

static int perf_event_open(struct perf_event_attr *hw_event, pid_t pid, int cpu, int group_fd, unsigned long flags)
{
	return syscall(__NR_perf_event_open, hw_event, pid, cpu, group_fd, flags);
}

int perflib_event_setup(unsigned int event, int pid, int cpu)
{
	struct perf_event_attr pe;
	if((cpu == PERFLIB_ALL_CPUS) && (pid == PERFLIB_ALL_PROCESSES))
		return -1;

	memset(&pe, 0, sizeof(struct perf_event_attr));

	pe.type = PERF_TYPE_HARDWARE;
	pe.size = sizeof(struct perf_event_attr);
	pe.config = event;
	pe.disabled = 1;
	pe.exclude_kernel = 1;
	pe.exclude_hv = 1;
	
	return perf_event_open(&pe, pid, cpu, -1, 0);
}


void perflib_event_start(int fd)
{
	ioctl(fd, PERF_EVENT_IOC_ENABLE, 0);
}


void perflib_event_restart(int fd)
{
	ioctl(fd, PERF_EVENT_IOC_RESET, 0);
	ioctl(fd, PERF_EVENT_IOC_ENABLE, 0);
}


void perflib_event_reset(int fd)
{
	ioctl(fd, PERF_EVENT_IOC_RESET, 0);
}


void perflib_event_stop(int fd)
{
	ioctl(fd, PERF_EVENT_IOC_DISABLE, 0);
}


long long perflib_event_read(int fd)
{
	long long a;
	read(fd, &a, sizeof(long long));
	return a;
}


void perflib_event_deinit(int fd)
{
	close(fd);
}
