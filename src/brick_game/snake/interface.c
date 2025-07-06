#include "interface.h"


void renderGame(Controller* controller) {
    // 1. Запрос данных у контроллера (не модели!)
    GameState_t state = Controller_getGameState(controller);

    // 2. Очистка экрана (или частичного перерисовывания)
    clear();

    // 3. Отрисовка игрового поля на основе state
    for (int y = 0; y < state.fieldHeight; y++) {
        for (int x = 0; x < state.fieldWidth; x++) {
            char cell = state.field[y][x];
            mvaddch(y, x, cell); // NCurses-функция для отрисовки символа
        }
    }

    // 4. Отрисовка UI (очки, уровень, пауза и т. д.)
    mvprintw(0, 0, "Score: %d", state.score);
    mvprintw(1, 0, "Level: %d", state.level);

    // 5. Обновление экрана
    refresh();
}