#ifndef LAB7_FUNCTOR_H
#define LAB7_FUNCTOR_H

#include <iostream>

using namespace std;

class StatFunctor
{
private:
    int maximum = 0,
        minimum = 0,
        positives = 0,
        negatives = 0,
        sumOfOdd = 0,
        sumOfEven = 0,
        firstElement = 0,
        size = 0;

    double
        average = 0;
    bool
        sameEnds = false;
public:
    StatFunctor() = default;

    void operator () (int number) {
        if (size == 0) {
            firstElement = minimum = maximum = number;
        }

        ++size;

        if (number > maximum) {
            maximum = number;
        } else if (number < minimum) {
            minimum = number;
        }

        average = (size * average + number) / size;

        if (number > 0) {
            ++positives;
        } else if (number < 0) {
            ++negatives;
        }

        if (number % 2 != 0) {
            sumOfOdd += number;
        } else {
            sumOfEven += number;
        }

        sameEnds = (firstElement == number);
    }

    StatFunctor& render() {
        cout
            << "\nСтатистика:"
            << "\nМинимальное число: " << minimum
            << "\nМаксимальное число: " << maximum
            << "\nСреднее число: " << average
            << "\nКоличество положительных чисел: " << positives
            << "\nКоличество отрицательных чисел: " << negatives
            << "\nСумма нечетных элементов: " << sumOfOdd
            << "\nСумма четных элементов: " << sumOfEven
            << "\nКонцы последовательности"
            << (sameEnds ? " совпадают" : " различаются") << "\n\n";

        return *this;
    }
};

#endif //LAB7_FUNCTOR_H