#ifndef LAB6_2_SHAPE_H
#define LAB6_2_SHAPE_H

#include <vector>
#include <iostream>

using namespace std;

struct Point
{
    int x;
    int y;
};

struct Shape
{
    int numOfVertices;
    vector<Point> vertices;
    friend ostream& operator << (ostream &os, const Shape &shape)
    {
        os << " Вершин в фигуре: " << shape.numOfVertices << endl;

        for (auto vertex : shape.vertices) {
            os << "[x:" << vertex.x << " y:" << vertex.y << "]";
        }
        os << endl;

        return os;
    }
};

#endif //LAB6_2_SHAPE_H