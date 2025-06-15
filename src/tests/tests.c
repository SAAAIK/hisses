#include "tests.h"

int main(void) {
  SRunner *runner;
  runner = srunner_create(s21_initGame_suite());

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}