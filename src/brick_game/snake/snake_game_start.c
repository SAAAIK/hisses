#include "snake_game_start.h"

// ==========Функция - инициализация игрового поля
void initGame(GameInfo_t *gameInfo) {
  // Динамическое выделение памяти для игрового поля
  gameInfo->field = malloc(BOARD_HEIGHT * sizeof(int *));
  for (int i = 0; i < BOARD_HEIGHT; i++) {
    gameInfo->field[i] = malloc(BOARD_WIDTH * sizeof(int));
    memset(gameInfo->field[i], 0,
           BOARD_WIDTH * sizeof(int)); // Инициализация нулями
  }

  gameInfo->snake_p = malloc(MAX_LENGTH * sizeof(int));
  memset(gameInfo->snake_p, 0, MAX_LENGTH * sizeof(int));

  gameInfo->level = 1;
  gameInfo->speed = 1; // Начальная скорость
  gameInfo->pause = 0; // Игра не на паузе

// инициализируем змейку
init_snake(gameInfo);
}

// инициализация змейки
void init_snake(GameInfo_t *gameInfo) {
    gameInfo->snake.length = 4; //начинаем с длины 4
    for (int i = 0; i < gameInfo->snake.length; i++) {
        gameInfo->snake.segments[i].x = BOARD_WIDTH/2 - i; // горизонтально вправо или влево
        gameInfo->snake.segments[i].y = BOARD_HEIGHT/2;
    }
    gameInfo->snake.dir_x = 1; // начальное направление вправо
    gameInfo->snake.dir_y = 0;
}

// Обновление поля и вывод
void print_field(GameInfo_t *gameInfo, Snake *snake) {
    // Заполняем поле точками
    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            gameInfo->field[y][x] = '+';
        }
    }

    // Отмечаем сегменты змейки тире '-'
    for (int i = 0; i < snake->length; i++) {
        int x = snake->segments[i].x;
        int y = snake->segments[i].y;

        // Проверка границ поля
        if (x >= 0 && x < BOARD_WIDTH && y >= 0 && y < BOARD_HEIGHT) {
            gameInfo->field[y][x] = '-';
        }
    }

    // Вывод поля построчно
    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            printf("%c", gameInfo->field[y][x]);
        }
        printf("\n");
    }
}

// движение змейки вперед при отсутствии ввода от пользователя
void move_snake(GameInfo_t *gameInfo) {
    // Сдвигаем сегменты: начиная с хвоста к голове
    for (int i = gameInfo->snake.length - 1; i > 0; i--) {
        gameInfo->snake.segments[i] = gameInfo->snake.segments[i -1];
    }
    // Обновляем голову в соответствии с направлением
    gameInfo->snake.segments[0].x += gameInfo->snake.dir_x;
    gameInfo->snake.segments[0].y += gameInfo->snake.dir_y;
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