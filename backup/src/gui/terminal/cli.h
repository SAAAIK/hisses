#ifndef S21_SNAKE_CLI
#define S21_SNAKE_CLI
#include <string.h>

#include "../../brick_game/snake/model.h"

/*// Вывод 3 лучших очков
#define MAX_SCORES 3
#define MAX_LINE_LENGTH 100
#define LINE_LENGTH 100

// СТруктура для чтения файла
typedef struct {
  char name[50];  // Предполагаем, что имя не будет длиннее 49 символов
  int score;
} ScoreEntry;
*/
void initializeGame(GameInfo_t *gameInfo);
UserAction_t getUserAction(int ch, bool *start_pressed, GameInfo_t *gameInfo);
void printHello();
void GameOver(GameInfo_t *gameInfo);

// Если игра не запущена и не была запущена, показать начальный экран
void printFirstScreen(bool *start_pressed, GameInfo_t gameInfo,
                      UserAction_t action);

void printPauseScreen();
void processGameOver(bool *flag_while, GameInfo_t *gameInfo);
void processGameWaiting(bool *start_pressed, GameInfo_t *gameInfo);

/*
void printTopScores();
int readScores(FILE *file, ScoreEntry scores[], int maxScores);
int compareScores(const void *a, const void *b);

// Первоначальная запись игрока в таблицу top.txt
void initPlayerScore(char *name);

void updateLastLine(char *playerName, int score);
*/
#endif