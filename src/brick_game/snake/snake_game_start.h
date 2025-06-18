#ifndef S21_SNAKE_GAME_START_H
#define S21_SNAKE_GAME_START_H

// Размер игрового поля
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
// Интервал в миллисекундах для автоматического сдвига змейки вперед
#define DROP_INTERVAL 2000000. 
// Максимальная длинна
#define MAX_LENGTH 200

#include <ncurses.h>
#include <stdbool.h> // Для использования bool
#include <stdio.h>
#include <stdlib.h> // для rand() и srand()
#include <string.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Segment;

typedef struct {
    Segment segments[MAX_LENGTH];
    int length; // текущая длина змейки
    int dir_x; // направление по x (-1,0,1)
    int dir_y; // направление по y (-1,0,1)
} Snake;

void init_snake(Snake *snake, int start_x, int start_y); // инициализация змейки
void print_field(const Snake *snake); // отрисовка поля
#endif