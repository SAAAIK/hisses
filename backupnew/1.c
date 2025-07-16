  #include "gui/cli/cli.h"
  #include "brick_game/tetris/tetris_game.h"
  
int main() {
    GameInfo_t gameInfo;
    initGame(&gameInfo);
    setNextPieceType(&gameInfo, I); // Задаем тип фигуры I явно

    // Ваш остальной код остается без изменений
    // Размещаем фигуру I на поле
    // gameInfo.currentPiece.type = I; // Теперь это не нужно

    // заполняем матрицу поля: 1 строка единицами, кроме первого столбца
    for (int j = 0; j < BOARD_WIDTH; j++) {
        gameInfo.field[19][j] = 1;
    }

    // Поворачиваем фигуру I, убираем влево и опускаем вниз
    rotatePiece(&gameInfo);
    for (int i = 0; i < 10; i++) movePieceLeft(&gameInfo);
    for (int i = 0; i < 20; i++) movePieceDown(&gameInfo);

    // Вывод игрового поля и счета
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 10; ++j) {
            printf("%d", gameInfo.field[i][j]);
        }
        printf("\n");
    }
    printf("Score: %d\n", gameInfo.score);

    // Освобождение ресурсов
    freeGameResources(&gameInfo);

    return 0;
}
