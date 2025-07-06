#include "controller.h"

Controller* Controller_init(model* model) {
    Controller* controller = malloc(sizeof(Controller));
    controller->model = model;
    return controller;
}

void Controller_destroy(Controller* controller) {
    free(controller);
}

GameInfo_t* Controller_getGameState(Controller* controller) {
    if (!controller || !controller->model) return NULL;
    return &controller->model->gameInfo;  // Возвращаем указатель на оригинал
}

UserAction_t userInput() {
    int ch = getch(); // Получаем нажатую клавишу
    
    if (ch != ERR) {  // Если была нажата клавиша
        switch (ch) {
            case KEY_UP:
                return UP;
            case KEY_DOWN:
                return DOWN;
            case KEY_LEFT:
                return LEFT;
            case KEY_RIGHT:
                return RIGHT;
            case 'p':
            case 'P':
                return PAUSE;
            case 'q':
            case 'Q':
                return QUIT;
            default:
                return NO_INPUT;
        }
    }
    
    return NO_INPUT; // Если клавиша не нажата
}


void GameLoop() {
    // Инициализация
    initscr();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    
    // Создаем модель и контроллер
    model* model = model_init();
    Controller* controller = Controller_init(model);
    
    while (1) {
        // 1. Обработка ввода
        UserAction_t action = userInput();
        // 2. Обновление модели
        update_model(model, action);
        // 3. Отрисовка
        renderGame(controller);
        // 4. Задержка 100мс
        napms(100); 
        }
    
    // Очистка
    Controller_destroy(controller);
    model_free(model);
    endwin();
}

int main(){
    GameLoop();
    return 1;
};