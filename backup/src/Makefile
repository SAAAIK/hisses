CC = g++
CC_FLAGS = -Wall -Werror -Wextra -std=c++17
LIB_NAME = s21_brickgame_snake
CODE_PATH = ./brick_game/snake/*.cpp  ./protytype/*.cpp 
TESTS_PATH = ./test
# COMMON_PATH = ./common
# BUILD_PATH = ./build
# TEST= tests.sh
TEST_FLAGS = -std=c++17 -g
GCOVFLAGS = -L. -l$(LIB_NAME) --coverage
OS = $(shell uname)

ifeq ($(OS), Linux)
	CHECK_FLAGS = -lgtest -lgmock -pthread
#	CHECK_FLAGS = -lcheck -pthread -lrt -lm
else
	CHECK_FLAGS = -lcheck 
endif

all: 

libsnake_game:
	$(CC) $(CFLAGS) -c brick_game/snake/snake_game.cpp -o brick_game/tetris/tetris_game.o
	ar rcs brick_game/tetris/libtetris_game.a brick_game/tetris/tetris_game.o

install: 


uninstall: 


clean: 
	rm -rf *.o *.g* *.info *.out report *.a *.dSYM debug *.txt $(TESTS_PATH)/make* ./report/*

dvi: 


dist: 


rebuild:

run: ./protytype/main.cpp
	$(CC) $(CC_FLAGS) -lgtest -lgmock -pthread ./protytype/main.cpp ./brick_game/snake/model.cpp -o ./protytype/main
	./protytype/main

TEST_COMPILE = $(CC) $(CC_FLAGS) $(TEST_FLAGS) tests/test*.cpp lib$(LIB_NAME).a $(CHECK_FLAGS) -L. -l$(LIB_NAME)

test: $(LIB_NAME).a
	$(TEST_COMPILE)
	-./a.out
	make clean

$(LIB_NAME).a: $(LIB_NAME).o
	ar rcs lib$(LIB_NAME).a *.o
	rm -rf *.o
	ranlib lib$(LIB_NAME).a
	cp lib$(LIB_NAME).a $(LIB_NAME).a
	cp lib$(LIB_NAME).a l$(LIB_NAME).a

$(LIB_NAME).o:
	$(CC) $(CC_FLAGS) -c $(CODE_PATH)