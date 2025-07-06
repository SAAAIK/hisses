#include "model.h"

// ==========Функция - инициализация игрового поля
model* model_init()
{ 
    model* model_exec = (model*)malloc(sizeof(model));
     if (!model_exec) return NULL;
    
    model_field_init(model_exec);
    model_snake_init(model_exec);

    //проставить остальные поля
    /*
    typedef struct {
    int **field; // Указатель на игровое поле
    int *snake_p; // Указатель на змейку
    int score;                   // Текущий счет
    int high_score;              // Рекордный счет
    int level;                   // Текущий уровень
    int speed;                   // Скорость падения фигур
    int pause;                   // Состояние паузы игры
    Snake snake;
    Apple apple;
    GameState_t state;           // Текущее состояние игры

    } GameInfo_t;
    */


    printf("1");
    return model_exec;
}

void model_field_init(model* model){
    model->gameInfo.field = (int**)malloc(BOARD_HEIGHT * sizeof(int*));
        if (!model->gameInfo.field) {
            free(model);
            return;
        }
        for (int i = 0; i < BOARD_HEIGHT; i++) {
                model->gameInfo.field[i] = (int*)malloc(BOARD_WIDTH * sizeof(int));
                if (!model->gameInfo.field[i]) {
                    for (int j = 0; j < i; j++) free(model->gameInfo.field[j]);
                    free(model->gameInfo.field);
                    free(model);
                    return;
                }
                memset(model->gameInfo.field[i], 0, BOARD_WIDTH * sizeof(int));
            }
    model->gameInfo.state = Spawn;
    };

void model_snake_init(model* model){
    model->gameInfo.snake.segments = (Segment*)malloc(MAX_LENGTH * sizeof(Segment));
    if (!model->gameInfo.snake.segments) {
        for (int i = 0; i < BOARD_HEIGHT; i++) free(model->gameInfo.field[i]);
        free(model->gameInfo.field);
        free(model);
        return;
    }
    model->gameInfo.snake.length =7;
    model->gameInfo.snake.dir_x =-1;
    model->gameInfo.snake.dir_y =-1;
    memset(model->gameInfo.snake.segments, 0, MAX_LENGTH * sizeof(Segment));
    };



void model_free(model* model) {
    if (!model) return;
    // Освобождаем поле
    if (model->gameInfo.field) {
        for (int i = 0; i < BOARD_HEIGHT; i++) {
            if (model->gameInfo.field[i]) free(model->gameInfo.field[i]);
        }
        free(model->gameInfo.field);
    }
    if (model->gameInfo.snake.segments) free(model->gameInfo.snake.segments);
    free(model);
};