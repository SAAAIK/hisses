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
    int width_, height_;
    vector<vector<int>> field_;

    public:
    void PrintField(field_);
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