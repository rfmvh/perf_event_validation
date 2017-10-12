CC=gcc
CFLAGS=

.PHONY: all clean

SRCS=$(wildcard *.c)
OBJS=$(patsubst %.c,%.o,$(SRCS))

all: $(OBJS)

%.o: %.c testcode.h
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f *.o
