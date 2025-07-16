#include "tetris_game.h"

// ==========Функция - инициализация игрового поля
void initGame(GameInfo_t *gameInfo) {
  // Динамическое выделение памяти для игрового поля
  gameInfo->field = malloc(BOARD_HEIGHT * sizeof(int *));

  for (int i = 0; i < BOARD_HEIGHT; i++) {
    gameInfo->field[i] = malloc(BOARD_WIDTH * sizeof(int));
    memset(gameInfo->field[i], 0,
           BOARD_WIDTH * sizeof(int)); // Инициализация нулями
  }

  gameInfo->next = malloc(MAX_BLOCKS * sizeof(int *));
  for (int i = 0; i < MAX_BLOCKS; i++) {
    gameInfo->next[i] = malloc(MAX_BLOCKS * sizeof(int));
  }

  gameInfo->level = 1;
  gameInfo->speed = 1; // Начальная скорость
  gameInfo->pause = 0; // Игра не на паузе

  // Генерируем рандомную фигуру в next
  generateNextPiece(gameInfo->next, gameInfo);
  spawnNewPiece(gameInfo);
}

// ==========Функция для генерации рандомной фигуры
void generateNextPiece(int **next, GameInfo_t *gameInfo) {
  // Очистка матрицы фигуры
  for (int i = 0; i < MAX_BLOCKS; i++) {
    memset(next[i], 0, MAX_BLOCKS * sizeof(int));
  }

  // Выбор случайного типа фигуры
  gameInfo->nextPieceType = rand() % 7; // Семь возможных фигур
  //   gameInfo->nextPieceType = 0;  // Семь возможных фигур

  // Заполнение матрицы в зависимости от типа фигуры
  switch (gameInfo->nextPieceType) {
  case I:
    next[0][0] = next[0][1] = next[0][2] = next[0][3] = 1;
    break;
  case J:
    next[0][0] = next[1][0] = next[1][1] = next[1][2] = 1;
    break;
  case L:
    next[0][2] = next[1][0] = next[1][1] = next[1][2] = 1;
    break;
  case O:
    next[0][1] = next[0][2] = next[1][1] = next[1][2] = 1;
    break;
  case S:
    next[0][1] = next[0][2] = next[1][0] = next[1][1] = 1;
    break;
  case T:
    next[0][1] = next[1][0] = next[1][1] = next[1][2] = 1;
    break;
  case Z:
    next[0][0] = next[0][1] = next[1][1] = next[1][2] = 1;
    break;
  }
}

void spawnNewPiece(GameInfo_t *gameInfo) { // ++
  // Инициализация текущей фигуры
  gameInfo->currentPiece.type =
      gameInfo->nextPieceType; // Установка типа текущей фигуры
  // gameInfo->currentPiece.orientation = 0;  // Начальная ориентация // ??
  // можно убирать
  gameInfo->currentPiece.position_x =
      BOARD_WIDTH / 2 - 2; // Центр поля по горизонтали
  gameInfo->currentPiece.position_y = 0; // Верх поля. текущая граница

  // Поэлементное копирование формы следующей фигуры в currentPiece.shape
  for (int i = 0; i < MAX_BLOCKS; i++) {
    for (int j = 0; j < MAX_BLOCKS; j++) {
      gameInfo->currentPiece.shape[i][j] = gameInfo->next[i][j];
    }
  }

  // Размещаем текущую фигуру на игровом поле
  placePieceOnField(gameInfo, &gameInfo->currentPiece); // ++

  // Генерируем новую следующую фигуру
  generateNextPiece(gameInfo->next, gameInfo); // ++
}

void placePieceOnField(GameInfo_t *gameInfo, Tetromino *tetromino) { // ++
  // Размещаем фигуру на игровом поле согласно ее текущему положению и форме
  for (int i = 0; i < MAX_BLOCKS; i++) {
    for (int j = 0; j < MAX_BLOCKS; j++) {
      if (tetromino->shape[i][j] == 1) {
        int x = tetromino->position_x + j;
        int y = tetromino->position_y + i;
        if (x >= 0 && x < BOARD_WIDTH && y >= 0 && y < BOARD_HEIGHT) {
          gameInfo->field[y][x] = 1;
        }
      }
    }
  }
}

