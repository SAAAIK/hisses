#ifndef S21_SNAKE_GAME_H
#define S21_SNAKE_GAME_H

// Размер игрового поля
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20

namespace s21 {

// Типы  действий пользователя
typedef enum {
  Start,
  Pause,
  Terminate,
  Left,
  Right,
  Up,
  Down,
  Action
} UserAction_t;

typedef struct {
    int x;
    int y;
} Position_t;

// Структура состояния игры
typedef enum {
  GameState_WaitingStart,
  GameState_Running,
  GameState_Paused,
  GameState_Over
} GameState_t;  //

// Структура для передачи информации об игре в интерфейс
typedef struct {
  int **field;  // Указатель на игровое поле
  int **next;  // Указатель на матрицу следующей фигуры
  int score;                    // Текущий счет
  int high_score;               // Рекордный счет
  int level;                    // Текущий уровень
  int speed;                    // Скорость падения фигур
  int pause;                    // Состояние паузы игры
  GameState_t state;            // Текущее состояние игры

} GameInfo_t;

// Структура для игрового поля
typedef struct {
  int matrix[BOARD_HEIGHT][BOARD_WIDTH];
} GameBoard;

// Определение функций для взаимодействия с пользовательским вводом и обновления
// состояния
void userInput(GameInfo_t *gameInfo, UserAction_t action, bool hold);
GameInfo_t updateCurrentState(GameInfo_t *gameInfo);

} //s21 namespace

#endif