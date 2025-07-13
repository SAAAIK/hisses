#include "snake_game_start.h"

// ==========Функция - инициализация игрового поля
void initGame(GameInfoExt_t *game_info_ext)
{
    // Динамическое выделение памяти для игрового поля
    game_info_ext->game_info.field = malloc(BOARD_HEIGHT * sizeof(int *));
    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        game_info_ext->game_info.field[i] = malloc(BOARD_WIDTH * sizeof(int));
        memset(game_info_ext->game_info.field[i], 0,
               BOARD_WIDTH * sizeof(int)); // Инициализация нулями
    }

    game_info_ext->snake.segments = malloc(MAX_LENGTH * sizeof(Segment));
    memset(game_info_ext->snake.segments, 0, MAX_LENGTH * sizeof(Segment));

    game_info_ext->game_info.level = 1;
    game_info_ext->game_info.speed = 1; // Начальная скорость
    game_info_ext->game_info.pause = 0; // Игра не на паузе

    // инициализируем змейку
    initSnake(game_info_ext);
    //spawnApple(game_info_ext); //для версии фсм закомментить
}

// Обновление поля и вывод
void spawnSnake(GameInfoExt_t *game_info_ext)
{
    for (int i = 0; i < game_info_ext->snake.length; i++)
    {
        int x = game_info_ext->snake.segments[i].x;
        int y = game_info_ext->snake.segments[i].y;
        // Проверка границ поля
        if (x >= 0 && x < BOARD_WIDTH && y >= 0 && y < BOARD_HEIGHT)
        {
            game_info_ext->game_info.field[y][x] = 1;
        }
    }
}

// инициализация змейки
void initSnake(GameInfoExt_t *game_info_ext)
{

    game_info_ext->snake.length = 7; // начинаем с длины 4
    for (int i = 0; i < game_info_ext->snake.length; i++)
    {
        game_info_ext->snake.segments[i].x = BOARD_WIDTH / 2 - i; // горизонтально вправо или влево
       game_info_ext->snake.segments[i].y = BOARD_HEIGHT / 2;
    }
    game_info_ext->snake.dir_x = 1; // начальное направление вправо
    game_info_ext->snake.dir_y = 0;

    // Размещаем змейку на игровом поле
    spawnSnake(game_info_ext);
}

void spawnApple(GameInfoExt_t *game_info_ext)
{
    int x, y;
    do
    {
        x = rand() % 10;
        y = rand() % 20;
    } while (game_info_ext->game_info.field[y][x] == 1);

    game_info_ext->apple.x = x;
    game_info_ext->apple.y = y;
    game_info_ext->game_info.field[y][x] = 1;
}

// Функция временно удаляет фигуру с игр поля перед проверкой перемещения
void removePieceFromField(GameInfoExt_t *game_info_ext)
{ // ++
    for (int i = 0; i < game_info_ext->snake.length; i++)
    {
        game_info_ext->game_info.field[game_info_ext->snake.segments[i].y]
                       [game_info_ext->snake.segments[i].x] = 0;
    }
}

// движение змейки вперед при отсутствии ввода от пользователя
void move_snake(GameInfoExt_t *game_info_ext)
{
    //
    // Сдвигаем сегменты: начиная с хвоста к голове
    if (isColliding(game_info_ext) == 1)
    {   removePieceFromField(game_info_ext);
        //shift state
        snakeShifting(game_info_ext);
        spawnSnake(game_info_ext);
    }
    else if (isColliding(game_info_ext) == 2)
    {   removePieceFromField(game_info_ext);
        //shift state
        snakeShifting(game_info_ext);
        growSnake(game_info_ext);
        spawnSnake(game_info_ext);
        //spawn state
        spawnApple(game_info_ext);
    }
    else if (isColliding(game_info_ext) == 0)
    {
        exit(1);
    }
}

