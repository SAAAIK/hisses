#include "model.h"

//using namespace s21;

s21::Field::Field() : width_(FIELD_WIDTH),height_(FIELD_HEIGHT){
  board_ = std::vector<int>(
      width_, std::vector<int>(
                 height_, 0));  // двумерный вектор, FIELD_WIDTH cтрок cодержит FIELD_HEIGHT столбцов

};

s21::Field::~Field(){             
};

s21::Field::PrintField(field_){
    for (int i = 0; i < height_; i++) {
        for (int j = 0; j < width_; j++) {
            if (board_[j][i] == 1) {
                std::cout << "x ";
            } else {
                std::cout << "- ";
            }
        }
        std::cout << std::endl;
    }
};