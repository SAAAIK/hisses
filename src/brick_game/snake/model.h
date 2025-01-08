#include '../snake.h' 

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
    //std::vector<std::vector<int>> field_; 
    public:
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