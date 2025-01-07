#include '../snake.h' 

namespace s21 {

class Snake {
    private:
    int _snake_length, _snake_direction;
    Position_t Position;

    public:
    Snake();
    ~Snake();
    // тело модели змейки
};
//конструктор и деструктор 

class Field {
    private:
    int _field_width, _field_height;
    GameInfoStruct field;

    public:
    Field();
    ~Field();
};

class Apple {
    private:
    int _apple_x, _apple_y;

    public:
    Apple();
    ~Apple();
};

} // namespace s21