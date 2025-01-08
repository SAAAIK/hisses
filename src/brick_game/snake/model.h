#ifndef S21_SNAKE_MODEL_H
#define S21_SNAKE_MODEL_H

#include "../snake.h"
#include <vector>


namespace s21 {

/*class Snake {
    private:
    int snake_length_, snake_direction_;
    Position_t Position_t;
    public:
    Snake();
    ~Snake();
    // тело модели змейки
};*/
//конструктор и деструктор  

class Field {
    private:
    int field_width_, field_height_;
    std::vector<std::vector<int>> field_; 
    public:
    PrintField(field_);
    Field();
    ~Field(); 
}; 

class Apple {
    private:
    int apple_x_, apple_y_;

    public:
    Apple();
    ~Apple();
};

}; // namespace s21

#endif