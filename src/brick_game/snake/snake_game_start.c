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

    gameInfo->snake.segments = malloc(MAX_LENGTH * sizeof(Segment));
    memset(gameInfo->snake.segments, 0, MAX_LENGTH * sizeof(Segment));

    gameInfo->level = 1;
    gameInfo->speed = 1; // Начальная скорость
    gameInfo->pause = 0; // Игра не на паузе

    // инициализируем змейку
    spawnSnake(gameInfo);
    spawnApple(gameInfo);
}

// Обновление поля и вывод
void placePieceOnField(GameInfo_t *gameInfo, Snake *snake)
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
void spawnSnake(GameInfo_t *gameInfo)
{

    gameInfo->snake.length = 7; // начинаем с длины 4
    for (int i = 0; i < gameInfo->snake.length; i++)
    {
        gameInfo->snake.segments[i].x = BOARD_WIDTH / 2 - i; // горизонтально вправо или влево
        gameInfo->snake.segments[i].y = BOARD_HEIGHT / 2;
    }
    gameInfo->snake.dir_x = 1; // начальное направление вправо
    gameInfo->snake.dir_y = 0;

    // Размещаем текущую фигуру на игровом поле
    placePieceOnField(gameInfo, &gameInfo->snake);
}

void spawnApple(GameInfo_t *gameInfo)
{
    int x, y;
    do
    {
        x = rand() % 10;
        y = rand() % 20;
    } while (gameInfo->field[y][x] == 1);

    gameInfo->apple.x = x;
    gameInfo->apple.y = y;
    gameInfo->field[y][x] = 1;

    // gameInfo->apple.x = rand() % 20;
    // gameInfo->apple.y = rand() % 20;
    // if (gameInfo->field[gameInfo->apple.x][gameInfo->apple.y] == 1){
    //     spawnApple(gameInfo);
    // }
    // else gameInfo->field[gameInfo->apple.x][gameInfo->apple.y] = 1;
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
    //
    // Сдвигаем сегменты: начиная с хвоста к голове
    if (canMove(gameInfo) == 1)
    {   removePieceFromField(gameInfo);
        for (int i = gameInfo->snake.length - 1; i > 0; i--)
        {
            gameInfo->snake.segments[i] = gameInfo->snake.segments[i - 1];
        }
        // Обновляем голову в соответствии с направлением
        gameInfo->snake.segments[0].x += gameInfo->snake.dir_x;
        gameInfo->snake.segments[0].y += gameInfo->snake.dir_y;
        placePieceOnField(gameInfo, &gameInfo->snake);
    }
    else if (canMove(gameInfo) == 2)
    {   removePieceFromField(gameInfo);
        for (int i = gameInfo->snake.length - 1; i > 0; i--)
        {
            gameInfo->snake.segments[i] = gameInfo->snake.segments[i - 1];
        }
        // Обновляем голову в соответствии с направлением
        gameInfo->snake.segments[0].x += gameInfo->snake.dir_x;
        gameInfo->snake.segments[0].y += gameInfo->snake.dir_y;
        growSnake(gameInfo);
        placePieceOnField(gameInfo, &gameInfo->snake);
        spawnApple(gameInfo);
    }
    else if (canMove(gameInfo) == 0)
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
    if (gameInfo->field[newY][newX] == 1) // Проверка на столкновение с другими фигурами
    {
        if (newX == gameInfo->apple.x && newY == gameInfo->apple.y)
        {
            printf("\nx = %d, y = %d\n ap.x = %d, ap.y = %d\n", newX, newY, gameInfo->apple.x, gameInfo->apple.y);
            return 2;
        }
        else
        {
            printf("\nx = %d, y = %d\n ap.x = %d, ap.y = %d\n", newX, newY, gameInfo->apple.x, gameInfo->apple.y);
            return 0;
        }
    }
    return 1; // Можно переместить
}

void growSnake(GameInfo_t *gameInfo)
{
    if (gameInfo->snake.length < MAX_LENGTH)
    {
        // добавляем новый сегмент в конец (можно просто копировать последний сегмент)
        gameInfo->snake.segments[gameInfo->snake.length] = gameInfo->snake.segments[gameInfo->snake.length - 1];
        gameInfo->snake.length++;
    }
}

void freeGameResources(GameInfo_t *gameInfo)
{ // ++
    // Освобождение памяти игрового поля
    if (gameInfo->field != NULL)
    {
        for (int i = 0; i < BOARD_HEIGHT; i++)
        {
            if (gameInfo->field[i] != NULL)
            {
                free(gameInfo->field[i]);
            }
        }
        free(gameInfo->field);
        gameInfo->field = NULL;
    }

    // Освобождение памяти матрицы следующей фигуры
    if (gameInfo->snake.segments != NULL)
    {
        for (int i = 0; i < MAX_LENGTH; i++)
        {
            free(gameInfo->snake.segments);
            gameInfo->snake.segments = NULL;
        }
    }
}

void movePieceDown(GameInfo_t *gameInfo)
{
    // removePieceFromField(gameInfo);
    if (gameInfo->snake.dir_x == 1 || gameInfo->snake.dir_x == -1)
    {
        gameInfo->snake.dir_x = 0;
        gameInfo->snake.dir_y = 1;
        // move_snake(gameInfo);
    }
}

void movePieceUp(GameInfo_t *gameInfo)
{
    // removePieceFromField(gameInfo);
    if (gameInfo->snake.dir_x == 1 || gameInfo->snake.dir_x == -1)
    {
        gameInfo->snake.dir_x = 0;
        gameInfo->snake.dir_y = -1;
        // move_snake(gameInfo);
    }
}

void movePieceRight(GameInfo_t *gameInfo)
{
    // removePieceFromField(gameInfo);
    if (gameInfo->snake.dir_y == 1 || gameInfo->snake.dir_y == -1)
    {
        gameInfo->snake.dir_x = 1;
        gameInfo->snake.dir_y = 0;
        // move_snake(gameInfo);
    }
}

void movePieceLeft(GameInfo_t *gameInfo)
{
    // removePieceFromField(gameInfo);
    if (gameInfo->snake.dir_y == 1 || gameInfo->snake.dir_y == -1)
    {
        gameInfo->snake.dir_x = -1;
        gameInfo->snake.dir_y = 0;
        // move_snake(gameInfo);
    }
}