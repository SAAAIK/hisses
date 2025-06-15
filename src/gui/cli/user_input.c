#include "../../brick_game/tetris/tetris_game.h"

void userInput(GameInfo_t *gameInfo, UserAction_t action, bool hold) {
  // В этом примере параметр hold не используется
  if (hold) { // hold - при зажатии клавиши вниз фигура телепортируется ?
    printf("1");
  }
  switch (action) {
  case Start:
    // if (gameInfo->state == GameState_WaitingStart ||
    //     gameInfo->state == GameState_Over) {
    initGame(gameInfo); // Переинициализация игры при необходимости
    gameInfo->state = GameState_Running;
    // }
    break;
  case Pause:
    if (gameInfo->state == GameState_Running) {
      gameInfo->state = GameState_Paused;
    } else if (gameInfo->state == GameState_Paused) {
      gameInfo->state = GameState_Running;
    }
    gameInfo->pause = !gameInfo->pause; // ??
    break;
  case Terminate:
    gameInfo->state = GameState_Over;
    break;
  case Left:
    if (!gameInfo->pause)
      movePieceLeft(gameInfo);
    break;
  case Right:
    if (!gameInfo->pause)
      movePieceRight(gameInfo);
    break;
  case Down:
    if (!gameInfo->pause)
      movePieceDown(gameInfo);
    break;
  case Action:
    if (!gameInfo->pause)
      rotatePiece(gameInfo); // Поворот фигуры
    break;
  case NoAction:
    break;
  }
}

GameInfo_t updateCurrentState(GameInfo_t *gameInfo) { return *gameInfo; } // ??
