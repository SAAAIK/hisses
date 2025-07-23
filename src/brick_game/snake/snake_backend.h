#ifndef S21_SNAKE_GAME_START_H
#define S21_SNAKE_GAME_START_H

// Размер игрового поля
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
// Интервал в миллисекундах для автоматического сдвига змейки вперед
#define DROP_INTERVAL 2000000. 
// Максимальная длинна
#define MAX_LENGTH 200

#define PLAYING 0
#define PAUSE 1
#define GAMEOVER 2
#define EXITING 3

#include <stdbool.h> // Для использования bool
#include <stdio.h>
#include <stdlib.h> // для rand() и srand()
#include <string.h>
#include <sys/time.h>

#include "snake_lib.h"

typedef struct {
    int x;
    int y;
} Segment_t;

typedef struct {
    Segment_t *segments;
    int length; // текущая длина змейки
    int dir_x; // направление по x (-1,0,1)
    int dir_y; // направление по y (-1,0,1)
} Snake_t;

typedef struct {
    int x;
    int y;
} Apple_t;

// Данные модели
typedef enum {
   kStart,
   kSpawn,
   kMoving,
   kShifting,
   kColliding,
   kGameOver,
   kPause,
   kExit
} GameState_t;

// // Типы  действий пользователя
// typedef enum {
//   Start,
//   Pause,
//   Terminate,
//   Left,
//   Right,
//   Down,
//   Up,
//   Action
// } UserAction_t; //

// // Структура для передачи информации об игре в интерфейс
// typedef struct {
//   int **field; // Указатель на игровое поле
//   int **next; // Указатель на змейку
//   int score;                   // Текущий счет
//   int high_score;              // Рекордный счет
//   int level;                   // Текущий уровень
//   int speed;                   // Скорость падения фигур
//   int pause;                   // Состояние паузы игры
// } GameInfo_t;

typedef struct {
  GameInfo_t game_info;
  int *snake_p; // Указатель на змейку
  Snake_t snake;
  Apple_t apple;
  GameState_t state;           // Текущее состояние игры
  UserAction_t input;
  bool new_input;
  bool timer_on;
  unsigned long long timer;
} GameInfoExt_t;

//void userInput(GameInfoExt_t *game_info_ext, UserAction_t action/*, bool hold*/);

void initGame(GameInfoExt_t *game_info_ext);
//void print_field(GameInfoExt_t *game_info_ext, Snake *snake);
void removePieceFromField(GameInfoExt_t *game_info_ext);
void spawnSnake(GameInfoExt_t *game_info_ext);

void initSnake(GameInfoExt_t *game_info_ext);
void spawnApple(GameInfoExt_t *game_info_ext);
void move_snake(GameInfoExt_t *game_info_ext);
int isColliding(GameInfoExt_t *game_info_ext);
void growSnake(GameInfoExt_t *game_info_ext);
void snakeShifting (GameInfoExt_t *game_info_ext);

void movePieceRight(GameInfoExt_t *game_info_ext);
void movePieceLeft(GameInfoExt_t *game_info_ext);
void movePieceUp(GameInfoExt_t *game_info_ext);
void movePieceDown(GameInfoExt_t *game_info_ext);
void freeGameResources(GameInfoExt_t *game_info_ext);
bool CheckIsItTimeToShift(GameInfoExt_t *game_info_ext);
unsigned long long CurrentTime();
unsigned long long TimeDiff(unsigned long long timer);
void GameScore(GameInfoExt_t *game_info_ext);
void SetLevel(GameInfoExt_t *game_info_ext);

void LoadMaxScore(GameInfoExt_t *game_info_ext);
void SaveMaxScore(GameInfoExt_t *game_info_ext);
#endif