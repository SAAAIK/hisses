#include "snake_game_start.h"

void initializeGame(GameInfo_t *gameInfo);
UserAction_t getUserAction(int ch,
                           bool *start_pressed /*, GameInfo_t *gameInfo*/);
void printField(GameInfo_t *gameInfo);
void printHello();
void printStart();
void printFirstScreen(bool *start_pressed, GameInfo_t gameInfo,
                      UserAction_t action);

void finite_state_machine_func(GameInfo_t *gameInfo, UserAction_t action) {
  switch (gameInfo->state) {
    case GameStart:
      printHello();
      switch (action) {
        case Start:
        printStart();
          // здесь должна происходить инициализация игры, поля, змейки и
          // параметров игры
          initGame(gameInfo);
          gameInfo->state = Spawn;
          break;
        case Terminate:
          gameInfo->state = GameExit;
          break;
        default:
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
          break;
        case Right:
          movePieceRight(gameInfo);
          break;
        case Down:
          movePieceDown(gameInfo);
          break;
        case Up:
          movePieceUp(gameInfo);
          break;
        case Action:
          // ускорение змейки
          break;
        case Pause:
          // пауза
          break;
        case Terminate:
          // переходим в состояние выхода
          break;
        default:
          break;
      }
      // здесь нужна проверка на задержку
      gameInfo->state = Shifting;
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

// void userInput(GameInfo_t *gameInfo, UserAction_t action /*, bool hold*/)
// {
//   // В этом примере параметр hold не используется
//   //   if (hold) { // hold - при зажатии клавиши вниз фигура телепортируется
//   ?
//   //     printf("1");
//   //   }
//   switch (action)
//   {
//   /*case Start:
//     // if (gameInfo->state == GameState_WaitingStart ||
//     //     gameInfo->state == GameState_Over) {
//     initGame(gameInfo); // Переинициализация игры при необходимости
//     gameInfo->state = GameState_Running;
//     // }
//     break;
//   case Pause:
//     if (gameInfo->state == GameState_Running) {
//       gameInfo->state = GameState_Paused;
//     } else if (gameInfo->state == GameState_Paused) {
//       gameInfo->state = GameState_Running;
//     }
//     gameInfo->pause = !gameInfo->pause; // вместо true/false
//     break;
//   case Terminate:
//     gameInfo->state = GameState_Over;
//     break;*/
//   case Left:
//     if (!gameInfo->pause)
//       movePieceLeft(gameInfo);
//     break;
//   case Right:
//     if (!gameInfo->pause)
//       movePieceRight(gameInfo);
//     break;
//   case Down:
//     if (!gameInfo->pause)
//       movePieceDown(gameInfo);
//     break;
//   case Up:
//     if (!gameInfo->pause)
//       movePieceUp(gameInfo);
//     break;
//     /*  case Action:
//         if (!gameInfo->pause)
//           rotatePiece(gameInfo); // Поворот фигуры
//         break;*/
//   case NoAction:
//     break;
//   }
// }

int main()  // КОНТРОЛЛЕР
{
  //   nodelay(strscr,TRUE);

  //   //Model_init();
  //   //View_init();

  //   while (1) {
  //       UserAction_t action =  getUserAction(ch);
  //       userInput(&gameInfo, action /*, hold*/); // Обновляет модель
  //       View_render(); // Запрашивает данные у модели через контроллер
  //       sleep(interval);
  // }

  clock_t lastDropTime = clock();
  double dropInterval = 2000000.;  // Интервал падения (скорость)

  bool start_pressed = false;

  GameInfo_t gameInfo;
  initializeGame(&gameInfo);
  // initGame(&gameInfo);

  while (1) {
    int ch = getch();
    UserAction_t action = getUserAction(ch, &start_pressed /*, &gameInfo*/);
    finite_state_machine_func(&gameInfo, action);

    // userInput(&gameInfo, action /*, hold*/);
    if (clock() - lastDropTime >= dropInterval) {
      lastDropTime = clock();
      clear();
      printField(&gameInfo);
      refresh();
      printf("\n%d\n", isColliding(&gameInfo));
      dropInterval = 2000000.;
    }
    // printField(&gameInfo);
  }
  endwin();
  return 0;
}

void printField(GameInfo_t *gameInfo) {
  // Отрисовка верхней границы поля
  for (int x = -1; x <= BOARD_WIDTH * 2; x++) {
    mvprintw(0, x + 1, "-");
  }
  for (int y = 0; y < BOARD_HEIGHT; y++) {
    // Отрисовка левой границы поля
    mvprintw(y + 1, 0, "]");

    for (int x = 0; x < BOARD_WIDTH; x++) {
      // Используем символ '#' для заполненной ячейки и пробел для пустой
      mvprintw(y + 1, x * 2 + 1, "%c", gameInfo->field[y][x] ? '#' : '+');
    }

    // Отрисовка правой границы поля
    mvprintw(y + 1, BOARD_WIDTH * 2 + 1, "[");
  }

  // Отрисовка нижней границы поля
  for (int x = -1; x <= BOARD_WIDTH * 2; x++) {
    mvprintw(BOARD_HEIGHT + 1, x + 1, "-");
  }
}

void initializeGame(GameInfo_t *gameInfo) {
  srand(time(NULL));
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);

  gameInfo->state = GameStart;
}

UserAction_t getUserAction(int ch,
                           bool *start_pressed /*, GameInfo_t *gameInfo*/) {
  switch (ch) {
    case 's':
      // if (*start_pressed)
      //   freeGameResources(gameInfo); // Чтобы ощишать память с влучае
      //   рестарта
      //                                // игры во время ее исполнения
      *start_pressed = true;
      return Start;
    case 'p':
      return Pause;
    case 'q':
      return Terminate;
    case KEY_LEFT:
      return Left;
    case KEY_RIGHT:
      return Right;
    case KEY_DOWN:
      return Down;
    case KEY_UP:
      return Up;
    case 'r':
      return Action;
    default:
      return NoAction;
      break;
  }
}

void printHello() {
  clear();  // Очистить экран перед повторным отображением сообщения
  printw("HELLO\n");
  printw("Welcome to Brick's Game!\nPress 's' to start playing Snake.");
}

void printStart() {
  clear();  // Очистить экран перед повторным отображением сообщения
  printw("STARTED\n");
}