#ifndef SNAKE_CONTROLLER_H
#define SNAKE_CONTROLLER_H

#include "interface.h"
#include "model.h"

typedef struct {
    model* model;
} Controller;

Controller* Controller_init(model* model);
void Controller_destroy(Controller* controller);
GameInfo_t* Controller_getGameState(Controller* controller);
void GameLoop();
UserAction_t userInput();
//void Controller_handleInput(Controller* controller, UserAction_t action);

#endif