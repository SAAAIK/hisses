#include "snake_game_start.h"

void initializeGame(GameInfo_t *gameInfo);
UserAction_t getUserAction(int ch /* bool *start_pressed, GameInfo_t *gameInfo*/);
void printField(GameInfo_t *gameInfo);

void userInput(GameInfo_t *gameInfo, UserAction_t action /*, bool hold*/)
{
  // В этом примере параметр hold не используется
  //   if (hold) { // hold - при зажатии клавиши вниз фигура телепортируется ?
  //     printf("1");
  //   }
  switch (action)
  {
  /*case Start:
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
    gameInfo->pause = !gameInfo->pause; // вместо true/false
    break;
  case Terminate:
    gameInfo->state = GameState_Over;
    break;*/
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
  case Up:
    if (!gameInfo->pause)
      movePieceUp(gameInfo);
    break;
    /*  case Action:
        if (!gameInfo->pause)
          rotatePiece(gameInfo); // Поворот фигуры
        break;*/
  case NoAction:
    break;
  }
}

int main()
{
  clock_t lastDropTime = clock();
  double dropInterval = 2000000.; // Интервал падения (скорость)

  GameInfo_t gameInfo;
  initializeGame(&gameInfo);
  initGame(&gameInfo);

  while (1)
  {
    int ch = getch();
    UserAction_t action = getUserAction(ch /*&start_pressed, &gameInfo*/);
    userInput(&gameInfo, action /*, hold*/);
    if (clock() - lastDropTime >= dropInterval)
    {
      move_snake(&gameInfo); // заменить на прод. движения змейки
      lastDropTime = clock();
      clear();
      printField(&gameInfo);
      refresh();
      printf("\n%d\n", canMove(&gameInfo));
      dropInterval = 2000000.;
    }
    //printField(&gameInfo);
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

void initializeGame(GameInfo_t *gameInfo)
{
  srand(time(NULL));
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);

  gameInfo->state = GameState_Running /*WaitingStart*/;
}

UserAction_t getUserAction(int ch /* bool *start_pressed, GameInfo_t *gameInfo*/)
{
  switch (ch)
  {
  /*case 's':
    if (*start_pressed)
      freeGameResources(gameInfo); // Чтобы ощишать память с влучае рестарта
                                   // игры во время ее исполнения
    *start_pressed = true;
    return Start;
  case 'p':
    return Pause;
  case 'q':
    return Terminate;*/
  case KEY_LEFT:
    return Left;
  case KEY_RIGHT:
    return Right;
  case KEY_DOWN:
    return Down;
  case KEY_UP:
    return Up;
  /*case 'r':
    return Action;*/
  default:
    return NoAction;
  }
}