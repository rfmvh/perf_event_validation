CC=gcc

.PHONY: all clean

all:	perf_hw_branch_instructions

clean:
	rm -f *.o perf_hw_branch_instructions

display_error.o:	display_error.c display_error.h
	$(CC) -o display_error.o -c display_error.c

perflib.o:	perflib.c perflib.h
	$(CC) -o perflib.o -c perflib.c

testlib.o:	testlib.c testlib.h
	$(CC) -o testlib.o -c testlib.c

testcode.o:	branches_testcode.c testcode.h
	$(CC) -o testcode.o -c branches_testcode.c

perf_hw_branch_instructions:	perf_hw_branch_instructions.c display_error.o perflib.o testlib.o testcode.o
	$(CC) -o perf_hw_branch_instructions display_error.o perflib.o testlib.o testcode.o perf_hw_branch_instructions.c
