#include "controller.h"

UserAction_t userInput() {
  int ch = getch();

  if (ch != ERR) {  // Если клавиша нажата
    switch (ch) {
      case KEY_UP:
        return KEY_UP;
      case KEY_DOWN:
        return KEY_DOWN;
      case 'p':
        return KEY_PAUSE;
      case 'q':
        return KEY_QUIT;
      default:
        return NO_INPUT;
    }
  }
  else{return NO_INPUT;}
}

void GameLoop() {
  initscr(); // Инициализация ncurses
  nodelay(stdscr, TRUE);
  model_init();

  // View_init();

  while (1) {
    UserAction_t action = userInput(ch);
    updateModel(action);  // Обновляет модель
    renderGame(); // Запрашивает данные у модели через контроллер
    sleep(10);
  }
};

int main() {
  GameLoop();
  return 1;
};





/*
GameState_t Controller_getGameState(GameState_t* controller) {
    GameState_t state;

    // Заполнение данных из модели (контроллер знает, как их получить)
    state.score = Model_getScore(controller->model);
    state.level = Model_getLevel(controller->model);
    state.field = Model_getFieldSnapshot(controller->model); // Копия поля

    return state;
};
*/