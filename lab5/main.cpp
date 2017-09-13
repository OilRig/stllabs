/**
 * Написать программа, которая выполняет следующие действия:
 *
 * 1) Заполняет vector<DataStruct> структурами DataStruct, при этом key1 и key2,
 * генерируются случайным образом в диапазоне от -5 до 5, str заполняется из
 * таблицы (таблица содержит 10 произвольных строк, индекс строки генерируется
 * случайным образом)
 *
 * DataStruct определена следующим образом:
 * typedef struct
 * {
 *     int     key1;
 *     int     key2;
 *     string  str;
 * } DataStruct;
 *
 * 2) Выводит полученный вектор на печать
 *
 * 3) Сортирует вектор следующим образом:
 *  - По возрастанию key1
 *  - Если key1 одинаковые, то по возрастанию key2
 *  - Если key1 и key2 одинаковые, то по возрастанию длинны строки str
 *
 * 4) Выводит полученный вектор на печать
 */

////////////////////////////////
// Фомин С. (группа 23531/21) //
////////////////////////////////

#include <iostream>
#include <vector>

using namespace std;

string strings[] = {
    "Lorem ipsum dolor",
    "sit amet consectetur",
    "adipisicing ",
    "elit Perspiciatis iusto",
    "sapiente quidem",
    "aliquam",
    "id",
    "dolorem asperiores",
    "sunt Eum sint qui"
};

struct DataStruct
{
    int key1;
    int key2;
    string str;
};

void printTable(vector<DataStruct> &vectorOfDS, const string &heading)
{
    printf("%20s\n%4s|%4s|str\n", heading.c_str(), "key1", "key2");

    for_each(vectorOfDS.begin(), vectorOfDS.end(), [] (DataStruct ds) {
        printf ("%4i|%4i|%s\n", ds.key1, ds.key2, ds.str.c_str());
    });

    printf("\n");
}

int randomIntBetween(int min, int max)
{
    return min + rand() % (++max - min);
}

int main()
{
    vector<DataStruct> dsVector(5);

    // Пункт 1
    for_each(dsVector.begin(), dsVector.end(), [](DataStruct &ds)
    {
        ds = {
            randomIntBetween(-5, 5),
            randomIntBetween(-5, 5),
            strings[randomIntBetween(0, 9)]
        };
    });

    // Пункт 2
    printTable(dsVector, "Вектор заполнен:");

    // Пункт 3
    sort(dsVector.begin(), dsVector.end(), [](
        const DataStruct &lhs, const DataStruct &rhs)
    {
        int
            lkey1 = lhs.key1, lkey2 = lhs.key2, lstr = (int) lhs.str.size(),
            rkey1 = rhs.key1, rkey2 = rhs.key2, rstr = (int) rhs.str.size();

        if (lkey1 < rkey1) {
            return true;
        }

        if (lkey1 == rkey1 && lkey2 < rkey2) {
            return true;
        }

        if (lkey1 == rkey1 && lkey2 == rkey2 && lstr < rstr) {
            return true;
        }

        return false;
    });

    // Пункт 4
    printTable(dsVector, "Вектор отсортирован:");
}

