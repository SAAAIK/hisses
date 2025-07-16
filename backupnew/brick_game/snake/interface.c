#include "interface.h"
#include "controller.h"
#include <ncurses.h>



void renderGame(Controller* controller) {
    // 1. Получаем состояние через контроллер
    GameInfo_t state = Controller_getGameState(controller);
    
    // 2. Очистка экрана
    clear();
    
    // 3. Отрисовка границ
    for (int y = 0; y < IBOARD_HEIGHT+ 2; y++) {
        mvprintw(y, 0, "$");
        mvprintw(y, IBOARD_WIDTH+ 1, "#");
    }

    if (state.state == Spawn){
         mvprintw(5, IBOARD_WIDTH/2, "SPAWN");
    }
    /*
    // 4. Отрисовка змейки
    for (int i = 0; i < state.snake.length; i++) {
        if (i == 0) {
            attron(COLOR_PAIR(HEAD_COLOR));
            mvprintw(state.snake.segments[i].y + 1, state.snake.segments[i].x + 1, "O");
            attroff(COLOR_PAIR(HEAD_COLOR));
        } else {
            attron(COLOR_PAIR(BODY_COLOR));
            mvprintw(state.snake.segments[i].y + 1, state.snake.segments[i].x + 1, "o");
            attroff(COLOR_PAIR(BODY_COLOR));
        }
    }
    */
    // 5. Отрисовка UI
    mvprintw(0, 100, "Score: %d", state.score);
    mvprintw(1, 100, "Level: %d", state.level);
    mvprintw(2, 100, "State: %d", state.state);
    
    // 6. Обновление экрана
    refresh();
    napms(100); 
}