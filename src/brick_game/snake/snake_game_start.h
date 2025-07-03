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
    Segment *segments;
    int length; // текущая длина змейки
    int dir_x; // направление по x (-1,0,1)
    int dir_y; // направление по y (-1,0,1)
} Snake;

typedef struct {
    int x;
    int y;
} Apple;

// Структура состояния игры
typedef enum {
  //GameState_WaitingStart,
  GameState_Running,
  //GameState_Paused,
  //GameState_Over
} GameState_t; //

// Типы  действий пользователя
typedef enum {
  //Start,
  //Pause,
  //Terminate,
  Left,
  Right,
  Down,
  Up,
  //Action,
  NoAction
} UserAction_t; //

// Структура для передачи информации об игре в интерфейс
typedef struct {
  int **field; // Указатель на игровое поле
  int *snake_p; // Указатель на змейку
  int score;                   // Текущий счет
  int high_score;              // Рекордный счет
  int level;                   // Текущий уровень
  int speed;                   // Скорость падения фигур
  int pause;                   // Состояние паузы игры
  Snake snake;
  Apple apple;
  GameState_t state;           // Текущее состояние игры

} GameInfo_t;

void userInput(GameInfo_t *gameInfo, UserAction_t action/*, bool hold*/);

void initGame(GameInfo_t *gameInfo);
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
#endif