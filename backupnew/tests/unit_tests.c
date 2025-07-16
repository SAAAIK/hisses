#include "tests.h"

START_TEST(initGame_test_1) {
  GameInfo_t gameInfo;
  initGame(&gameInfo);

  int count_field = 0;

  for (int i = 0; i < MAX_BLOCKS; i++) {
    for (int j = 0; j < BOARD_WIDTH; j++) {
      count_field += gameInfo.field[i][j];
    }
  }

  ck_assert_int_eq(count_field, 4);
  ck_assert_int_eq(gameInfo.score, 0);
  ck_assert_int_eq(gameInfo.high_score, 0);
  ck_assert_int_eq(gameInfo.level, 1);
  ck_assert_int_eq(gameInfo.speed, 1);
  ck_assert_int_eq(gameInfo.pause, 0);

  int count_next = 0;
  for (int i = 0; i < MAX_BLOCKS; i++) {
    for (int j = 0; j < MAX_BLOCKS; j++) {
      count_next += gameInfo.next[i][j];
    }
  }
  ck_assert_int_eq(count_next, 4);

  freeGameResources(&gameInfo);
}
END_TEST

START_TEST(initGame_test_2) {
  GameInfo_t gameInfo;
  initGame(&gameInfo);

  int count_field = 0;

  for (int i = 0; i < MAX_BLOCKS; i++) {
    for (int j = 0; j < BOARD_WIDTH; j++) {
      count_field += gameInfo.field[i][j];
    }
  }
  for (int k = 0; k < 200; k++) {
    movePieceDown(&gameInfo);
  }

  ck_assert_int_eq(count_field, 4);
  ck_assert_int_eq(gameInfo.score, 0);
  ck_assert_int_eq(gameInfo.high_score, 0);
  ck_assert_int_eq(gameInfo.level, 1);
  ck_assert_int_eq(gameInfo.speed, 1);
  ck_assert_int_eq(gameInfo.pause, 0);

  int count_next = 0;
  for (int i = 0; i < MAX_BLOCKS; i++) {
    for (int j = 0; j < MAX_BLOCKS; j++) {
      count_next += gameInfo.next[i][j];
    }
  }
  ck_assert_int_eq(count_next, 4);

  freeGameResources(&gameInfo);
}
END_TEST

START_TEST(initGame_test_3) {
  GameInfo_t gameInfo;
  initGame(&gameInfo);

  int count_field = 0;

  for (int i = 0; i < MAX_BLOCKS; i++) {
    for (int j = 0; j < BOARD_WIDTH; j++) {
      count_field += gameInfo.field[i][j];
    }
  }

  ck_assert_int_eq(count_field, 4);
  ck_assert_int_eq(gameInfo.score, 0);
  ck_assert_int_eq(gameInfo.high_score, 0);
  ck_assert_int_eq(gameInfo.level, 1);
  ck_assert_int_eq(gameInfo.speed, 1);
  ck_assert_int_eq(gameInfo.pause, 0);

  int count_next = 0;
  for (int i = 0; i < MAX_BLOCKS; i++) {
    for (int j = 0; j < MAX_BLOCKS; j++) {
      count_next += gameInfo.next[i][j];
    }
  }
  ck_assert_int_eq(count_next, 4);

  freeGameResources(&gameInfo);
}
END_TEST

START_TEST(initGame_test_4) {
  GameInfo_t gameInfo;
  initGame(&gameInfo);

  int count_field = 0;

  for (int i = 0; i < MAX_BLOCKS; i++) {
    for (int j = 0; j < BOARD_WIDTH; j++) {
      count_field += gameInfo.field[i][j];
    }
  }

  ck_assert_int_eq(count_field, 4);
  ck_assert_int_eq(gameInfo.score, 0);
  ck_assert_int_eq(gameInfo.high_score, 0);
  ck_assert_int_eq(gameInfo.level, 1);
  ck_assert_int_eq(gameInfo.speed, 1);
  ck_assert_int_eq(gameInfo.pause, 0);

  int count_next = 0;
  for (int i = 0; i < MAX_BLOCKS; i++) {
    for (int j = 0; j < MAX_BLOCKS; j++) {
      count_next += gameInfo.next[i][j];
    }
  }
  ck_assert_int_eq(count_next, 4);

  freeGameResources(&gameInfo);
}
END_TEST

