#include "../../brick_game/tetris/tetris_game.h"
#include "cli.h"

void printField(GameInfo_t *gameInfo) {
  // Отрисовка верхней границы поля
  for (int x = -1; x <= BOARD_WIDTH * 2; x++) {
    mvprintw(0, x + 1, "-");
  }
  for (int y = 0; y < BOARD_HEIGHT; y++) {
    // Отрисовка левой границы поля
    mvprintw(y + 1, 0, "]");

    for (int x = 0; x < BOARD_WIDTH; x++) {
      // Используем символ '#' для заполненной ячейки и пробел для пустой
      mvprintw(y + 1, x * 2 + 1, "%c", gameInfo->field[y][x] ? '#' : ' ');
    }

    // Отрисовка правой границы поля
    mvprintw(y + 1, BOARD_WIDTH * 2 + 1, "[");
  }

  // Отрисовка нижней границы поля
  for (int x = -1; x <= BOARD_WIDTH * 2; x++) {
    mvprintw(BOARD_HEIGHT + 1, x + 1, "-");
  }
  // Отрисовка боковой панели
  int panelX = BOARD_WIDTH * 2 + 4; // Стартовая X-координата боковой панели
  // start color
  init_pair(1, COLOR_RED, COLOR_BLACK);
  attron(COLOR_PAIR(1));
  mvprintw(1, panelX, "Next piece:");
  attroff(COLOR_PAIR(1));

  // Отрисовка следующей фигуры
  for (int i = 0; i < MAX_BLOCKS; i++) {
    for (int j = 0; j < MAX_BLOCKS; j++) {
      if (gameInfo->next[i][j] == 1) {
        // Для упрощения визуализации используем символ '#'
        mvprintw(4 + i, panelX + j * 2, "#");
      } else {
        // Очистка места, где фигура не занимает позицию
        mvprintw(4 + i, panelX + j * 2, "  ");
      }
    }
  }
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK); // Определение цветовой пары №1:
                                        // красный текст на черном фоне

  attron(COLOR_PAIR(1)); // Включение цветовой пары №1
  mvprintw(7, panelX, "Score: ");
  attroff(COLOR_PAIR(1)); // Выключение цветовой пары

  mvprintw(7, panelX + 7, "%d", gameInfo->score); // Вывод счёта
  attron(COLOR_PAIR(1));
  mvprintw(9, panelX, "Level:  %d", gameInfo->level); // Вывод уровня
  attroff(COLOR_PAIR(1));
  mvprintw(9, panelX + 7, "Level: %d", gameInfo->level);
  // mvprintw(11, panelX, "Restart: 's'");               // дебаг тест
  printTopScores();
}

void printHello() {
  clear(); // Очистить экран перед повторным отображением сообщения
  printw("HELLO\n");
  printw("Welcome to Brick's Game!\nPress 's' to start playing Tetris.");
}

void printPauseScreen() {
  mvprintw(BOARD_HEIGHT + 2, 0, "The game is paused. Press \"p\" to continue.");

  refresh();
}
