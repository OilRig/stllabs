/**
 * Написать программу, которая выполняет следующие действия (все операции должны
 * выполняться с помощью стандартных алгоритмов):
 *
 * 1) Заполняет вектор геометрическими фигурами. Геометрическая фигура может
 * быть треугольником, квадратом, прямоугольником или пятиугольником.
 *
 * 2) Подсчитывает общее количество вершин всех фигур содержащихся в векторе
 * (так треугольник добавляет к общему числу 3, квадрат 4 и т.д.)
 *
 * 3) Считает количество треугольников, квадратов и прямоугольников в векторе
 *
 * 4) Удаляет все пятиугольники
 *
 * 5) На основании этого вектора создает vector<Point>, который содержит
 * координаты одной из вершин (любой) каждой фигуры, т.е. первый элемент вектора
 * содержит координаты одной из вершину первой фигуры, второй элемент этого
 * вектора содержит координаты одной из вершину второй фигуры и т.д.
 *
 * 6) Изменяет вектор так, чтобы он содержал в начале все треугольники, потом
 * все квадраты, а потом пятиугольники.
 *
 * 7) Распечатывает вектор после каждого этапа работы
 *
 * [Подсказка]: кроме алгоритмов рассмотренных в этой работе можно применять все
 * средства описанные в предыдущих работах, включая алгоритмы сортировки.
 */

////////////////////////////////
// Фомин С. (группа 23531/21) //
////////////////////////////////

#include <iostream>
#include <vector>

#include "Shape.h"

using namespace std;

int randInt(int min, int max)
{
    return min + rand() % (++max - min);
}

/**
 * Заполняет вектор случайными фигурами
 */
void populateWithRandomShapes(vector<Shape> &shapes) {
    for (int i = 0; i < 10; ++i) {
        int numOfVertexes = randInt(3, 5);

        vector<Point> vertices;
        vertices.reserve(static_cast<unsigned long>(numOfVertexes - 1));

        for (int j = 0; j < numOfVertexes - 1; ++j) {
            vertices.push_back({2, 3});
        }

        Shape shape = {numOfVertexes, vertices};
        shapes.push_back(shape);
    }
}

int main()
{
    vector<Shape> shapes;

    // Пункт 1
    populateWithRandomShapes(shapes);

    for (const auto &shape : shapes)
    {
        cout << shape;
    }

    // Пункты 2 и 3
    int
        numOfTriangles = 0,
        numOfSquares = 0,
        numOfPentagons = 0,
        totalVertices = 0;

    for (const auto &shape : shapes)
    {
        int vertices = shape.numOfVertices;

        switch (vertices) {
            case 3 : numOfTriangles++; break;
            case 4 : numOfSquares++; break;
            case 5 : numOfPentagons++; break;
            default: break;
        }

        totalVertices += vertices;
    }

    printf("\nВсего вершин в фигурах: %d\n", totalVertices);
    printf(
        "Треугольников: %d\nЧетырехугольников: %d\nПятиугольников: %d\n\n",
        numOfTriangles, numOfSquares, numOfPentagons
    );

    // Пункт 4
    vector<Shape> nonPentagonShapes(shapes.size());

    auto it = copy_if (
        shapes.begin(),
        shapes.end(),
        nonPentagonShapes.begin(),
        [] (Shape shape) {
            return shape.numOfVertices != 5;
        }
    );

    nonPentagonShapes.resize(
        static_cast<unsigned long>(distance(nonPentagonShapes.begin(), it))
    );

    for (const auto &shape : nonPentagonShapes)
    {
        cout << shape;
    }

    cout << endl << endl;

    // Пункт 5
    vector<Point> everyShapesPoints;
    everyShapesPoints.reserve(shapes.size());

    for (const auto &shape : shapes)
    {
        Point point = shape.vertices.front();
        everyShapesPoints.push_back(point);
    }

    // Пункт 6
    sort(shapes.begin(), shapes.end(), [] (const Shape &lhs, const Shape &rhs) {
        return lhs.numOfVertices < rhs.numOfVertices;
    });

    for (const auto &shape : shapes)
    {
        cout << shape;
    }
}