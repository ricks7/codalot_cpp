CC=gcc
CXX=g++
CXXFLAGS=-g -Wall
CFLAGS=-g -Wall
LDFLAGS=-g -Wall

.PHONY: build all test run clean
build: src/main test/codalot_test

all: clean build

test: test/codalot_test
	test/codalot_test

run: src/main
	src/main

clean:
	rm -rf src/*.o src/a.exe src/a.out src/main.exe src/main
	rm -rf test/*.o test/a.exe test/a.out test/codalot_test.exe test/codalot_test
	rm -rf *.o a.out a.exe main main.exe codalot_test codalot_test.exe

test/codalot_test:

src/main:
