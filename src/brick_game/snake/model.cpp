#include "model.h"
using namespace s21;
using namespace std;
Field::Field() : width_(FIELD_WIDTH),height_(FIELD_HEIGHT){
  field_ = vector<vector<int>>(
      width_, vector<int>(
                 height_, 0));  // двумерный вектор, FIELD_WIDTH cтрок cодержит FIELD_HEIGHT столбцов

};

Field::~Field(){             
};

// height accessor
int Field::get_height() const noexcept { return height_; }

// cols accessor
int Field::get_width() const noexcept { return width_; }

void Field::PrintField(){
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

Snake::Snake() :snake_direction_=Right, snake_length_=4 {
    snake_body_= vector<Position_t>();
    snake_body_.insert(head(),{10,8});
    snake_body_.insert(head(),{10,7});
    snake_body_.insert(head(),{10,6});
    snake_body_.insert(head(),{10,5});
};

Snake::~Snake(){             
};

Snake::get_snake(){
    return snake_body_;
};