START_TEST(initGame_test_5) {
  GameInfo_t gameInfo;
  initGame(&gameInfo);

  int count_field = 0;

  for (int i = 0; i < MAX_BLOCKS; i++) {
    for (int j = 0; j < BOARD_WIDTH; j++) {
      count_field += gameInfo.field[i][j];
    }
  }

  ck_assert_int_eq(count_field, 4);
  ck_assert_int_eq(gameInfo.score, 0);
  ck_assert_int_eq(gameInfo.high_score, 0);
  ck_assert_int_eq(gameInfo.level, 1);
  ck_assert_int_eq(gameInfo.speed, 1);
  ck_assert_int_eq(gameInfo.pause, 0);

  int count_next = 0;
  for (int i = 0; i < MAX_BLOCKS; i++) {
    for (int j = 0; j < MAX_BLOCKS; j++) {
      count_next += gameInfo.next[i][j];
    }
  }
  ck_assert_int_eq(count_next, 4);

  freeGameResources(&gameInfo);
}
END_TEST

START_TEST(initGame_test_6) {
  GameInfo_t gameInfo;
  initGame(&gameInfo);

  int count_field = 0;

  for (int i = 0; i < MAX_BLOCKS; i++) {
    for (int j = 0; j < BOARD_WIDTH; j++) {
      count_field += gameInfo.field[i][j];
    }
  }

  ck_assert_int_eq(count_field, 4);
  ck_assert_int_eq(gameInfo.score, 0);
  ck_assert_int_eq(gameInfo.high_score, 0);
  ck_assert_int_eq(gameInfo.level, 1);
  ck_assert_int_eq(gameInfo.speed, 1);
  ck_assert_int_eq(gameInfo.pause, 0);

  int count_next = 0;
  for (int i = 0; i < MAX_BLOCKS; i++) {
    for (int j = 0; j < MAX_BLOCKS; j++) {
      count_next += gameInfo.next[i][j];
    }
  }
  ck_assert_int_eq(count_next, 4);

  freeGameResources(&gameInfo);
}
END_TEST

START_TEST(initGame_test_7) {
  GameInfo_t gameInfo;
  initGame(&gameInfo);

  int count_field = 0;

  for (int i = 0; i < MAX_BLOCKS; i++) {
    for (int j = 0; j < BOARD_WIDTH; j++) {
      count_field += gameInfo.field[i][j];
    }
  }

  ck_assert_int_eq(count_field, 4);
  ck_assert_int_eq(gameInfo.score, 0);
  ck_assert_int_eq(gameInfo.high_score, 0);
  ck_assert_int_eq(gameInfo.level, 1);
  ck_assert_int_eq(gameInfo.speed, 1);
  ck_assert_int_eq(gameInfo.pause, 0);

  int count_next = 0;
  for (int i = 0; i < MAX_BLOCKS; i++) {
    for (int j = 0; j < MAX_BLOCKS; j++) {
      count_next += gameInfo.next[i][j];
    }
  }
  ck_assert_int_eq(count_next, 4);

  freeGameResources(&gameInfo);
}
END_TEST

