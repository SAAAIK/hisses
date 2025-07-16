#ifndef FSM_H
#define FSM_H

#define PLAYING 0
#define PAUSE 1
#define GAMEOVER 2
#define EXITING 3

#include "snake_game_start.h"

GameInfoExt_t *GetCurrentGameInfoExt();
void FiniteStateMachine(GameInfoExt_t *game_info_ext);

#endif