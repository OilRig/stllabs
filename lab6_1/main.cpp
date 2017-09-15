/**
 * Написать программу, которая выполняет следующие действия:
 *
 * 1) Читает содержимое текстового файла
 *
 * 2) Выделяет слова, ими считаются последовательности символов, разделенные
 * пробелами и/или знаками табуляции и/или символами новой строки
 *
 * 3) Выводит список слов присутствующих в тексте без повторений
 */

////////////////////////////////
// Фомин С. (группа 23531/21) //
////////////////////////////////

#include <iostream>
#include <fstream>
#include "WordList.h"
#include "Parser.h"

using namespace std;

string readFileToString()
{
    ifstream file;
    file.open("lorem.txt");

    string text;
    char symbol;

    while (!file.eof()) {
        file.get(symbol);
        text += symbol;
    }

    return text;
}

int main() {
    // Пункт 1
    string inputText = readFileToString();
    cout << inputText;

    // Пункт 2
    WordList words = parseText(inputText);

    // Пункт 3
    words.unique().render();
}