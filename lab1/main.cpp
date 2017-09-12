/**
 * 1) Напишите алгоритм сортировки (любой простейший) содержимого вектора целых
 * чисел, используя оператор operator[].
 *
 * 2) Напишите алгоритм сортировки (любой простейший) содержимого вектора целых
 * чисел, используя метод at().
 *
 * 3) Напишите алгоритм сортировки (любой простейший) содержимого вектора целых
 * чисел, используя для доступа к содержимому вектора только итераторы. Для
 * работы с итераторами допустимо использовать только операторы получения
 * текущего элемента и перехода в следующему (подсказка, можно сохранять копию
 * итератора указывающего на некоторый элемент).
 *
 * 4) Прочитайте во встроенный массив С содержимое текстового файла, скопируйте
 * данные в вектор одной строкой кода (без циклов и алгоритмов STL)
 *
 * 5) Напишите программу, сохраняющую в векторе числа, полученные из
 * стандартного ввода (окончанием ввода является число 0). Удалите все элементы,
 * которые делятся на 2 (не используйте стандартные алгоритмы STL), если
 * последнее число 1. Если последнее число 2, добавьте после каждого числа
 * которое делится на 3 три единицы.
 *
 * 6) Напишите функцию void fillRandom(double* array, int size) заполняющую
 * массив случайными значениями в интервале от -1.0 до 1.0. Заполните с помощью
 * заданной функции вектора размером 5,10,25,50,100 и отсортируйте его
 * содержимое (с помощью любого разработанного ранее алгоритма модифицированного
 * для сортировки действительных чисел)
 */

////////////////////////////////
// Фомин С. (группа 23531/21) //
////////////////////////////////

#include <vector>
#include <cstdio>
#include <iostream>

#include "decorators.h"
#include "scan.h"
#include "file.h"

using namespace std;

void fillRandom(double *array, const int size) {
    for (int i = 0; i < (int) size; ++i) {
        array[i] = 1 - 2.0 * rand() / RAND_MAX;
    }
}

int main(int argc, const char * argv[]) {
    // Пункты 1:3
    vector<int> intVector = {5, 3, 6, 1, 3, 4, 7, 11, 6, 4, 8};
    
    IndexVectorDecorator<int> indexBasedInt(intVector);
    AtVectorDecorator<int> atBasedInt(intVector);
    IteratorVectorDecorator<int> iteratorBasedInt(intVector);
    
    IndexVectorDecorator<double> indexBasedDouble({5.73, 1.39, 8.26, 3.14});
    
    vector<VectorDecorator<int> *> vectorDecorators = {
        &indexBasedInt, &atBasedInt, &iteratorBasedInt
    };
    
    for (int i = 0; i < vectorDecorators.size(); ++i) {
        vectorDecorators[i]->output();
        vectorDecorators[i]->sort();
        vectorDecorators[i]->output();
        
        cout << endl;
    }
    
    // Пункт 4
    readFileIntoVector();
    
    // Пункт 5
    scanIntsIntoVector();
    
    // Пункт 6
    vector<int> lengths = {5, 10, 25, 50, 100};
    
    for (int i = 0; i < lengths.size(); ++i) {
        vector<double> tempVector(lengths[i]);
        fillRandom(&tempVector[0], lengths[i]);
        IndexVectorDecorator<double> vec(tempVector);
        
        vec.output();
        vec.sort();
        vec.output();
        
        cout << endl;
    }
}
