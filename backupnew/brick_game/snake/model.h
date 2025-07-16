#ifndef MODEL_H
#define MODEL_H

// Размер игрового поля
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
// Интервал в миллисекундах для автоматического сдвига змейки вперед
#define DROP_INTERVAL 2000000. 
// Максимальная длинна
#define MAX_LENGTH 200

#define DEFAULT_LEVEL 1
#define DEFAULT_SPEED 1
#define HEAD_COLOR 1
#define BODY_COLOR 2
#define APPLE_COLOR 3
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

typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    PAUSE,
    QUIT,
    NO_INPUT
} UserAction_t;

/*
typedef struct {
    Segment *segments;
    int length; // текущая длина змейки
    int dir_x; // направление по x (-1,0,1)
    int dir_y; // направление по y (-1,0,1)
} Snake;
*/

typedef struct {
    int x;
    int y;
} Apple;

// Данные модели
typedef enum {
   Spawn,
   GameOver,
   Pause,
   Moving,
   Reaching,
   Growing
} GameState_t;


typedef  struct {
    Segment *segments;
    int length; // текущая длина змейки
    int dir_x; // направление по x (-1,0,1)
    int dir_y; // направление по y (-1,0,1)
    } Snake;

typedef struct {
  int **field; // Указатель на игровое поле;
  int score;                   // Текущий счет
  int high_score;              // Рекордный счет
  int level;                   // Текущий уровень
  int speed;                   // Скорость падения фигур
  int pause;                   // Состояние паузы игры
  Snake snake;
  Apple apple;
  GameState_t state;           // Текущее состояние игры

} GameInfo_t;

typedef struct model {
    GameInfo_t gameInfo;  // Данные скрыты внутри!
} model;



model* modelInit();  
void modelFieldInit(model* model);
void modelSnakeInit(model* model);
void modelFree(model* model);
void sendActionToModel(UserAction_t);
void updateModel(model* model, UserAction_t action);
void moveSnake(model* model);
int modelGetScore(const model* model);
int modelGetLevel(const model* model);
int modelGetSnakeLength(const model* model);
Segment modelGetSnakeSegment(const model* model, int index);
GameState_t modelGetGameState(const model* model);
/*
//void print_field(GameInfo_t *gameInfo, Snake *snake);
void removePieceFromField(GameInfo_t *gameInfo);
void placePieceOnField(GameInfo_t *gameInfo, Snake *snake);

void spawnSnake(GameInfo_t *gameInfo);
void spawnApple(GameInfo_t *gameInfo);
void move_snake(GameInfo_t *gameInfo);
int canMove(GameInfo_t *gameInfo);
void growSnake(GameInfo_t *gameInfo);

void movePieceRight(GameInfo_t *gameInfo);
void movePieceLeft(GameInfo_t *gameInfo);
void movePieceUp(GameInfo_t *gameInfo);
void movePieceDown(GameInfo_t *gameInfo);
void freeGameResources(GameInfo_t *gameInfo);
*/
//typedef struct Controller Controller;
#endif