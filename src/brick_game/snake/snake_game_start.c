#include "snake_game_start.h"

// ==========Функция - инициализация игрового поля
void initGame(GameInfo_t *gameInfo)
{
    // Динамическое выделение памяти для игрового поля
    gameInfo->field = malloc(BOARD_HEIGHT * sizeof(int *));
    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        gameInfo->field[i] = malloc(BOARD_WIDTH * sizeof(int));
        memset(gameInfo->field[i], 0,
               BOARD_WIDTH * sizeof(int)); // Инициализация нулями
    }

    gameInfo->snake.segments = malloc(MAX_LENGTH * sizeof(Segment));
    memset(gameInfo->snake.segments, 0, MAX_LENGTH * sizeof(Segment));

    gameInfo->level = 1;
    gameInfo->speed = 1; // Начальная скорость
    gameInfo->pause = 0; // Игра не на паузе

    // инициализируем змейку
    init_snake(gameInfo);
}

// Обновление поля и вывод
void PlacePieceOnField(GameInfo_t *gameInfo, Snake *snake)
{
    // // Заполняем поле точками
    // for (int y = 0; y < BOARD_HEIGHT; y++) {
    //     for (int x = 0; x < BOARD_WIDTH; x++) {
    //         gameInfo->field[y][x] = 0;
    //     }
    // }

    // Отмечаем сегменты змейки тире '-'
    for (int i = 0; i < snake->length; i++)
    {
        int x = snake->segments[i].x;
        int y = snake->segments[i].y;
        // Проверка границ поля
        if (x >= 0 && x < BOARD_WIDTH && y >= 0 && y < BOARD_HEIGHT)
        {
            gameInfo->field[y][x] = 1;
        }
    }

    // // Вывод поля построчно
    // for (int y = 0; y < BOARD_HEIGHT; y++) {
    //     for (int x = 0; x < BOARD_WIDTH; x++) {
    //         printf("%c", gameInfo->field[y][x]);
    //     }
    //     printf("\n");
    // }
}

// инициализация змейки
void init_snake(GameInfo_t *gameInfo){

    gameInfo->snake.length = 4; // начинаем с длины 4
    for (int i = 0; i < gameInfo->snake.length; i++)
    {
        gameInfo->snake.segments[i].x = BOARD_WIDTH / 2 - i; // горизонтально вправо или влево
        gameInfo->snake.segments[i].y = BOARD_HEIGHT / 2;
    }
    gameInfo->snake.dir_x = 1; // начальное направление вправо
    gameInfo->snake.dir_y = 0;

    // Размещаем текущую фигуру на игровом поле
    PlacePieceOnField(gameInfo, &gameInfo->snake);
}

// Функция временно удаляет фигуру с игр поля перед проверкой перемещения
void removePieceFromField(GameInfo_t *gameInfo)
{ // ++
    for (int i = 0; i < gameInfo->snake.length; i++)
    {
        gameInfo->field[gameInfo->snake.segments[i].y]
                       [gameInfo->snake.segments[i].x] = 0;
    }
}

// движение змейки вперед при отсутствии ввода от пользователя
void move_snake(GameInfo_t *gameInfo)
{
    removePieceFromField(gameInfo);
    // Сдвигаем сегменты: начиная с хвоста к голове
    if (canMove(gameInfo))
    {
        for (int i = gameInfo->snake.length - 1; i > 0; i--)
        {
            gameInfo->snake.segments[i] = gameInfo->snake.segments[i - 1];
        }
        // Обновляем голову в соответствии с направлением
        gameInfo->snake.segments[0].x += gameInfo->snake.dir_x;
        gameInfo->snake.segments[0].y += gameInfo->snake.dir_y;
        PlacePieceOnField(gameInfo, &gameInfo->snake);
    }
    else
    {
        exit(1);
    }
}

int canMove(GameInfo_t *gameInfo)
{ //
    int newX = gameInfo->snake.segments[0].x + gameInfo->snake.dir_x;
    int newY = gameInfo->snake.segments[0].y + gameInfo->snake.dir_y;
    // Проверка на выход за границы игрового поля
    if (newX < 0 || newX >= BOARD_WIDTH || newY >= BOARD_HEIGHT || newY < 0)
    {
        return 0;
    }
    // // Проверка на столкновение с другими фигурами
    // if (newY >= 0 && gameInfo->field[newY][newX] == 1) {
    //   return 0;
    // }
    return 1; // Можно переместить
}

void movePieceDown(GameInfo_t *gameInfo)
{
    //removePieceFromField(gameInfo);
    if (gameInfo->snake.dir_x == 1 || gameInfo->snake.dir_x == -1)
    {
            gameInfo->snake.dir_x = 0;
            gameInfo->snake.dir_y = 1;
            //move_snake(gameInfo);
    }
}

void movePieceUp(GameInfo_t *gameInfo)
{
    //removePieceFromField(gameInfo);
    if (gameInfo->snake.dir_x == 1 || gameInfo->snake.dir_x == -1)
    {
            gameInfo->snake.dir_x = 0;
            gameInfo->snake.dir_y = -1;
            //move_snake(gameInfo);
    }
}

void movePieceRight(GameInfo_t *gameInfo)
{
    //removePieceFromField(gameInfo);
    if (gameInfo->snake.dir_y == 1 || gameInfo->snake.dir_y == -1)
    {
            gameInfo->snake.dir_x = 1;
            gameInfo->snake.dir_y = 0;
            //move_snake(gameInfo);
    }
}

void movePieceLeft(GameInfo_t *gameInfo)
{
    //removePieceFromField(gameInfo);
    if (gameInfo->snake.dir_y == 1 || gameInfo->snake.dir_y == -1)
    {
            gameInfo->snake.dir_x = -1;
            gameInfo->snake.dir_y = 0;
            //move_snake(gameInfo);
    }
}

void change_direction(Snake *snake, int new_dir_x, int new_dir_y)
{
    // Можно добавить проверку на противоположность направления,
    // чтобы не развернуться на месте.
    if ((new_dir_x == -snake->dir_x && new_dir_y == -snake->dir_y))
    {
        return; // запрещено разворачиваться на месте
    }
    snake->dir_x = new_dir_x;
    snake->dir_y = new_dir_y;
}

void grow_snake(Snake *snake)
{
    if (snake->length < MAX_LENGTH)
    {
        // добавляем новый сегмент в конец (можно просто копировать последний сегмент)
        snake->segments[snake->length] = snake->segments[snake->length - 1];
        snake->length++;
    }
}

void freeGameResources(GameInfo_t *gameInfo) { // ++
  // Освобождение памяти игрового поля
  if (gameInfo->field != NULL) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
      if (gameInfo->field[i] != NULL) {
        free(gameInfo->field[i]);
      }
    }
    free(gameInfo->field);
    gameInfo->field = NULL;
  }

  // Освобождение памяти матрицы следующей фигуры
  if (gameInfo->snake.segments != NULL) {
    for (int i = 0; i < MAX_LENGTH; i++) {
    free(gameInfo->snake.segments);
    gameInfo->snake.segments = NULL;
  }
}
}