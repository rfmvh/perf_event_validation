CC=gcc
CFLAGS=
LINKERFLAGS=-L../lib -L../loads
INCLUDEFLAGS=-I../lib -I../loads
OBJFILES=../lib/*.o ../loads/*.o

.PHONY: all clean

SRCS=$(wildcard *.c)
BINS=$(patsubst %.c,%,$(SRCS))

all: $(BINS)

%: %.c
	$(CC) $(CFLAGS) $(LINKERFLAGS) $(INCLUDEFLAGS) $(OBJFILES) -o $@ $<

clean:
	rm -f $(BINS)
