#ifndef LAB8_SQUARE_H
#define LAB8_SQUARE_H

#include <iostream>
#include "Shape.h"

using namespace std;

class Square : public Shape
{
public:
    using Shape::Shape;

    void draw() override {
        printf("%s с координатами [%d:%d]\n", "Квадрат", posX, posY);
    }
};

#endif //LAB8_SQUARE_H
