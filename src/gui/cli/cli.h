#ifndef C_CLI_H_
#define C_CLI_H_

#include <curses.h>
#include "../../brick_game/snake/snake_lib.h"

void EnableNcurses();
void DisableNcurses();
void FrontendFunc(GameInfo_t game_info);

#endif