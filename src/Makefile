.PHONY: clean
CC=gcc
CFLAGS = -lstdc++ -std=c++17
TESTFLAGS = -lgtest
TEST = testing/test.cc
SOURCE = model/*cc
OBJECTS = *.o
all: build static

build:
	$(CC) $(CFLAGS) -c $(SOURCE)

static: build
	ar rc s21_mlp.a $(OBJECTS)
	ranlib s21_mlp.a
tests: static
	$(CC) $(CFLAGC) $(TESTFLAGS) $(TEST) s21_mlp.a -o TEST
run_test: tests
	./TEST
clean:
	rm -rf $(OBJECTS)