void snakeShifting (GameInfoExt_t *game_info_ext){
for (int i = game_info_ext->snake.length - 1; i > 0; i--)
        {
            game_info_ext->snake.segments[i] = game_info_ext->snake.segments[i - 1];
        }
        // Обновляем голову в соответствии с направлением
        game_info_ext->snake.segments[0].x += game_info_ext->snake.dir_x;
        game_info_ext->snake.segments[0].y += game_info_ext->snake.dir_y;
}

int isColliding(GameInfoExt_t *game_info_ext)
{ //
    int newX = game_info_ext->snake.segments[0].x + game_info_ext->snake.dir_x;
    int newY = game_info_ext->snake.segments[0].y + game_info_ext->snake.dir_y;
    // Проверка на выход за границы игрового поля
    if (newX < 0 || newX >= BOARD_WIDTH || newY >= BOARD_HEIGHT || newY < 0)
    {
        return 1;
    }
    if (game_info_ext->game_info.field[newY][newX] == 1) // Проверка на столкновение с другими фигурами
    {
        if (newX == game_info_ext->apple.x && newY == game_info_ext->apple.y)
        {
            printf("\nx = %d, y = %d\n ap.x = %d, ap.y = %d\n", newX, newY, game_info_ext->apple.x, game_info_ext->apple.y);
            return 2;
        }
        else
        {
            printf("\nx = %d, y = %d\n ap.x = %d, ap.y = %d\n", newX, newY, game_info_ext->apple.x, game_info_ext->apple.y);
            return 1;
        }
    }
    return 0; // Можно переместить
}

void growSnake(GameInfoExt_t *game_info_ext)
{
    if (game_info_ext->snake.length < MAX_LENGTH)
    {
        // добавляем новый сегмент в конец (можно просто копировать последний сегмент)
        game_info_ext->snake.segments[game_info_ext->snake.length] = game_info_ext->snake.segments[game_info_ext->snake.length - 1];
        game_info_ext->snake.length++;
    }
}

void freeGameResources(GameInfoExt_t *game_info_ext)
{ // ++
    // Освобождение памяти игрового поля
    if (game_info_ext->game_info.field != NULL)
    {
        for (int i = 0; i < BOARD_HEIGHT; i++)
        {
            if (game_info_ext->game_info.field[i] != NULL)
            {
                free(game_info_ext->game_info.field[i]);
            }
        }
        free(game_info_ext->game_info.field);
        game_info_ext->game_info.field = NULL;
    }

    // Освобождение памяти матрицы следующей фигуры
    if (game_info_ext->snake.segments != NULL)
    {
        for (int i = 0; i < MAX_LENGTH; i++)
        {
            free(game_info_ext->snake.segments);
            game_info_ext->snake.segments = NULL;
        }
    }
}

void movePieceDown(GameInfoExt_t *game_info_ext)
{
    // removePieceFromField(game_info_ext);
    if (game_info_ext->snake.dir_x == 1 || game_info_ext->snake.dir_x == -1)
    {
        game_info_ext->snake.dir_x = 0;
        game_info_ext->snake.dir_y = 1;
        // move_snake(game_info_ext);
    }
}

void movePieceUp(GameInfoExt_t *game_info_ext)
{
    // removePieceFromField(game_info_ext);
    if (game_info_ext->snake.dir_x == 1 || game_info_ext->snake.dir_x == -1)
    {
        game_info_ext->snake.dir_x = 0;
        game_info_ext->snake.dir_y = -1;
        // move_snake(game_info_ext);
    }
}

void movePieceRight(GameInfoExt_t *game_info_ext)
{
    // removePieceFromField(game_info_ext);
    if (game_info_ext->snake.dir_y == 1 || game_info_ext->snake.dir_y == -1)
    {
        game_info_ext->snake.dir_x = 1;
        game_info_ext->snake.dir_y = 0;
        // move_snake(game_info_ext);
    }
}

void movePieceLeft(GameInfoExt_t *game_info_ext)
{
    // removePieceFromField(game_info_ext);
    if (game_info_ext->snake.dir_y == 1 || game_info_ext->snake.dir_y == -1)
    {
        game_info_ext->snake.dir_x = -1;
        game_info_ext->snake.dir_y = 0;
        // move_snake(game_info_ext);
    }
}