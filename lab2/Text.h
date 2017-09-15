#ifndef Text_h
#define Text_h

#include <iostream>

#define WOW "Vau!!!"
#define CANONIC_SPACE " "

using namespace std;

// Перечисление с типами элементов текста
enum ElementType {
    Word,
    Punctuation,
    Space
};

// Структура элемента текста
struct TextElement {
    ElementType type;
    string value;
};

// Класс для хранения элементов текста
class Text {
private:
    vector<TextElement> _elements;
public:
    void addElement(TextElement element)
    {
        if (element.type == Word && element.value.length() > 10) {
            element.value = WOW;
        }
        
        if (element.type == Space) {
            element.value = CANONIC_SPACE;
        }
        
        if (element.type == Punctuation && _elements.back().type == Space) {
            _elements.pop_back();
        }

        if (element.value.length() > 0) {
            _elements.push_back(element);
        }
    }
    
    vector<string> toFixedWidth()
    {
        vector<string> output;
        
        string line, elementValue;
        int lengthLeft = 40, elementLength;
        
        for (auto it = _elements.begin(); it != _elements.end(); ++it)
        {
            elementValue = it->value;
            elementLength = (int) elementValue.length();
            
            if (lengthLeft - elementLength > 0 && it != prev(_elements.end())) {
                line += elementValue;
                lengthLeft -= elementLength;
            } else {
                output.push_back(line);
                lengthLeft = 40;
                line = "";
            }
        }
        
        return output;
    }

    void render()
    {
        for (auto it = _elements.begin(); it != _elements.end(); ++it)
        {
            cout << it->value;
        }
        
        cout << endl << endl;
    }
};

#endif /* Text_h */