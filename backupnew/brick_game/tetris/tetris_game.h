#ifndef S21_TETRIS_GAME_H
#define S21_TETRIS_GAME_H

// Размер игрового поля
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
#define DROP_INTERVAL                                                          \
  2000 // Интервал в миллисекундах для автоматического сдвига фигуры вниз

// Размер для фигур
#define MAX_BLOCKS 4
#include <ncurses.h>
#include <stdbool.h> // Для использования bool
#include <stdio.h>
#include <stdlib.h> // для rand() и srand()
#include <string.h>
#include <time.h>

//=================Структура проекта=================
// src/
// ├── brick_game/
// │   └── tetris/
// │       ├── tetris_game.h
// │       └── tetris_game.c
// └── gui/
// │   └── cli/
// │       ├── main.c
// │       └── interface.c
// │       └── user_input.c
// │       └── top_score.c
// │       └── cli.h
// └── tests/
// │    ├── tests.c
// │    └── tests.h
// │    └── unit_tests.c

// =================Структуры для фигур=================

// Типы фигуры
typedef enum { I, J, L, O, S, T, Z } TetrominoType; //
//  typedef enum { Z, T, S, O, L, J, I } TetrominoType;

// Структура для текущей ориентации фигуры и координаты на игровом поле
typedef struct {
  TetrominoType type;
  int orientation;
  int position_x, position_y;
  int shape[MAX_BLOCKS][MAX_BLOCKS]; // Макс размер фигуры 4х4
} Tetromino;                         //

// Структура состояния игры
typedef enum {
  GameState_WaitingStart,
  GameState_Running,
  GameState_Paused,
  GameState_Over
} GameState_t; //

// Типы  действий пользователя
typedef enum {
  Start,
  Pause,
  Terminate,
  Left,
  Right,
  Down,
  Action,
  NoAction
} UserAction_t; //

// Структура для передачи информации об игре в интерфейс
typedef struct {
  int **field; // Указатель на игровое поле
  int **next; // Указатель на матрицу следующей фигуры
  int score;                   // Текущий счет
  int high_score;              // Рекордный счет
  int level;                   // Текущий уровень
  int speed;                   // Скорость падения фигур
  int pause;                   // Состояние паузы игры
  Tetromino currentPiece;      // Текущая активная фигура
  TetrominoType nextPieceType; // Тип фигуры next
  GameState_t state;           // Текущее состояние игры

} GameInfo_t;

// Структура для игрового поля
typedef struct {
  int matrix[BOARD_HEIGHT][BOARD_WIDTH];
} GameBoard;

// Определение функций для взаимодействия с пользовательским вводом и обновления
// состояния
void userInput(GameInfo_t *gameInfo, UserAction_t action, bool hold);
GameInfo_t updateCurrentState(GameInfo_t *gameInfo);

// =================ФУНКЦИИ=================
void initGame(GameInfo_t *gameInfo);
void generateNextPiece(int **next, GameInfo_t *gameInfo);
void spawnNewPiece(GameInfo_t *gameInfo);
void placePieceOnField(GameInfo_t *gameInfo, Tetromino *tetromino);
void printField(GameInfo_t *gameInfo);
void fixPiece(GameInfo_t *gameInfo);
int canMove(GameInfo_t *gameInfo, int dx, int dy);
void movePieceDown(GameInfo_t *gameInfo);
void removePieceFromField(GameInfo_t *gameInfo);
void movePieceLeft(GameInfo_t *gameInfo);
void movePieceRight(GameInfo_t *gameInfo);
int removeFullRows(GameInfo_t *gameInfo);
void rotatePiece(GameInfo_t *gameInfo);
void freeGameResources(GameInfo_t *gameInfo);
#endif