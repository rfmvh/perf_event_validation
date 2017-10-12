.PHONY: all clean

all: build

clean:
	make -C lib clean
	make -C loads clean
	make -C tests clean

build:
	make -C lib
	make -C loads
	make -C tests

