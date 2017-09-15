#ifndef Text_h
#define Text_h

#define CANONICAL_SPACE " "

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

    void render()
    {
        for (auto &_element : _elements) {
            cout << _element << CANONICAL_SPACE;
        }

        cout << endl << endl;
    }

    WordList unique()
    {
        auto unique = _elements;

        sort(unique.begin(), unique.end());
        unique.erase(
            std::unique(unique.begin(), unique.end()),
            unique.end()
        );

        return WordList(unique);
    }
};

#endif /* Text_h */
