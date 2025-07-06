#include "interface.h"


void renderGame(Controller* controller) {
    // 1. Запрос данных у контроллера (не модели!)
    // 2. Очистка экрана (или частичного перерисовывания)
    clear();

    
    for (int y = 0; y < FIELD_HEIGHT + 2; y++) {
        mvprintw(y, 0, "#");
        mvprintw(y, FIELD_WIDTH + 1, "#");
    }

    // 2. Рисуем змейку
    for (int i = 0; i < state->snake_length; i++) {
        if (i == 0) {
            attron(COLOR_PAIR(HEAD_COLOR));
            mvprintw(state->snake[i].y + 1, state->snake[i].x + 1, "O");
            attroff(COLOR_PAIR(HEAD_COLOR));
        } else {
            attron(COLOR_PAIR(BODY_COLOR));
            mvprintw(state->snake[i].y + 1, state->snake[i].x + 1, "o");
            attroff(COLOR_PAIR(BODY_COLOR));
        }
    }
    // 4. Отрисовка UI (очки, уровень, пауза и т. д.)
    mvprintw(0, 0, "Score: %d", state.score);
    mvprintw(1, 0, "Level: %d", state.level);

    // 5. Обновление экрана
    refresh();
}