void movePieceDown(GameInfo_t *gameInfo) { // -
  // Удаление текущего положения фигуры с игрового поля для проверки
  removePieceFromField(gameInfo);

  // Проверяем, можно ли переместить фигуру вниз
  if (canMove(gameInfo, 0, 1)) { //
    // Перемещение фигуры вниз
    gameInfo->currentPiece.position_y++;

    // Размещение фигуры на новом месте на игровом поле
    placePieceOnField(gameInfo, &gameInfo->currentPiece);
  } else {
    // Возвращаем фигуру на исходное место перед "фиксацией", т.к. перемещение
    // невозможно
    placePieceOnField(gameInfo, &gameInfo->currentPiece);

    // Фигура достигла дна или нашла препятствие, "фиксируем" ее
    fixPiece(gameInfo);

    // Генерация новой фигуры
    spawnNewPiece(gameInfo);
  }
}

int canMove(GameInfo_t *gameInfo, int dx, int dy) { // ++
  for (int i = 0; i < MAX_BLOCKS; i++) {
    for (int j = 0; j < MAX_BLOCKS; j++) {
      if (gameInfo->currentPiece.shape[i][j] == 1) {
        int newX = gameInfo->currentPiece.position_x + j + dx;
        int newY = gameInfo->currentPiece.position_y + i + dy;
        // Проверка на выход за границы игрового поля
        if (newX < 0 || newX >= BOARD_WIDTH || newY >= BOARD_HEIGHT) {
          return 0;
        }
        // Проверка на столкновение с другими фигурами
        if (newY >= 0 && gameInfo->field[newY][newX] == 1) {
          return 0;
        }
      }
    }
  }
  return 1; // Можно переместить
}

void fixPiece(GameInfo_t *gameInfo) { // ++
  // Код для "фиксации" фигуры на игровом поле
  for (int i = 0; i < MAX_BLOCKS; i++) {
    for (int j = 0; j < MAX_BLOCKS; j++) {
      if (gameInfo->currentPiece.shape[i][j] == 1) {
        int x = gameInfo->currentPiece.position_x + j;
        int y = gameInfo->currentPiece.position_y + i;
        if (x >= 0 && x < BOARD_WIDTH && y >= 0 && y < BOARD_HEIGHT) {
          gameInfo->field[y][x] = 1;
        }
      }
    }
  }

  int counter_lines = 0;
  for (int i = 0; i < MAX_BLOCKS; i++) {
    counter_lines += removeFullRows(gameInfo);
  }
  switch (counter_lines) {
  case 0:
    break;
  case 1:
    gameInfo->score += 100;
    break;
  case 2:
    gameInfo->score += 300;
    break;
  case 3:
    gameInfo->score += 700;
    break;
  case 4:
    gameInfo->score += 1500;
    break;

  default:
    break;
  }
  if (gameInfo->level < 10) {
    gameInfo->level = 1 + gameInfo->score / 600;
  }
  for (int j = 0; j < MAX_BLOCKS; j++) {
    int y = gameInfo->currentPiece.position_y + j;
    if (y == 0) { // Проверка касания верхнего потолка
      gameInfo->state = GameState_WaitingStart; // Остановка игры
      return; // Выход из функции
    }
  }
}

// Функция временно удаляет фигуру с игр поля перед проверкой перемещения
void removePieceFromField(GameInfo_t *gameInfo) { // ++
  for (int i = 0; i < MAX_BLOCKS; i++) {
    for (int j = 0; j < MAX_BLOCKS; j++) {
      if (gameInfo->currentPiece.shape[i][j] == 1) {
        gameInfo->field[gameInfo->currentPiece.position_y + i]
                       [gameInfo->currentPiece.position_x + j] = 0;
      }
    }
  }
}

// Функция движения влево
void movePieceLeft(GameInfo_t *gameInfo) { // ++
  // Удаление текущего положения фигуры с игрового поля для проверки
  removePieceFromField(gameInfo);

  // Проверяем, можно ли переместить фигуру влево
  if (canMove(gameInfo, -1, 0)) {
    // Перемещение фигуры влево
    gameInfo->currentPiece.position_x--;

    // Размещение фигуры на новом месте на игровом поле
    placePieceOnField(gameInfo, &gameInfo->currentPiece);
  } else {
    // Возвращаем фигуру на исходное место, т.к. перемещение невозможно
    placePieceOnField(gameInfo, &gameInfo->currentPiece);
  }
}

