#include <gtest/gtest.h>
#include "../brick_game/snake.h"

TEST(field_test, constructor) {
  s21::Field myField;
  EXPECT_EQ(myField.get_height(), 20);
  EXPECT_EQ(myField.get_width(), 10);
}

int main() {
  testing::InitGoogleTest();
  if (RUN_ALL_TESTS()) {
    std::cout << "Some tests have failed" << std::endl;
  }
}