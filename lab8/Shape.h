#ifndef LAB8_SHAPE_H
#define LAB8_SHAPE_H

class Shape
{
protected:
    int posX,
        posY;
public:
    Shape(int posX, int posY) : posX(posX), posY(posY) {}

    bool isMoreLeft(const Shape& ref) {
        return posX < ref.posX;
    }

    bool isUpper(const Shape& ref) {
        return posY < ref.posY;
    };

    virtual void draw() = 0;
};

#endif //LAB8_SHAPE_H