START_TEST(initGame_test_8) {
  GameInfo_t gameInfo;
  initGame(&gameInfo);

  int count_field = 0;

  for (int i = 0; i < MAX_BLOCKS; i++) {
    for (int j = 0; j < BOARD_WIDTH; j++) {
      count_field += gameInfo.field[i][j];
    }
  }

  ck_assert_int_eq(count_field, 4);
  ck_assert_int_eq(gameInfo.score, 0);
  ck_assert_int_eq(gameInfo.high_score, 0);
  ck_assert_int_eq(gameInfo.level, 1);
  ck_assert_int_eq(gameInfo.speed, 1);
  ck_assert_int_eq(gameInfo.pause, 0);

  int count_next = 0;
  for (int i = 0; i < MAX_BLOCKS; i++) {
    for (int j = 0; j < MAX_BLOCKS; j++) {
      count_next += gameInfo.next[i][j];
    }
  }
  ck_assert_int_eq(count_next, 4);

  freeGameResources(&gameInfo);
}
END_TEST

START_TEST(initGame_test_9) {
  GameInfo_t gameInfo;
  initGame(&gameInfo);

  int count_field = 0;

  for (int i = 0; i < MAX_BLOCKS; i++) {
    for (int j = 0; j < BOARD_WIDTH; j++) {
      count_field += gameInfo.field[i][j];
    }
  }

  ck_assert_int_eq(count_field, 4);
  ck_assert_int_eq(gameInfo.score, 0);
  ck_assert_int_eq(gameInfo.high_score, 0);
  ck_assert_int_eq(gameInfo.level, 1);
  ck_assert_int_eq(gameInfo.speed, 1);
  ck_assert_int_eq(gameInfo.pause, 0);

  int count_next = 0;
  for (int i = 0; i < MAX_BLOCKS; i++) {
    for (int j = 0; j < MAX_BLOCKS; j++) {
      count_next += gameInfo.next[i][j];
    }
  }
  ck_assert_int_eq(count_next, 4);

  freeGameResources(&gameInfo);
}
END_TEST

START_TEST(initGame_test_10) {
  GameInfo_t gameInfo;
  initGame(&gameInfo);

  int count_field = 0;

  for (int i = 0; i < MAX_BLOCKS; i++) {
    for (int j = 0; j < BOARD_WIDTH; j++) {
      count_field += gameInfo.field[i][j];
    }
  }

  ck_assert_int_eq(count_field, 4);
  ck_assert_int_eq(gameInfo.score, 0);
  ck_assert_int_eq(gameInfo.high_score, 0);
  ck_assert_int_eq(gameInfo.level, 1);
  ck_assert_int_eq(gameInfo.speed, 1);
  ck_assert_int_eq(gameInfo.pause, 0);

  int count_next = 0;
  for (int i = 0; i < MAX_BLOCKS; i++) {
    for (int j = 0; j < MAX_BLOCKS; j++) {
      count_next += gameInfo.next[i][j];
    }
  }
  ck_assert_int_eq(count_next, 4);

  freeGameResources(&gameInfo);
}
END_TEST

START_TEST(movePieceDown_test_1) {
  GameInfo_t gameInfo;
  initGame(&gameInfo);
  movePieceDown(&gameInfo);

  int count_first_str = 0;

  for (int i = 0; i < BOARD_WIDTH; i++) {
    count_first_str += gameInfo.field[0][i];
  }
  ck_assert_int_eq(count_first_str, 0);
  int count_field = 0;

  for (int i = 1; i < MAX_BLOCKS; i++) {
    for (int j = 0; j < BOARD_WIDTH; j++) {
      count_field += gameInfo.field[i][j];
    }
  }

  ck_assert_int_eq(count_field, 4);
  ck_assert_int_eq(gameInfo.score, 0);
  ck_assert_int_eq(gameInfo.high_score, 0);
  ck_assert_int_eq(gameInfo.level, 1);
  ck_assert_int_eq(gameInfo.speed, 1);
  ck_assert_int_eq(gameInfo.pause, 0);

  int count_next = 0;
  for (int i = 0; i < MAX_BLOCKS; i++) {
    for (int j = 0; j < MAX_BLOCKS; j++) {
      count_next += gameInfo.next[i][j];
    }
  }
  ck_assert_int_eq(count_next, 4);

  freeGameResources(&gameInfo);
}
END_TEST

