#ifndef LAB7_FUNCTOR_H
#define LAB7_FUNCTOR_H

#include <iostream>

using namespace std;

class Functor
{
private:
    int maximum = 0,
        minimum = 0,
        positives = 0,
        negatives = 0,
        sumOfOdd = 0,
        sumOfEven = 0,
        firstElement = 0,
        allAmount = 0;

    double
        average = 0;
    bool
        sameEnds = false;
public:
    Functor() = default;

    void operator () (int number) {
        if (allAmount == 0) {
            firstElement = minimum = maximum = number;
        }

        if (number > maximum) {
            maximum = number;
        } else if (number < minimum) {
            minimum = number;
        }

        average = (allAmount * average + number) / ++allAmount;

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

    friend ostream & operator << (ostream &os, Functor &sf) {
        os << "Статистика:"
           << "\nМинимальное число: " << sf.minimum
           << "\nМаксимальное число: " << sf.maximum
           << "\nСреднее число: " << sf.average
           << "\nКоличество положительных чисел: " << sf.positives
           << "\nКоличество отрицательных чисел: " << sf.negatives
           << "\nСумма нечетных элементов: " << sf.sumOfOdd
           << "\nСумма четных элементов: " << sf.sumOfEven
           << "\nКонцы последовательности"
           << (sf.sameEnds ? " совпадают" : " различаются") << endl << endl;

        return os;
    }
};

#endif //LAB7_FUNCTOR_H