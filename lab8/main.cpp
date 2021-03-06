/**
 * 0) Разработать программу, которая используя только стандартные алгоритмы и
 * функторы, умножает каждый элемент списка чисел с плавающей точкой на число π
 *
 * Разработать программу, которая:
 * 1) Реализует иерархию геометрических фигур состоящую из:
 *
 * Класс Shape.
 * - Содержит информацию о положении центра фигуры (координаты x и y).
 * - Содердит метод IsMoreLeft, позволяющий определить расположена ли данная
 * фигура левее (определяется по положению центра) чем фигура переданная в
 * качестве аргумента
 * - Содердит метод IsUpper, позволяющий определить расположена ли данная фигура
 * выше (определяется по положению центра) чем фигура переданная в качестве
 * аргумента
 * - Определяет чисто виртаульную функцию рисования Draw (каждая фигура в
 * реализации этой функци должна выводить на стандартный вывод свое название и
 * положение цента)
 *
 * Класс Circle производный от класса Shape
 * - Реализует Draw
 *
 * Класс Triangle производный от класса Shape
 * - Реализует Draw
 *
 * Класс Square производный от класса Shape
 * - Реализует Draw
 *
 * 2) Содержит список list<Shape*>, заполенный указателями на различные фигуры
 *
 * 3) С помощью стандартных алгоритмов и адаптеров выводит (Draw) все фигуры
 *
 * 4) С помощью стандартных алгоритмов и адаптеров сортирует список по положению
 * центра слева-направо и выводит фигуры
 *
 * 5) С помощью стандартных алгоритмов и адаптеров сортирует список по положению
 * центра справа-налево и выводит фигуры
 *
 * 6) С помощью стандартных алгоритмов и адаптеров сортирует список по положению
 * центра сверху-вниз и выводит фигуры
 *
 * 7) С помощью стандартных алгоритмов и адаптеров сортирует список по положению
 * центра снизу-вверх и выводит фигуры
 */

////////////////////////////////
// Фомин С. (группа 23531/21) //
////////////////////////////////

#include <iostream>
#include <cmath>
#include <list>

#include "Shape.h"
#include "Triangle.h"
#include "Square.h"
#include "Circle.h"

using namespace std;

void drawAllShapes(const list<Shape*> &shapes)
{
    cout << endl;
    for_each(shapes.begin(), shapes.end(), [](Shape* shape) {
        shape->draw();
    });
}

int main() {
    // Пункт 0
    list<double> listOfDoubles = {
        10.0, 5.0, 2.34, 5.232, 2.0
    };

    transform(
        listOfDoubles.begin(),
        listOfDoubles.end(),
        listOfDoubles.begin(),
        bind1st(multiplies<double>(), M_PI)
    );

    for (auto num : listOfDoubles) {
        cout << num << " ";
    }

    cout << endl;

    // Пункты 1:2
    Triangle
        tri1(11,12),
        tri2(02,04);

    Square
        sqa1(12,35),
        sqa2(56,24);

    Circle
        cir1(56,49),
        cir2(33,92);

    list<Shape*> shapes = {
        &tri1, &tri2, &sqa1, &sqa2, &cir1, &cir2
    };

    // Пункт 3
    drawAllShapes(shapes);

    // Пункт 4
    shapes.sort([](Shape* lhs, Shape* rhs) {
        return lhs->isMoreLeft(*rhs);
    });

    drawAllShapes(shapes);

    // Пункт 5
    shapes.sort([](Shape* lhs, Shape* rhs) {
        return !lhs->isMoreLeft(*rhs);
    });

    drawAllShapes(shapes);

    // Пункт 6
    shapes.sort([](Shape* lhs, Shape* rhs) {
        return lhs->isUpper(*rhs);
    });

    drawAllShapes(shapes);

    // Пункт 7
    shapes.sort([](Shape* lhs, Shape* rhs) {
        return !lhs->isUpper(*rhs);
    });

    drawAllShapes(shapes);
}