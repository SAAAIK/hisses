#include "snake.h"

int main(){
  printf("1");
  EnableNcurses();
  game_loop();
  DisableNcurses();
  return 0;
}

void game_loop()
{
  GameInfo_t game_info = {0};
  while(game_info.pause != 3)
  {
    game_info = updateCurrentState();
    FrontendFunc(game_info);
    UserInputToUserAction(getch());
    //napms(1000);
  }
}