CC=gcc
CFLAGS=-I./brick_game/tetris -I./gui/cli -std=c11
LDFLAGS=-L./brick_game/tetris -ltetris_game -lncurses
CHECK_FLAGS=$(shell pkg-config --cflags --libs check)
GCOV_FLAGS=-fprofile-arcs -ftest-coverage

# Определение библиотек для тестов в зависимости от ОС
OS := $(shell uname -s)
ifeq ($(OS), Darwin)
	TEST_LIBS = -lcheck -lm -lpthread
else
	TEST_LIBS = -lcheck -lsubunit -pthread -lrt -lm
endif

# Исходные файлы и исполняемые файлы
CLI_SOURCES=gui/cli/main.c gui/cli/interface.c gui/cli/user_input.c gui/cli/top_score.c
EXEC=tetris_game
TEST_SOURCES=tests/unit_tests.c tests/tests.c
TEST_EXEC=run_tests

.PHONY: all clean libtetris_game test gcov_report

all: libtetris_game $(EXEC)

libtetris_game:
	$(CC) $(CFLAGS) -c brick_game/tetris/tetris_game.c -o brick_game/tetris/tetris_game.o
	ar rcs brick_game/tetris/libtetris_game.a brick_game/tetris/tetris_game.o

$(EXEC): $(CLI_SOURCES)
	$(CC) $(CFLAGS) $(CLI_SOURCES) $(LDFLAGS) -o $(EXEC)

test: libtetris_game
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $(TEST_SOURCES) brick_game/tetris/tetris_game.c -o $(TEST_EXEC) $(LDFLAGS) $(CHECK_FLAGS) $(TEST_LIBS)
	./$(TEST_EXEC)

gcov_report: test
	rm -rf report
	mkdir report
	gcovr -r . --html --html-details -o report/gcov_report.html --exclude tests/
	open report/gcov_report.html

clean:
	rm -f $(EXEC) $(TEST_EXEC)
	rm -f brick_game/tetris/*.o brick_game/tetris/libtetris_game.a
	rm -f *.gcda *.gcno *.o *.html *.css brick_game/tetris/*.gcno
	rm -rf report
	rm -rf build


leaks:
	leaks -atExit -- ./tetris_game

style :
	clang-format --style=google -n brick_game/tetris/*.h brick_game/tetris/*.c gui/cli/*.c gui/cli/*.h

install: all
	mkdir -p build
	cp $(EXEC) build/$(EXEC)

uninstall:
	rm -rf build

dist:
	mkdir -p dist
	tar -cvzf dist/$(DIST_NAME).tar.gz $(DIST_FILES)

dvi:  
ifeq ($(OS), Darwin)
	open ./doc/documentation.md
else
	cat ./doc/documentation.md
endif