START_TEST(movePieceDown_and_left_test_2) {
  GameInfo_t gameInfo;
  initGame(&gameInfo);
  //   int prev_next[4][4] = gameInfo.next;
  for (int i = 0; i < 40; i++) {
    movePieceDown(&gameInfo);
  }

  for (int i = 0; i < 8; i++) {
    movePieceLeft(&gameInfo);
  }

  int count_field = 0;

  for (int i = 0; i < BOARD_HEIGHT; i++) {
    for (int j = 0; j < BOARD_WIDTH; j++) {
      count_field += gameInfo.field[i][j];
    }
  }

  ck_assert_int_eq(count_field, 12);
  ck_assert_int_eq(gameInfo.score, 0);
  ck_assert_int_eq(gameInfo.high_score, 0);
  ck_assert_int_eq(gameInfo.level, 1);
  ck_assert_int_eq(gameInfo.speed, 1);
  ck_assert_int_eq(gameInfo.pause, 0);

  int count_next = 0;
  for (int i = 0; i < MAX_BLOCKS; i++) {
    for (int j = 0; j < MAX_BLOCKS; j++) {
      count_next += gameInfo.next[i][j];
    }
  }
  ck_assert_int_eq(count_next, 4);

  freeGameResources(&gameInfo);
}
END_TEST

START_TEST(movePieceDown_and_right_test_3) {
  GameInfo_t gameInfo;
  initGame(&gameInfo);
  //   int prev_next[4][4] = gameInfo.next;
  for (int i = 0; i < 40; i++) {
    movePieceDown(&gameInfo);
  }

  for (int i = 0; i < 8; i++) {
    movePieceRight(&gameInfo);
  }

  int count_field = 0;

  for (int i = 0; i < BOARD_HEIGHT; i++) {
    for (int j = 0; j < BOARD_WIDTH; j++) {
      count_field += gameInfo.field[i][j];
    }
  }

  ck_assert_int_eq(count_field, 12);
  ck_assert_int_eq(gameInfo.score, 0);
  ck_assert_int_eq(gameInfo.high_score, 0);
  ck_assert_int_eq(gameInfo.level, 1);
  ck_assert_int_eq(gameInfo.speed, 1);
  ck_assert_int_eq(gameInfo.pause, 0);

  int count_next = 0;
  for (int i = 0; i < MAX_BLOCKS; i++) {
    for (int j = 0; j < MAX_BLOCKS; j++) {
      count_next += gameInfo.next[i][j];
    }
  }
  ck_assert_int_eq(count_next, 4);

  freeGameResources(&gameInfo);
}
END_TEST

START_TEST(score_100_test_1) {
  GameInfo_t gameInfo;
  initGame(&gameInfo);
  // Размещаем фигуру I на поле
  gameInfo.currentPiece.type = I;

  // заполняем матрицу поля: 1 строка единицами, кроме первого столбца
  for (int j = 1; j < BOARD_WIDTH; j++) {
    gameInfo.field[19][j] = 1;
  }

  // Поворачиваем фигуру I, убираем влево и опускаем вниз
  rotatePiece(&gameInfo);
  for (int i = 0; i < 10; i++) movePieceLeft(&gameInfo);
  for (int i = 0; i < 20; i++) movePieceDown(&gameInfo);

  ck_assert_int_eq(gameInfo.score, 100);
  ck_assert_int_eq(gameInfo.high_score, 0);
  ck_assert_int_eq(gameInfo.level, 1);

  freeGameResources(&gameInfo);
}
END_TEST

