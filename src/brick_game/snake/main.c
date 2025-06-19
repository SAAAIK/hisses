#include "snake_game_start.h"

int main() 
{
    clock_t lastDropTime = clock();
//    double dropInterval = 2000000.; // Интервал падения (скорость)

    GameInfo_t gameInfo;
    initGame(&gameInfo);

    while (1)
    {if (clock() - lastDropTime >= DROP_INTERVAL) {
          move_snake(&gameInfo); // заменить на прод. движения змейки
          lastDropTime = clock();
          clear();
          print_field(&gameInfo, &gameInfo.snake);
          refresh();
          //dropInterval = 2000000.;
        }
        //print_field(&gameInfo->snake;
        }
  endwin();
    return 0;
}