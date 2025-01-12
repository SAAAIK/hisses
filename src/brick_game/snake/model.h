#ifndef S21_SNAKE_MODEL_H
#define S21_SNAKE_MODEL_H

#include "../snake.h"
#include <vector>
#include <iostream>

using namespace std;
enum class Direction { Up, Down, Left, Right };

namespace s21 {  
class Snake {
    private:
    unsigned int snake_length_;
    Direction snake_direction_;
    std::vector<Position_t> snake_body_;
    public:
    Snake();
    ~Snake();
    // тело модели змейки
};
//конструктор и деструктор  

class Field {
    private:
    int width_, height_;
    vector<vector<int>> field_;
    public:
    void PrintField();
    Field();
    ~Field();
    void get_snake();
    void get_apple();
    int get_width() const noexcept;
    int get_height() const noexcept;
}; 

class Apple {
    private:
    Position_t apple_pos_;

    public:
    Apple();
    ~Apple();
};

}; // namespace s21

#endif