START_TEST(score_300_test_1) {
  GameInfo_t gameInfo;
  initGame(&gameInfo);
  // Размещаем фигуру I на поле
  gameInfo.currentPiece.type = I;

  // заполняем матрицу поля: 1-2 строка единицами, кроме первого столбца
  for (int j = 1; j < BOARD_WIDTH; j++) {
    gameInfo.field[19][j] = 1;
    gameInfo.field[18][j] = 1;
  }

  // Поворачиваем фигуру I, убираем влево и опускаем вниз
  rotatePiece(&gameInfo);
  for (int i = 0; i < 10; i++) movePieceLeft(&gameInfo);
  for (int i = 0; i < 20; i++) movePieceDown(&gameInfo);

  ck_assert_int_eq(gameInfo.score, 300);
  ck_assert_int_eq(gameInfo.high_score, 0);
  ck_assert_int_eq(gameInfo.level, 1);

  freeGameResources(&gameInfo);
}
END_TEST

START_TEST(score_700_test_1) {
  GameInfo_t gameInfo;
  initGame(&gameInfo);
  // Размещаем фигуру I на поле
  gameInfo.currentPiece.type = I;

  // заполняем матрицу поля: 1-2-3 строка единицами, кроме первого столбца
  for (int j = 1; j < BOARD_WIDTH; j++) {
    gameInfo.field[19][j] = 1;
    gameInfo.field[18][j] = 1;
    gameInfo.field[17][j] = 1;
  }

  // Поворачиваем фигуру I, убираем влево и опускаем вниз
  rotatePiece(&gameInfo);
  for (int i = 0; i < 10; i++) movePieceLeft(&gameInfo);
  for (int i = 0; i < 20; i++) movePieceDown(&gameInfo);

  ck_assert_int_eq(gameInfo.score, 700);
  ck_assert_int_eq(gameInfo.high_score, 0);
  ck_assert_int_eq(gameInfo.level, 2);

  freeGameResources(&gameInfo);
}
END_TEST

START_TEST(score_1500_test_1) {
  GameInfo_t gameInfo;
  initGame(&gameInfo);
  // Размещаем фигуру I на поле
  gameInfo.currentPiece.type = I;

  // заполняем матрицу поля: 1-2-3-4 строка единицами, кроме первого столбца
  for (int j = 1; j < BOARD_WIDTH; j++) {
    gameInfo.field[19][j] = 1;
    gameInfo.field[18][j] = 1;
    gameInfo.field[17][j] = 1;
    gameInfo.field[16][j] = 1;
  }

  // Поворачиваем фигуру I, убираем влево и опускаем вниз
  rotatePiece(&gameInfo);
  for (int i = 0; i < 10; i++) movePieceLeft(&gameInfo);
  for (int i = 0; i < 20; i++) movePieceDown(&gameInfo);

  ck_assert_int_eq(gameInfo.score, 1500);
  ck_assert_int_eq(gameInfo.high_score, 0);
  ck_assert_int_eq(gameInfo.level, 3);

  freeGameResources(&gameInfo);
}
END_TEST

Suite *s21_initGame_suite(void) {
  TCase *tc_case = tcase_create("initGame");
  Suite *s = suite_create("initGame_test");

  tcase_add_test(tc_case, initGame_test_1);
  tcase_add_test(tc_case, initGame_test_2);
  tcase_add_test(tc_case, initGame_test_3);
  tcase_add_test(tc_case, initGame_test_4);
  tcase_add_test(tc_case, initGame_test_5);
  tcase_add_test(tc_case, initGame_test_6);
  tcase_add_test(tc_case, initGame_test_7);
  tcase_add_test(tc_case, initGame_test_8);
  tcase_add_test(tc_case, initGame_test_9);
  tcase_add_test(tc_case, initGame_test_10);

  tcase_add_test(tc_case, movePieceDown_test_1);
  tcase_add_test(tc_case, movePieceDown_and_left_test_2);
  tcase_add_test(tc_case, movePieceDown_and_right_test_3);

  tcase_add_test(tc_case, score_100_test_1);
  tcase_add_test(tc_case, score_300_test_1);
  tcase_add_test(tc_case, score_700_test_1);
  tcase_add_test(tc_case, score_1500_test_1);

  suite_add_tcase(s, tc_case);

  return s;
}
