.PHONY: clean
CC=gcc
CFLAGS=-lstdc++ -std=c++17
CHECKFLAGS=-Wall -Werror -Wextra
TESTFLAGS=-lgtest
TEST= testing/test.cc
SOURCE = model/*cc
OBJECTS = *.o
all: tests

install:
	@make clean
	@mkdir build
	@cd view/ && qmake && make && make clean && rm Makefile  && mv perceptron.app ../build/

uninstall:
	@rm -rf build

dvi:
	@open index.html

dist: install
	@rm -rf Archive_MLP/
	@mkdir Archive_MLP/
	@mkdir Archive_MLP/src
	@mv  ./build/perceptron.app  Archive_MLP/src/
	@tar cvzf Archive_MLP.tgz Archive_MLP/
	@rm -rf Archive_MLP/

tests:
	$(CC) $(CFLAGS) $(TESTFLAGS) model/*.cc matrix/*.cc matrix/*.cpp $(TEST)
	@./a.out

check:
	@cp -r ../materials/linters/.clang-format model/
	@cd model/; clang-format -i *.cc *.h; cd ../
	@cp -r ../materials/linters/.clang-format controller/
	@cd controller/; clang-format -i *.cc *.h; cd ../
	@cp -r ../materials/linters/.clang-format matrix/
	@cd matrix/; clang-format -i *.cc *.h *.cpp; cd ../



clean:
	@rm -rf $(OBJECTS)
	@rm -rf build
	@rm -rf Archive_MLP
	@rm -rf a.out
	@rm -rf Archive_MLP.tgz
