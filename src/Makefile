CC = g++
CC_FLAGS = -Wall -Werror -Wextra -std=c++17
LIB_NAME = s21_matrix_oop
CODE_PATH = ./code
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


dvi: 


dist: 


test:


rebuild:

run: ./protytype/main.cpp
	$(CC) $(CC_FLAGS) -lgtest -lgmock -pthread ./protytype/main.cpp ./brick_game/snake/model.cpp -o ./protytype/main
	./protytype/main