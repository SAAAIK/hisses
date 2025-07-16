#include "snake_lib.h"
#include "fsm.h"

void userInput(UserAction_t user_input, bool hold) {
  (void)hold; // заглушка так как в данной версии brickgame параметр hold нам не нужен
  GameInfoExt_t *game_inf_ext = GetCurrentGameInfoExt();
  if (!game_info_ext->new_input) {
    game_info_ext->input = user_input;
    game_info_ext->new_input = true;
  }
}

GameInfo_t updateCurrentState() {
  GameInfoExt_t *game_info_ext = GetCurrentGameInfoExt();
  FiniteStateMachine(game_info_ext);
  return game_info_ext->game_info;
}