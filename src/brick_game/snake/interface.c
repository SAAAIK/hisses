#include "interface.h"

void renderGame(Controller* controller) {
    // 1. Получаем состояние через контроллер
    GameInfo_t state = Controller_getGameState(controller);
    
    // 2. Очистка экрана
    clear();
    
    // 3. Отрисовка границ
    for (int y = 0; y < FIELD_HEIGHT + 2; y++) {
        mvprintw(y, 0, "#");
        mvprintw(y, FIELD_WIDTH + 1, "#");
    }
    
    // 4. Отрисовка змейки
    for (int i = 0; i < state.snake_length; i++) {
        if (i == 0) {
            attron(COLOR_PAIR(HEAD_COLOR));
            mvprintw(state.snake[i].y + 1, state.snake[i].x + 1, "O");
            attroff(COLOR_PAIR(HEAD_COLOR));
        } else {
            attron(COLOR_PAIR(BODY_COLOR));
            mvprintw(state.snake[i].y + 1, state.snake[i].x + 1, "o");
            attroff(COLOR_PAIR(BODY_COLOR));
        }
    }
    
    // 5. Отрисовка UI
    mvprintw(0, 0, "Score: %d", state.score);
    mvprintw(1, 0, "Level: %d", state.level);
    
    // 6. Обновление экрана
    refresh();
}