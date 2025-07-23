#ifndef FSM_H
#define FSM_H

#include "snake_backend.h"

GameInfoExt_t *GetCurrentGameInfoExt();
void FiniteStateMachine(GameInfoExt_t *game_info_ext);

#endif