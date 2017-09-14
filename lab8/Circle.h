#ifndef LAB8_CIRCLE_H
#define LAB8_CIRCLE_H

#include <iostream>
#include "Shape.h"

using namespace std;

class Circle : public Shape
{
public:
    using Shape::Shape;

    void draw() override {
        printf("%s с координатами [%d:%d]\n", "Круг", posX, posY);
    }
};

#endif //LAB8_CIRCLE_H
