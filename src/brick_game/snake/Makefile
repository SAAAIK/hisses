all:
	gcc -Wall -Werror -Wextra snake_game_start.c main.c -lncurses
	./a.out

spec:
	rm -f ./a.out
	gcc -Wall -Werror -Wextra controller.c model.c interface.c -lncurses
	./a.out

spec_1:
	rm -f ./a.out
	gcc -Wall -Werror -Wextra controller.c model.c -lncurses
	./a.out