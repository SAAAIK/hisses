include "snake_game_start.h"

void finite_state_machine_func(GameInfo_t *gameInfo, UserAction_t action) {
  switch (gameInfo->state) {

    case GameStart:
      switch (action) {
        case Start:
          // здесь должна происходить инициализация игры, поля, змейки и
          // параметров игры
          initGame(gameInfo);
          gameInfo->state = Spawn;
          break;
        case Terminate:
          gameInfo->state = GameExit;
          break;
      }
      break;

    case Spawn:
      spawnSnake(gameInfo);
      spawnApple(gameInfo);
      gameInfo->state = Moving;
      break;

    case Moving:
      switch (action) {
        case Left:
          movePieceLeft(gameInfo);
          gameInfo->state = Shifting;
          break;
        case Right:
          movePieceRight(gameInfo);
          gameInfo->state = Shifting;
          break;
        case Down:
          movePieceDown(gameInfo);
          gameInfo->state = Shifting;
          break;
        case Up:
          movePieceUp(gameInfo);
          gameInfo->state = Shifting;
          break;
        case Action:
          // ускорение змейки
          gameInfo->state = Shifting;
          break;
        case Pause:
          // пауза
          gameInfo->state = Pause;
          break;
        case Terminate:
          // переходим в состояние выхода
          gameInfo->state = GameExit;
          break;
      }
      break;

    case Shifting:
      if (isColliding(gameInfo) == 0) {
        removePieceFromField(gameInfo);
        snakeShifting(gameInfo);
        spawnSnake(gameInfo);
        gameInfo->state = Moving;

      } else if (isColliding(gameInfo) == 1 || isColliding(gameInfo) == 2) {
        gameInfo->state = Colliding;
      }
      break;

    case Colliding:
      if (isColliding(gameInfo) == 2)  // врезались в яблоко
      {
        removePieceFromField(gameInfo);
        snakeShifting(gameInfo);
        growSnake(gameInfo);
        gameInfo->state = Spawn;

      } else if (isColliding(gameInfo) == 1) {
        gameInfo->state = GameOver;
      }
      break;

    case GameOver:
    //
      gameInfo->state = GameStart;
      break;

    case GamePause:
      // вопрос как реализовывать паузу
      break;

    case GameExit:
      freeGameResources(gameInfo);
      break;

    default:
      break;
  }
}

// user_input_to_action(getch());

// void user_input_to_action(int user_input) {
//   switch (user_input) {
//     case KEY_LEFT:
//       userInput(Left, false);
//       break;
//     case KEY_RIGHT:
//       userInput(Right, false);
//       break;
//     case KEY_UP:
//       userInput(Up, false);
//       break;
//     case KEY_DOWN:
//       userInput(Down, false);
//       break;
//     case 'a':
//       userInput(Action, false);
//       break;
//     case 's':
//       userInput(Start, false);
//       break;
//     case 'p':
//       userInput(Pause, false);
//       break;
//     case 't':
//       userInput(Terminate, false);
//       break;
//     default:
//       break;
//   }
// }

// void userInput(UserAction_t user_input, bool hold) {
//   (void)hold;
//   GameInfoExtended_t *game_inf_ex = get_current_game_inf_ex();
//   if (!game_inf_ex->new_input) {
//     game_inf_ex->input = user_input;
//     game_inf_ex->new_input = true;
//   }
// }