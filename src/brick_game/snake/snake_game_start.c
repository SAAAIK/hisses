#include "snake_game_start.h"

void init_snake(Snake *snake, int start_x, int start_y) {
    snake->length = 4; //начинаем с длины 4
    for (int i = 0; i < snake->length; i++) {
        snake->segments[i].x = start_x - i; // горизонтально вправо или влево
        snake->segments[i].y = start_y;
    }
    snake->dir_x = 1; // начальное направление вправо
    snake->dir_y = 0;
}

// Обновление поля и вывод
void print_field(const Snake *snake) {
    char field[BOARD_HEIGHT][BOARD_WIDTH];

    // Заполняем поле точками
    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            field[y][x] = '.';
        }
    }

    // Отмечаем сегменты змейки тире '-'
    for (int i = 0; i < snake->length; i++) {
        int x = snake->segments[i].x;
        int y = snake->segments[i].y;

        // Проверка границ поля
        if (x >= 0 && x < BOARD_WIDTH && y >= 0 && y < BOARD_HEIGHT) {
            field[y][x] = '-';
        }
    }

    // Вывод поля построчно
    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            printf("%c", field[y][x]);
        }
        printf("\n");
    }
}

void move_snake(Snake *snake) {
    // Сдвигаем сегменты: начиная с хвоста к голове
    for (int i = snake->length - 1; i > 0; i--) {
        snake->segments[i] = snake->segments[i -1];
    }
    // Обновляем голову в соответствии с направлением
    snake->segments[0].x += snake->dir_x;
    snake->segments[0].y += snake->dir_y;
}

void change_direction(Snake *snake, int new_dir_x, int new_dir_y) {
    // Можно добавить проверку на противоположность направления,
    // чтобы не развернуться на месте.
    if ((new_dir_x == -snake->dir_x && new_dir_y == -snake->dir_y)) {
        return; // запрещено разворачиваться на месте
    }
    snake->dir_x = new_dir_x;
    snake->dir_y = new_dir_y;
}

void grow_snake(Snake *snake) {
    if (snake->length < MAX_LENGTH) {
        // добавляем новый сегмент в конец (можно просто копировать последний сегмент)
        snake->segments[snake->length] = snake->segments[snake->length -1];
        snake->length++;
    }
}

// void printField(GameInfo_t *gameInfo) {
//   // Отрисовка верхней границы поля
//   for (int x = -1; x <= BOARD_WIDTH * 2; x++) {
//     mvprintw(0, x + 1, "-");
//   }
//   for (int y = 0; y < BOARD_HEIGHT; y++) {
//     // Отрисовка левой границы поля
//     mvprintw(y + 1, 0, "]");

//     for (int x = 0; x < BOARD_WIDTH; x++) {
//       // Используем символ '#' для заполненной ячейки и пробел для пустой
//       mvprintw(y + 1, x * 2 + 1, "%c", gameInfo->field[y][x] ? '#' : ' ');
//     }

//     // Отрисовка правой границы поля
//     mvprintw(y + 1, BOARD_WIDTH * 2 + 1, "[");
//   }

//   // Отрисовка нижней границы поля
//   for (int x = -1; x <= BOARD_WIDTH * 2; x++) {
//     mvprintw(BOARD_HEIGHT + 1, x + 1, "-");
//   }
// }