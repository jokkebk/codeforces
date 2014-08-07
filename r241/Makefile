CPP=clang++
CFLAGS=-Wall -std=c++0x -stdlib=libc++

all: main

run: main
	./main

main: main.cc
	$(CPP) $(CFLAGS) $< -o $@
