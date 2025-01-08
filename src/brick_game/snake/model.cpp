#include "model.h"

//using namespace s21;

s21::Field::Field() : width_(FIELD_WIDTH),height_(FIELD_HEIGHT){
  board_ = std::vector<int>(
      width_, std::vector<int>(
                 height_, 0));  // двумерный вектор, FIELD_WIDTH cтрок cодержит FIELD_HEIGHT столбцов

};

s21::Field::~Field(){             
};