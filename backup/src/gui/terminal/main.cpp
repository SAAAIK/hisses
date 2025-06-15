#include "cli.h"

int main() {

printField(&gameInfo);

  /*char playerName[50];  // Оставляем место для символа окончания строки
  printf("Enter your name: ");
  fgets(playerName, sizeof(playerName), stdin);
  // Удаление символа новой строки, если он присутствует
  playerName[strcspn(playerName, "\n")] = 0;
  initPlayerScore(playerName); 
  GameInfo_t gameInfo;
  //clock_t lastDropTime = clock();
  //double dropInterval = 200000.;  // Интервал падения (скорость)

  //bool start_pressed = false;  // Флаг что было нажато s
  //bool hold = false;           // Флаг зажатой клавиши
  //bool flag_while = true;
initializeGame(&gameInfo);
printField(&gameInfo);

  while (flag_while) {
    if (!start_pressed) printHello();
    int ch = getch();
    UserAction_t action = getUserAction(ch, &start_pressed, &gameInfo);

    // Если игра не запущена и не была запущена, показать начальный экран
    printFirstScreen(&start_pressed, gameInfo, action);

    if (start_pressed) {
      userInput(&gameInfo, action, hold);  // Обработка ввода пользователя
      switch (gameInfo.state) {
        case GameState_WaitingStart:
          processGameWaiting(&start_pressed, &gameInfo);
          break;
        case GameState_Running:
          start_pressed = true;
          // Движение фигуры вниз
          if (clock() - lastDropTime >= dropInterval) {
            movePieceDown(&gameInfo);
            lastDropTime = clock();
            clear();
            printField(&gameInfo);
            refresh();
            dropInterval = 200000. / gameInfo.level;
          }
          printField(&gameInfo);
          break;
        case GameState_Paused:
          printPauseScreen();
          break;
        case GameState_Over:
          processGameOver(&flag_while, &gameInfo);
          break;
      }
      updateLastLine(playerName, gameInfo.score);
    }
  }
  endwin();
  return 0;
}

void processGameWaiting(bool *start_pressed,
                        GameInfo_t *gameInfo) {  // пока неясно зачем это нужно
  *start_pressed = false;
  freeGameResources(gameInfo);  //
}

void processGameOver(bool *flag_while,
                     GameInfo_t *gameInfo) {  // не нужно писать game_over
  clear();
  *flag_while = false;
  freeGameResources(gameInfo);
}
void printFirstScreen(bool *start_pressed, GameInfo_t gameInfo,
                      UserAction_t action) {
  if (!(*start_pressed) && gameInfo.state == GameState_WaitingStart) {
    printHello();
    if (action == Terminate)
      *start_pressed = true;  // вот этой строки у меня нет
  }
} 

void initializeGame(GameInfo_t *gameInfo) {
  srand(time(NULL));
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);

  gameInfo->state = GameState_WaitingStart;
}


UserAction_t getUserAction(int ch, bool *start_pressed, GameInfo_t *gameInfo) {
  switch (ch) {
    case 's':
      if (*start_pressed)
        freeGameResources(gameInfo);  // Чтобы ощишать память с влучае рестарта
                                      // игры во время ее исполнения
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
    case 'r':
      return Action;
    default:
      return NoAction;
  }
}
*/