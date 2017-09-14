#ifndef LAB8_TRIANGLE_H
#define LAB8_TRIANGLE_H

#include "Shape.h"

using namespace std;

class Triangle : public Shape
{
public:
    using Shape::Shape;

    void draw() override {
        printf("%s с координатами [%d:%d]\n", "Треугольник", posX, posY);
    }
};

#endif //LAB8_TRIANGLE_H
