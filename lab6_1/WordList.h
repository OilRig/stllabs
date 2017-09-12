#ifndef Text_h
#define Text_h

#define SPACE " "

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// Класс для хранения списка слов
class WordList {
private:
    vector<string> _elements;
public:
    void addElement(const string &element)
    {
        _elements.push_back(element);
    }

    explicit WordList(const vector<string> &_elements = {})
    {
        this->_elements = _elements;
    }

    WordList render()
    {
        for (auto &_element : _elements) {
            cout << _element << SPACE;
        }

        cout << endl << endl;

        return *this;
    }

    WordList unique()
    {
        auto unique = _elements;

        /**
         * std::unique() сдвигает повторяющиеся соседние элементы в конец
         * вектора, возаращая итератор на начало области вектора, где хранятся
         * дубли, поэтому сначала я сортирую вектор
         */
        sort(unique.begin(), unique.end());

        /**
         * И только потом стираю, с итератора возвращенного unique и до конца
         */
        unique.erase(
            std::unique(unique.begin(), unique.end()),
            unique.end()
        );

        return WordList(unique);
    }
};

#endif /* Text_h */
