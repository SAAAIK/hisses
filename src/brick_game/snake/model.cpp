#include "model.h"
//using namespace s21;
using namespace std;
s21::Field::Field() : width_(FIELD_WIDTH),height_(FIELD_HEIGHT){
  field_ = vector<vector<int>>(
      width_, vector<int>(
                 height_));  // двумерный вектор, FIELD_WIDTH cтрок cодержит FIELD_HEIGHT столбцов

};

s21::Field::~Field(){             
};

void s21::Field::PrintField(){
    for (int i = 0; i < height_; i++) {
        for (int j = 0; j < width_; j++) {
            if (field_[j][i] == 1) {
                cout << "x ";
            } else {
                cout << "- ";
            }
        }
        cout << endl;
    }
};