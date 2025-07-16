#include "cli.h"

static void PrintBorder();
static void PrintStats(GameInfo_t game_info);
static void PrintField(GameInfo_t game_info);
static void PrintGameOver();
static void PrintPause();
static void PrintStartScreen();
static void PrintControlKeys();

void FrontendFunc(GameInfo_t game_info) {
  clear();
  if (game_info.field == NULL){
    //PrintStats(game_info);
    PrintStartScreen();}
  else {
    PrintStats(game_info);
    PrintField(game_info);
  }
  if (game_info.pause == 1) {
    PrintPause();
  }
  if (game_info.pause == 2) {
    PrintGameOver();
  }
  PrintControlKeys();
  PrintBorder();
  refresh();
}

void EnableNcurses() {
  initscr();
  curs_set(0);
  cbreak();
  halfdelay(1);
  keypad(stdscr, TRUE);
}

void DisableNcurses() { endwin(); }

static void PrintBorder() {
  const char border = '|';
  int row = 22, col = 22;
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++) {
      if (i == 0) {
        mvaddch(i, j, border);
      }
      if (i == row - 1) {
        mvaddch(i, j, border);
      }
      if (j == 0 && i > 0) {
        mvaddch(i, j, border);
      }
      if (j == col - 1 && i > 0) {
        mvaddch(i, j, border);
      }
    }
}

static void PrintStats(GameInfo_t game_info) {
  mvaddstr(0, 24, "Score");
  mvprintw(1, 24, "%d", game_info.score);

  mvaddstr(2, 24, "Debug");
  mvprintw(3, 24, "%d", game_info.mem_alloc);

  //mvaddstr(2, 24, "High Score");
  //mvprintw(3, 24, "%d", game_info.high_score);

  mvaddstr(4, 24, "Level");
  mvprintw(5, 24, "%d", game_info.level);

  mvaddstr(6, 24, "Speed");
  mvprintw(7, 24, "%d", game_info.speed);

  // mvaddstr(9, 25, "Next");
  // for (int i = 0; i < 2; i++)
  //   for (int j = 0; j < 4; j++)
  //     if (game_info.next[i][j] == 1) {
  //       mvaddch(i + 11, j * 2 + 24, '[');
  //       mvaddch(i + 11, j * 2 + 25, ']');
  //     }
}

static void PrintField(GameInfo_t game_info) {
  for (int i = 0; i < 20; i++)
    for (int j = 0; j < 10; j++)
      if (game_info.field[i][j] == 1) {
        mvaddch(i + 1, j * 2 + 1, '[');
        mvaddch(i + 1, j * 2 + 2, ']');
      }
}

static void PrintStartScreen() { mvaddstr(10, 2, "Press 's' to start"); }

static void PrintControlKeys() {
  mvaddstr(14, 24, "s - start");
  mvaddstr(15, 24, "t - exit(terminate)");
  mvaddstr(16, 24, "a - action");
  mvaddstr(17, 24, "p - pause, unpause");
  mvaddstr(18, 24, "<-,->  - left and right move");
  mvaddstr(19, 24, "down arrow  - fast move down");
}

static void PrintGameOver() {
  mvaddstr(9, 1, "____________________");
  mvaddstr(10, 7, "GAME OVER");
  mvaddstr(11, 1, "____________________");
  mvaddstr(12, 1, "Press 's' to restart");
  mvaddstr(13, 1, "____________________");
}

static void PrintPause() {
  mvaddstr(9, 1, "____________________");
  mvaddstr(10, 8, "Pause");
  mvaddstr(11, 1, "____________________");
  mvaddstr(12, 1, "Press 'p' to resume");
  mvaddstr(13, 1, "____________________");
}