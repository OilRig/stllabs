#ifndef Text_h
#define Text_h

#define WOW "Vau!!!"
#define SPACE " "

using namespace std;

// Перечисление с типами элементов текста
enum ElementType {
    Word,
    PunctuationMark,
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
        if (element.type == ElementType::Word && element.value.length() > 10) {
            element.value = WOW;
        }
        
        if (element.type == ElementType::Space) {
            element.value = SPACE;
        }
        
        if (
            element.type == ElementType::PunctuationMark &&
            _elements.back().type == ElementType::Space
        ) {
            _elements.pop_back();
        }
        
        _elements.push_back(element);
    }
    
    vector<string> toFixedWidth()
    {
        vector<string> output;
        
        string line = "", elementValue;
        int lineLengthLeft = 40, elementLength;
        
        for (auto it = _elements.begin(); it != _elements.end(); ++it)
        {
            elementValue = it->value;
            elementLength = (int) elementValue.length();
            
            if (
                lineLengthLeft - elementLength > 0 &&
                it != prev(_elements.end())
            ) {
                line += elementValue;
                lineLengthLeft -= elementLength;
            } else {
                output.push_back(line);
                line = "";
                lineLengthLeft = 40;
            }
        }
        
        return output;
    }
    
    Text render()
    {
        for (auto it = _elements.begin(); it != _elements.end(); ++it)
        {
            cout << it->value;
        }
        
        cout << endl << endl;
        
        return *this;
    }
};

#endif /* Text_h */
