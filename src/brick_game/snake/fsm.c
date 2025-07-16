#include "fsm.h"

GameInfoExt_t *GetCurrentGameInfoExt()
{
  static GameInfoExt_t game_info_ext = {0};
  return &game_info_ext;
}

void FiniteStateMachine(GameInfoExt_t *game_info_ext)
{
  switch (game_info_ext->state)
  { // свитч по состояниям

  case kStart: // если состояние в ожидании запуска
    printf("8");
    if (game_info_ext->new_input)
    {
      switch (
          game_info_ext
              ->input)
      { // если пришел новый ввод от игрока свитч по вводу

      case Start: // если нажали старт
        // здесь должна происходить инициализация игры, поля, змейки и
        // параметров игры
        initGame(game_info_ext);
        game_info_ext->state = kSpawn;
        break;

      case Terminate: // если нажали выйти
        game_info_ext->state = kExit;
        break;

      default:
        break;
      }
    }
    game_info_ext->new_input =
        false; // отметили, что новый ввод был обработан
    break;

  case kSpawn:
    spawnSnake(game_info_ext);
    spawnApple(game_info_ext);
    game_info_ext->state = kMoving;
    break;

  case kMoving:
    if (game_info_ext->new_input)
    {
      switch (game_info_ext->input)
      {
      case Left:
        movePieceLeft(game_info_ext);
        game_info_ext->state = kShifting;
        break;
      case Right:
        movePieceRight(game_info_ext);
        game_info_ext->state = kShifting;
        break;
      case Down:
        movePieceDown(game_info_ext);
        game_info_ext->state = kShifting;
        break;
      case Up:
        movePieceUp(game_info_ext);
        game_info_ext->state = kShifting;
        break;
      case Action:
        // ускорение змейки
        game_info_ext->state = kShifting;
        break;
      case Pause:
        game_info_ext->state = kPause;
        game_info_ext->game_info.pause = PAUSE;
        break;
      case Terminate:
        // переходим в состояние выхода
        game_info_ext->state = kExit;
        break;

      default:
        break;
      }
    }
    game_info_ext->new_input = false;
    break;

  case kShifting:
    if (isColliding(game_info_ext) == 0)
    {
      removePieceFromField(game_info_ext);
      snakeShifting(game_info_ext);
      spawnSnake(game_info_ext);
      game_info_ext->state = kMoving;
    }
    else if (isColliding(game_info_ext) == 1 ||
             isColliding(game_info_ext) == 2)
    {
      game_info_ext->state = kColliding;
    }
    break;

  case kColliding:
    if (isColliding(game_info_ext) == 2) // врезались в яблоко
    {
      removePieceFromField(game_info_ext);
      snakeShifting(game_info_ext);
      growSnake(game_info_ext);
      game_info_ext->state = kSpawn;
    }
    else if (isColliding(game_info_ext) == 1)
    {
      game_info_ext->state = kGameOver;
    }
    break;

  case kGameOver:
    //
    game_info_ext->state = kStart;
    game_info_ext->game_info.pause = GAMEOVER;
    break;

  case kPause:
    switch (game_info_ext->input)
    {
    case Pause:
      game_info_ext->game_info.pause = PLAYING;
      game_info_ext->state = kMoving;
      break;
    case Terminate:
      game_info_ext->state = kExit;
      break;
    default:
      break;
    }
    break;

  case kExit:
    freeGameResources(game_info_ext);
    game_info_ext->game_info.pause = EXITING;
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