// Функция движения вправо
void movePieceRight(GameInfo_t *gameInfo) {
  // Удаление текущего положения фигуры с игрового поля для проверки
  removePieceFromField(gameInfo);

  // Проверяем, можно ли переместить фигуру вправо
  if (canMove(gameInfo, 1, 0)) {
    // Перемещение фигуры вправо
    gameInfo->currentPiece.position_x++;

    // Размещение фигуры на новом месте на игровом поле
    placePieceOnField(gameInfo, &gameInfo->currentPiece);
  } else {
    // Возвращаем фигуру на исходное место, т.к. перемещение невозможно
    placePieceOnField(gameInfo, &gameInfo->currentPiece);
  }
}

// Функция вращения
void rotatePiece(GameInfo_t *gameInfo) { // подумать
  int temp[MAX_BLOCKS][MAX_BLOCKS] = {0};
  int size = 4; // Размер матрицы для вращения

  // Удаление фигуры с поля
  removePieceFromField(gameInfo);

  // Вращение матрицы фигуры
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      temp[j][size - i - 1] = gameInfo->currentPiece.shape[i][j];
    }
  }

  // Проверка валидности нового положения
  int isValid = 1;
  for (int i = 0; i < size && isValid; i++) {
    for (int j = 0; j < size; j++) {
      if (temp[i][j] == 1) { // Для каждого блока фигуры
        int newX = gameInfo->currentPiece.position_x + j;
        int newY = gameInfo->currentPiece.position_y + i;
        if (newX < 0 || newX >= BOARD_WIDTH || newY >= BOARD_HEIGHT ||
            gameInfo->field[newY][newX] == 1) {
          isValid = 0; // Новое положение невалидно
          break;
        }
      }
    }
  }

  // Если новое положение валидно, применяем вращение
  if (isValid) {
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        gameInfo->currentPiece.shape[i][j] = temp[i][j];
      }
    }
    // Размещаем фигуру на поле в новой ориентации
    placePieceOnField(gameInfo, &gameInfo->currentPiece);
  } else {
    // Возвращаем фигуру на поле в исходной ориентации, если новое положение
    // невалидно
    placePieceOnField(gameInfo, &gameInfo->currentPiece);
  }
}

// Функция удаления заполненной строки
int removeFullRows(GameInfo_t *gameInfo) { // ++
  int counter_lines = 0; // Строка не удалялась
  for (int y = BOARD_HEIGHT - 1; y >= 0; y--) { // Начинаем проверку снизу вверх
    int rowFull = 1; // Предполагаем, что строка полностью заполнена
    for (int x = 0; x < BOARD_WIDTH; x++) {
      if (gameInfo->field[y][x] == 0) { // Если находим пустую ячейку
        rowFull = 0; // Строка не полностью заполнена
        break; // Прерываем проверку текущей строки
      }
    }

    if (rowFull) { // Если строка полностью заполнена
      counter_lines += 1;
      for (int rowToMoveDown = y; rowToMoveDown > 0; rowToMoveDown--) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
          // Сдвигаем строки вниз
          gameInfo->field[rowToMoveDown][x] =
              gameInfo->field[rowToMoveDown - 1][x];
        }
      }
      // Добавляем новую пустую строку на верх игрового поля
      for (int x = 0; x < BOARD_WIDTH; x++) {
        gameInfo->field[0][x] = 0;
      }
      y++; // После удаления строки повторно проверяем текущую строку,
           // так как она была заменена на строку выше
    }
  }
  return counter_lines;
}

void freeGameResources(GameInfo_t *gameInfo) { // ++
  // Освобождение памяти игрового поля
  if (gameInfo->field != NULL) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
      if (gameInfo->field[i] != NULL) {
        free(gameInfo->field[i]);
      }
    }
    free(gameInfo->field);
    gameInfo->field = NULL;
  }

  // Освобождение памяти матрицы следующей фигуры
  if (gameInfo->next != NULL) {
    for (int i = 0; i < MAX_BLOCKS; i++) {
      if (gameInfo->next[i] != NULL) {
        free(gameInfo->next[i]);
      }
    }
    free(gameInfo->next);
    gameInfo->next = NULL;
  }
}
