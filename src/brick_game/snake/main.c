#include "snake_game_start.h"

int main() 
{
    clock_t lastDropTime = clock();
//    double dropInterval = 2000000.; // Интервал падения (скорость)

    Snake snake = {0};
    init_snake(&snake, 5, 10);

    while (1)
    {if (clock() - lastDropTime >= DROP_INTERVAL) {
          //movePieceDown(&gameInfo); // заменить на прод. движения змейки
          lastDropTime = clock();
          clear();
          print_field(&snake);
          refresh();
          //dropInterval = 2000000.;
        }
        //print_field(&snake);
        }
  endwin();
    return 0;
}